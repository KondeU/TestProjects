#include "../inc/DumpGenerator.h"

#ifdef _WIN32

#include <cstdio>
#include <Windows.h>
#include <DbgHelp.h>

BOOL CatchAllExceptDump();
LONG GenerateMiniDump(PEXCEPTION_POINTERS pExceptionPointers);
LONG CrashFinishWork(LONG next);
LONG WINAPI ExceptionHandler(LPEXCEPTION_POINTERS lpExceptionPointers);

BOOL CatchAllExceptDump()
{
    SetUnhandledExceptionFilter(ExceptionHandler);

    // UCRT hook code
    #ifdef _M_IX86
    // Code for x86:
    // 33 C0     xor eax,eax
    // C2 04 00  ret 4
    unsigned char szExecute[] = { 0x33, 0xC0, 0xC2, 0x04, 0x00 };
    #elif _M_X64
    // Code for x64:
    // 33 C0     xor eax,eax
    // C3        ret
    unsigned char szExecute[] = { 0x33, 0xC0, 0xC3 };
    #else
    // Only works for x86 and x64
    return FALSE;
    #endif

    HMODULE hKernel32 = LoadLibrary(TEXT("kernel32.dll"));
    if (hKernel32 == NULL) {
        return FALSE;
    }

    // The function is ANSI version
    void* addr = GetProcAddress(hKernel32, "SetUnhandledExceptionFilter");
    if (addr) {
        DWORD dwOldFlag = 0;
        DWORD dwTempFlag = 0;
        SIZE_T bytesWritten = 0;

        BOOL suc = FALSE;
        suc = VirtualProtect(addr, sizeof(szExecute),
            PAGE_EXECUTE_READWRITE, &dwOldFlag);
        suc = WriteProcessMemory(GetCurrentProcess(),
            addr, szExecute, sizeof(szExecute), &bytesWritten);
        suc = VirtualProtect(addr, sizeof(szExecute), dwOldFlag, &dwTempFlag);
        return TRUE;
    }
    return FALSE;
}

LONG WINAPI ExceptionHandler(LPEXCEPTION_POINTERS lpExceptionPointers)
{
    if (IsDebuggerPresent()) {
        return EXCEPTION_CONTINUE_SEARCH;
    }
    return CrashFinishWork(GenerateMiniDump(lpExceptionPointers));
}

LONG GenerateMiniDump(PEXCEPTION_POINTERS pExceptionPointers)
{
    HMODULE hDbgHelp = LoadLibrary(TEXT("DbgHelp.dll"));
    if (hDbgHelp == NULL) {
        return EXCEPTION_CONTINUE_SEARCH;
    }

    using MiniDumpWriteDumpPtr = BOOL(WINAPI*)(
        HANDLE, DWORD, HANDLE, MINIDUMP_TYPE,
        PMINIDUMP_EXCEPTION_INFORMATION,
        PMINIDUMP_USER_STREAM_INFORMATION,
        PMINIDUMP_CALLBACK_INFORMATION);
    MiniDumpWriteDumpPtr pfnMiniDumpWriteDump =
        reinterpret_cast<MiniDumpWriteDumpPtr>(
            GetProcAddress(hDbgHelp, "MiniDumpWriteDump"));
    if (pfnMiniDumpWriteDump == NULL) {
        FreeLibrary(hDbgHelp);
        return EXCEPTION_CONTINUE_SEARCH;
    }

    TCHAR szPrefix[] = TEXT("crash");
    TCHAR szFileName[MAX_PATH] = { 0 };

    #ifdef UNICODE
    #define tprintf swprintf_s
    #else
    #define tprintf sprintf_s
    #endif

    SYSTEMTIME stComputerLocalTime;
    GetLocalTime(&stComputerLocalTime);
    tprintf(szFileName, TEXT("%s-%04d%02d%02d-%02d%02d%02d.dmp"), szPrefix,
        stComputerLocalTime.wYear,   stComputerLocalTime.wMonth,
        stComputerLocalTime.wDay,    stComputerLocalTime.wHour,
        stComputerLocalTime.wMinute, stComputerLocalTime.wSecond);

    HANDLE hDumpFile = CreateFile(szFileName, GENERIC_WRITE, FILE_SHARE_READ,
        NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hDumpFile == INVALID_HANDLE_VALUE) {
        FreeLibrary(hDbgHelp);
        return EXCEPTION_CONTINUE_SEARCH;
    }

    MINIDUMP_EXCEPTION_INFORMATION mdei;
    mdei.ThreadId = GetCurrentThreadId();
    mdei.ExceptionPointers = pExceptionPointers;
    mdei.ClientPointers = FALSE;
    pfnMiniDumpWriteDump(
        GetCurrentProcess(),
        GetCurrentProcessId(),
        hDumpFile, MiniDumpWithFullMemory,
        (pExceptionPointers ? &mdei : NULL), NULL, NULL);

    CloseHandle(hDumpFile);
    FreeLibrary(hDbgHelp);
    return EXCEPTION_EXECUTE_HANDLER;
}

LONG CrashFinishWork(LONG next)
{
    MessageBox(NULL, TEXT("Application crash! Dump file generated."),
        TEXT("DFX"), MB_ICONERROR);
    return next;
}

DumpGenerator::DumpGenerator()
{
    if (CatchAllExceptDump() != TRUE) {
        MessageBox(NULL, TEXT("Dump catcher setup error!"),
            TEXT("DFX"), MB_ICONWARNING);
    }
}

DumpGenerator::~DumpGenerator()
{
}

#else

DumpGenerator::DumpGenerator()
{
}

DumpGenerator::~DumpGenerator()
{
}

#endif

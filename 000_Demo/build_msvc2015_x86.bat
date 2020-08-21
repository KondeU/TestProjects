PATH=%~dp0..\Tools\CMake\cmake-3.18.1-win32-x86\bin;%PATH%

set BUILD_TYPE=RelWithDebInfo
set BUILD_COMPILE=Visual Studio 14 2015

mkdir build
cd build
cmake .. -G "%BUILD_COMPILE%"
cmake --build . --config %BUILD_TYPE% -j 8
cd ..

mkdir output
cd output
copy ..\build\%BUILD_TYPE%\*.exe . /Y
copy ..\setting.txt . /Y
cd ..

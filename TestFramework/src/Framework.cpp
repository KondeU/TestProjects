#include "../inc/Framework.h"
#include "../inc/DumpGenerator.h"
#include <iostream>

void Framework::Run()
{
    for (const auto& processor : processors) {
        bool success = false;
        std::cout << "Running processor: " << processor.first << std::endl;

        success = processor.second->Init();
        std::cout << "[Init    : " << (success ? "PASS" : "FAIL") << "]" << std::endl;
        
        success = processor.second->Process();
        std::cout << "[Process : " << (success ? "PASS" : "FAIL") << "]" << std::endl;
        
        success = processor.second->Deinit();
        std::cout << "[Deinit  : " << (success ? "PASS" : "FAIL") << "]" << std::endl;
    }
}

void Framework::AddProcessor(const std::string& name, Processor* processor)
{
    processors.emplace_back(name, processor);
}

namespace {
    DumpGenerator g_dumpGenerator;
}

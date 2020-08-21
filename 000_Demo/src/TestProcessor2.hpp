#pragma once

#include "../../TestFramework/inc/Processor.h"

PROCESSOR(TestProcessor2)

// TODO: 测试过程中使用的 头文件
// eg.标准输出头
#include <iostream>

namespace {
    // TODO: 测试过程中使用的 变量、函数 等
}

bool TestProcessor2::Init()
{
    // TODO: 测试初始化
    return true;
}

bool TestProcessor2::Deinit()
{
    // TODO: 测试终止化
    int* p = 0; // 测试示例：
    *p = 0;     // 用来制造Crash触发Dump文件生成
    return true;
}

bool TestProcessor2::Process()
{
    // TODO: 测试过程
    // eg.输出setting配置文件中的一个字段
    std::cout << GetSetting()->GetString("General", "Author") << std::endl;
    return true;
}

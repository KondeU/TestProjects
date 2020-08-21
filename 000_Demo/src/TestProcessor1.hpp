#pragma once

#include "../../TestFramework/inc/Processor.h"

// TODO: 测试过程中使用的 头文件
// eg.标准输出头
#include <iostream>

class TestProcessor1 : public Processor {
public:
    bool Init() override
    {
        // TODO: 测试初始化
        return true;
    }

    bool Deinit() override
    {
        // TODO: 测试终止化
        return true;
    }

    bool Process() override
    {
        // TODO: 测试过程
        // eg.输出setting配置文件中的一个字段
        std::cout << GetSetting()->GetString("General", "Case") << std::endl;
        return true;
    }

private:
    // TODO: 测试过程中使用的 变量、函数 等
};

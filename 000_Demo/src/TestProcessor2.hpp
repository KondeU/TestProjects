#pragma once

#include "../../TestFramework/inc/Processor.h"

PROCESSOR(TestProcessor2)

// TODO: ���Թ�����ʹ�õ� ͷ�ļ�
// eg.��׼���ͷ
#include <iostream>

namespace {
    // TODO: ���Թ�����ʹ�õ� ���������� ��
}

bool TestProcessor2::Init()
{
    // TODO: ���Գ�ʼ��
    return true;
}

bool TestProcessor2::Deinit()
{
    // TODO: ������ֹ��
    int* p = 0; // ����ʾ����
    *p = 0;     // ��������Crash����Dump�ļ�����
    return true;
}

bool TestProcessor2::Process()
{
    // TODO: ���Թ���
    // eg.���setting�����ļ��е�һ���ֶ�
    std::cout << GetSetting()->GetString("General", "Author") << std::endl;
    return true;
}

#pragma once

#include "../../TestFramework/inc/Processor.h"

// TODO: ���Թ�����ʹ�õ� ͷ�ļ�
// eg.��׼���ͷ
#include <iostream>

class TestProcessor1 : public Processor {
public:
    bool Init() override
    {
        // TODO: ���Գ�ʼ��
        return true;
    }

    bool Deinit() override
    {
        // TODO: ������ֹ��
        return true;
    }

    bool Process() override
    {
        // TODO: ���Թ���
        // eg.���setting�����ļ��е�һ���ֶ�
        std::cout << GetSetting()->GetString("General", "Case") << std::endl;
        return true;
    }

private:
    // TODO: ���Թ�����ʹ�õ� ���������� ��
};

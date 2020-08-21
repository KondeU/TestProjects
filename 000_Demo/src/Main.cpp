#include "../../TestFramework/inc/Framework.h"

#include "TestProcessor1.hpp"
#include "TestProcessor2.hpp"

int main()
{
    Framework framework;

    TestProcessor1 testProcessor1;
    TestProcessor2 testProcessor2;

    framework.AddProcessor("TestProcessor1", &testProcessor1);
    framework.AddProcessor("TestProcessor2", &testProcessor2);

    framework.Run();

    system("pause");
    return 0;
}
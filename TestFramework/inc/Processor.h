#ifndef _Processor_h_
#define _Processor_h_

#include "Setting.h"

class Processor {
public:
    Processor() = default;
    virtual ~Processor() = default;

    virtual bool Init() = 0;
    virtual bool Deinit() = 0;
    virtual bool Process() = 0;

protected:
    Setting* GetSetting();
};

#define PROCESSOR(CustomProcessor)         \
class CustomProcessor : public Processor { \
public:                                    \
    bool Init() override;                  \
    bool Deinit() override;                \
    bool Process() override;               \
};

#endif

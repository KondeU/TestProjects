#ifndef _Framework_h_
#define _Framework_h_

#include <string>
#include <vector>
#include <utility>
#include "Processor.h"

class Framework final {
public:
    void Run();
    void AddProcessor(const std::string& name, Processor* processor);

private:
    std::vector<std::pair<std::string, Processor*>> processors;
};

#endif

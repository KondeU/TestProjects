#include "../inc/Setting.h"
#include "../3rd/CConfig/source/CConfig.h"
#include <iostream>

namespace {
    CConfig config("setting.txt");
}

Setting Setting::setting;

Setting* Setting::GetSetting()
{
    return &setting;
}

int Setting::GetInteger(const std::string& group, const std::string& key, int dv)
{
    return config.GetInteger(group, key, dv);
}

bool Setting::GetBoolean(const std::string& group, const std::string& key, bool dv)
{
    return config.GetBoolean(group, key, dv);
}

double Setting::GetDouble(const std::string& group, const std::string& key, double dv)
{
    return config.GetDouble(group, key, dv);
}

std::string Setting::GetString(const std::string& group, const std::string& key, std::string dv)
{
    return config.GetString(group, key, dv);
}

Setting::Setting()
{
    unsigned int lines = 0;
    bool success = config.LoadFile(&lines);
    config.SetAutoSave(false);

    std::cout
        << "Load config file: "
        << (success ? "Success. " : "Failed! ")
        << "Read lines: " << lines << std::endl;
    std::cout << "---------------" << std::endl;
}

Setting::~Setting()
{
}

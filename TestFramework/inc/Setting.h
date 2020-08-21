#ifndef _Setting_h_
#define _Setting_h_

#include <string>

class Setting final {
public:
    static Setting* GetSetting();

    int GetInteger(const std::string& group, const std::string& key, int dv = 0);
    bool GetBoolean(const std::string& group, const std::string& key, bool dv = false);
    double GetDouble(const std::string& group, const std::string& key, double dv = 0.0);
    std::string GetString(const std::string& group, const std::string& key, std::string dv = "");

private:
    Setting();
    ~Setting();
    static Setting setting;
};

#endif

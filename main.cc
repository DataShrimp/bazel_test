#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

int main()
{
    std::string filename = "test.json";
    // 尝试打开JSON文件
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Failed to open file " << filename << std::endl;
        return 1;
    }

    try {
        // 尝试解析JSON字符串
        json j = json::parse(file);

        // 如果解析成功，则验证JSON格式是否正确
        if (j.is_object()) {
            std::cout << "JSON format is valid." << std::endl;
        } else {
            std::cout << "JSON format is not valid." << std::endl;
        }
    } catch (json::parse_error& e) {
        // 如果解析失败，则输出错误信息
        std::cout << "JSON parse error: " << e.what() << std::endl;
    }

    return 0;
}
#pragma once
#include <string>

namespace File {
    std::string ReadFile(const std::string &filePath);
    void WriteFile(const std::string &dataToWrite, const std::string &filePath);
    void DeleteFile(const std::string &filePath);

    void LogFile(std::string message, bool date);
};

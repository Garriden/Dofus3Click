#pragma once
#include <iostream>
#include <filesystem>
#include <string>

class File {
    public:
        File() = delete; // Prevent instantiation
        ~File() = delete;

        static std::string ReadFile(const std::string &filePath);
        static void WriteFile(const std::string &dataToWrite, const std::string &filePath);
        static void DeleteFile(const std::string &filePath);

        static void LogFile(std::string message);
};

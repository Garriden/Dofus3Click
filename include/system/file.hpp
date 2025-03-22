#pragma once
#include <string>
#include <vector>

namespace File {
    std::string ReadFile(const std::string &filePath);
    void WriteFile(const std::string &dataToWrite, const std::string &filePath);
    void DeleteLocalFile(const std::string &filePath);

    void LogFile(std::string message, bool date);

    // Get all the Coordenates inside a .csv, given a file name.
    std::vector<std::vector<std::pair<int, int> > > ReadFileAndBuildMap(const std::string &filePath);
};

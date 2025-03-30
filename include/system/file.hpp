#pragma once
#include <string>
#include <vector>

#define INPUT_PATTERN_CHARACTER             (696969)
#define INPUT_PATTERN_ESC                   (696942)
#define INPUT_PATTERN_CTRL                  (696924)
#define INPUT_PATTERN_AVPAG                 (696930)
#define INPUT_PATTERN_AVPAG_UP              (696931)
#define INPUT_PATTERN_AVPAG_DOWN            (696932)

namespace File {
    std::string ReadFile(const std::string &filePath);
    void WriteFile(const std::string &dataToWrite, const std::string &filePath);
    void DeleteLocalFile(const std::string &filePath);

    void LogFile(std::string message, bool date);

    // Get all the Coordenates inside a .csv, given a file name.
    std::vector<std::vector<std::pair<int, int> > > ReadFileAndBuildMap(const std::string &filePath);
};

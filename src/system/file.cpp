#include "system/file.hpp"
//#include "Utils.h"
#include "system/actualTime.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

std::vector<std::vector<std::pair<int, int> > > File::ReadFileAndBuildMap(const std::string &filePath)
{
    // Find file.
    std::filesystem::path path{ filePath };

    std::vector<std::vector<std::pair<int, int> > > ret;

    std::vector<std::pair<int, int> > row;
    std::pair<int, int> coord;
    std::string word;

    // Read file.
    std::error_code error;
    if(std::filesystem::exists(path, error)) {
        std::ifstream ifs(path);
        std::string line;
        
        while(std::getline(ifs, line)) { // Read line by line
            row.clear();

            std::stringstream str(line);

            while(std::getline(str, word, ',')) {
                coord.first = stoi(word);
                std::getline(str, word, ',');
                coord.second = stoi(word);
                row.push_back(coord);
                std::cout <<  "coord.first: " << coord.first  << "  coord.second: " << coord.second << std::endl;
            }
            ret.push_back(row);
        }
        ifs.close();
    } else {
        std::cout << "File doesnt exist: " << filePath << " / " << error.message() << std::endl;
        std::cout << "Creating new file..." << std::endl;
        std::filesystem::create_directories(path);
    }

    return ret;
}

std::string File::ReadFile(const std::string &filePath)
{
    // Find file.
    std::filesystem::path path{ filePath };

    std::string ret = "";
    // Read file.
    std::error_code error;
    if(std::filesystem::exists(path, error)) {
        std::ifstream ifs(path);
        std::string line;
        
        while(std::getline(ifs, line)) { // Read line by line
            ret += line;
        }
        ifs.close();
    } else {
        std::cout << "File doesnt exist: " << filePath << " / " << error.message() << std::endl;
        std::cout << "Creating new file..." << std::endl;
        std::filesystem::create_directories(path);
    }

    return ret;
}

void File::WriteFile(const std::string &dataToWrite, const std::string &filePath)
{
    // Find file.
    std::filesystem::path path{ filePath };

    // Write it into file.
    std::ofstream ofs(path);
    ofs << dataToWrite;
    ofs.close();
}

void File::DeleteFile(const std::string &filePath)
{
    std::filesystem::path path{ filePath };

    std::error_code error;
    if(!std::filesystem::remove(path, error)) {
        std::cout << "! Could not remove the file: " << filePath << ". Error: " << error.message() << std::endl;
    }
}

void File::LogFile(std::string message, bool date)
{
    std::cout << " message: " <<  message << std::endl;

    std::string s = std::to_string(GetDay())   + 
                    std::to_string(GetMonth()) + 
                    std::to_string(GetYear())  + 
                    ".txt";

    std::string base = "";
    if(date) {
        base = "[" +
            std::to_string(GetHour()) + ":" +
            std::to_string(GetMin())  + ":" +
            std::to_string(GetSec()) + 
            "] ";
    }

    std::string read = File::ReadFile(s);

    File::WriteFile(base + read + message, s);
}
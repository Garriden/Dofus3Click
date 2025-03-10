#include <fstream>
#include "system/file.hpp"
//#include "Utils.h"
#include "system/actualTime.hpp"

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
        
        while (std::getline(ifs, line)) { // Read line by line
            ret += line;
        }
        ifs.close();
    } else {
        std::cout << "! Could not open the file: " << filePath << ". Error: " << error.message() << std::endl;
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

void File::LogFile(std::string message)
{
    std::string s = std::to_string(GetDay())   + 
                    std::to_string(GetMonth()) + 
                    std::to_string(GetYear())  + 
                    ".txt";
    std::string base = "["						 +
                        std::to_string(GetHour()) + ":" +
                        std::to_string(GetMin())  + ":" +
                        std::to_string(GetSec()) + 
                        "] ";

    File::WriteFile(base + message, "1");

    std::cout << message << std::endl;
}
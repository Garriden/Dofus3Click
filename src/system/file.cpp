#include <filesystem>
#include <fstream>
#include "system/file.hpp"
#include <iostream>
#include <string>
//#include "Utils.h"
//#include "ActualTime.h"

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
        std::cout << "Could not open the file: " << filePath << ". Error: " << error.message() << std::endl;
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
        LOG_WARN("Could not remove the file: {}. Error: {}", filePath, error.message());
    }
}

void LogFile(std::string message)
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

	std::string filename(s);
	std::ofstream file_out;

	file_out.open(filename, std::ios_base::app);
	file_out << base << message << std::endl;
	file_out.close();

	std::cout << message << std::endl;
}
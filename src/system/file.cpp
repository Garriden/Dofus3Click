#include "system/file.hpp"
#include "utils.hpp"
#include "system/actualTime.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

namespace { // anonymus namespace.
    std::string trimLeadingWhitespace(const std::string& str) {
        size_t firstNonSpace = str.find_first_not_of(" \t\n\r\f\v"); // Find the first non-whitespace character

        if(firstNonSpace == std::string::npos) {
            // String is all whitespace
            return "";
        }

        std::string ret = str.substr(firstNonSpace);

        size_t pos = ret.find(" ");
        if(pos != std::string::npos) {
            ret = str.substr(0, pos);
        }

        return ret;
    }

    bool isSingleCharacter(const std::string& str) {
        if(str.length() == 1) {
            return true;
        }

        return false;
    }
}

std::vector<std::vector<std::pair<int, int> > > File::ReadFileAndBuildMap(const std::string &filePath)
{
    auto isNumber = [](const std::string& str) -> bool { // Local function needed to parse strings.
        for (char c : str) {
            if (!std::isdigit(c) && c != '-' && c != '.') {
                return false;
            }
        }
        return !str.empty();
    };

    // Find file.
    std::filesystem::path path{ filePath };

    std::vector<std::vector<std::pair<int, int> > > ret;

    std::vector<std::pair<int, int> > row;
    std::pair<int, int> coord;
    std::string word, word2;

    // Read file.
    std::error_code error;
    if(std::filesystem::exists(path, error)) {
        std::ifstream ifs(path);
        std::string line;

        while(std::getline(ifs, line)) { // Read line by line
            row.clear();
            std::stringstream str(line);
 
            while(std::getline(str, word, ',')) {
                word = trimLeadingWhitespace(word);

                std::getline(str, word2, ',');
                word2 = trimLeadingWhitespace(word2);

                if(word == "up" || (isNumber(word2) && isNumber(word) && (stoi(word2) <= UP_Y + ERROR_GET_COLOUR_QUITE)) ) { // CheckChangeMap
                    coord.first  = UP_X;
                    coord.second = UP_Y;
                } else if(word == "left" || (isNumber(word) && (stoi(word) <= LEFT_X + ERROR_GET_COLOUR_QUITE)) ) {
                    coord.first  = LEFT_X;
                    coord.second = LEFT_Y;
                } else if(word == "down" || (isNumber(word2) && isNumber(word) && (stoi(word2) >= DOWN_Y - ERROR_GET_COLOUR_QUITE)) ) {
                    coord.first  = DOWN_X;
                    coord.second = DOWN_Y;
                } else if(word == "right" || (isNumber(word) && (stoi(word) >= RIGHT_X - ERROR_GET_COLOUR_QUITE)) ) {
                    coord.first  = RIGHT_X;
                    coord.second = RIGHT_Y;
                } else {
                    if(isNumber(word) && isNumber(word2)) {
                        coord.first = stoi(word);
                        coord.second = stoi(word2);
                    } else {
                        std::cout << "character: " << word << std::endl;
                        if(isSingleCharacter(word)) {
                            // An ugly way to translate the character I have in the .csv file into the coordenates vector.
                            //  if I find a character in the .csv file, I build the coordenate vector<pair<int,int> > as:
                            //   {INPUT_PATTERN_CHARACTER, character}.
                            coord.first = INPUT_PATTERN_CHARACTER;
                            coord.second = static_cast<int>(word[0]);
                        } else {
                            std::cout << "word: is NOT a single character!" << std::endl;
                            if(word == "ESC") {
                                coord.first = INPUT_PATTERN_ESC;
                                coord.second = 0;
                            } else if(word == "ctrl") {
                                if(isSingleCharacter(word2)) {
                                    coord.first = INPUT_PATTERN_CTRL;
                                    coord.second = static_cast<int>(word2[0]);
                                }
                            }
                        }
                    }
                }
                row.push_back(coord);
                //std::cout <<  "coord.first: " << coord.first  << "  coord.second: " << coord.second << std::endl;
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
        std::ofstream ofs(path);
    }

    return ret;
}

void File::WriteFile(const std::string &dataToWrite, const std::string &filePath)
{
    // Find file.
    std::filesystem::path path{ filePath };

    // Write it into file in append mode.
    std::ofstream ofs(path, std::ios_base::app);

    ofs << dataToWrite << std::endl;
    ofs.close();
}

void File::DeleteLocalFile(const std::string &filePath)
{
    std::filesystem::path path{ filePath };

    std::error_code error;
    if(!std::filesystem::remove(path, error)) {
        std::cout << "! Could not remove the file: " << filePath << ". Error: " << error.message() << std::endl;
    }
}

void File::LogFile(std::string message, bool date)
{
    std::cout <<  message << std::endl;

    std::string day = std::to_string(GetDay());
    if(day.length() < 2) {
        day = '0' + day;
    }

    std::string month = std::to_string(GetMonth());
    if(month.length() < 2) {
        month = '0' + month;
    }

    std::string  year = std::to_string(GetYear());

    std::string s = day + month + year + ".txt";

    std::string base = "";
    if(date) {
        std::string hour = std::to_string(GetHour());
        if(hour.length() < 2) {
            hour = '0' + hour;
        }

        std::string min = std::to_string(GetMin());
        if(min.length() < 2) {
            min = '0' + min;
        }

        std::string sec = std::to_string(GetSec());
        if(sec.length() < 2) {
            sec = '0' + sec;
        }

        base = "[" + hour + ":" + min + ":" + sec + "] ";
    }

    File::WriteFile(base + message, s);
}
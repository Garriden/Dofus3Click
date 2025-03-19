#include "system/inputs.hpp"
#include "system/file.hpp"
#include "utils.hpp"
#include "basicOperations.hpp"
#include "menusInterface.hpp"

#include <iostream>
#include <windows.h>
#include <chrono>
#include <thread>
#include <filesystem>

std::vector<std::vector<std::pair<int, int> > > TranslateCSVToArray(std::string file_name)
{
    std::fstream file(file_name, std::ios::in);

    std::vector<std::vector<std::pair<int, int> > > content;
    std::vector<std::pair<int, int> > row;
    std::pair<int, int> coord;
    std::string line, word;

    while(getline(file, line)) {
        row.clear();

        std::stringstream str(line);

        while(getline(str, word, ',')) {
            coord.first = stoi(word);
            getline(str, word, ',');
            coord.second = stoi(word);
            row.push_back(coord);
        }
        content.push_back(row);
    }

    return content;
}

std::vector<std::vector<std::pair<int, int> > > GetCSVFile(std::string file_name)
{
    std::string file_name_path = "x64/Release/Telemetry/" + file_name + ".csv";
    std::fstream file(file_name_path, std::ios::in);

    if (!file.is_open()) {
        file_name_path = "Telemetry/" + file_name + ".csv";
        std::fstream file(file_name_path, std::ios::in);
        if (!file.is_open()) {
            File::LogFile("Could not open the file", true);
        }
    }
    return TranslateCSVToArray(file_name_path);
}


void DebugPoints()
{
    Show::MenuDebugPoints();
    while (true) {
        if (GetAsyncKeyState(VK_LCONTROL)) {
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            POINT cursorPos;
            GetCursorPos(&cursorPos);
            std::cout << "Mouse X = " << cursorPos.x << std::endl;
            std::cout << "Mouse Y = " << cursorPos.y << std::endl;
            COLORREF color = GetColor(cursorPos.x, cursorPos.y, true);
        } else if(GetAsyncKeyState(VK_LSHIFT)) {
            RecordTelemetry();
        }
    }
}

void RecordTelemetry()
{
    std::vector<std::pair<int, int> > Coord;
    POINT cursor;
    char buff[256];
    int pos = 0;
    int territory = 0;
    bool firstTime = true;
    bool telemetry_paused = false;

    while(true) {

        if(firstTime) {
            firstTime = false;
            //sprintf_s(buff, "const std::vector < std::vector<std::pair<int, int> > > Coordets = { \n");
        }

        if(GetAsyncKeyState(VK_LSHIFT)) {
            if(telemetry_paused) {
                telemetry_paused = false;
                std::cout << "Telemetry paused." << std::endl;
            } else {
                std::cout << "Telemetry ON." << std::endl;
                telemetry_paused = true;
            }
            telemetry_paused = !telemetry_paused;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

        if(!telemetry_paused) {
            if(GetAsyncKeyState(VK_ESCAPE)) {
                std::cout << "Escape pressed!" << std::endl;

                break;
            }     

            if(GetAsyncKeyState(VK_LBUTTON) < 0) { // Click
                std::cout << "Click!" << std::endl;
                GetCursorPos(&cursor);
                Coord.push_back(std::make_pair(cursor.x, cursor.y));
                ++pos;
                Sleep(500);
            } else if(GetAsyncKeyState(VK_NUMPAD1) < 0) {
                Sleep(500);
                Coord.push_back(std::make_pair(-1, -1));
            } else if(GetAsyncKeyState(VK_NUMPAD2) < 0) {
                Sleep(500);
                Coord.push_back(std::make_pair(-2, -2));
            } else if(GetAsyncKeyState(VK_NUMPAD3) < 0) {
                Sleep(500);
                Coord.push_back(std::make_pair(-3, -3));
            } else if(GetAsyncKeyState(VK_NUMPAD4) < 0) {
                Sleep(500);
                Coord.push_back(std::make_pair(-4, -4));
            } else if(GetAsyncKeyState(VK_NUMPAD5) < 0) {
                Sleep(500);
                Coord.push_back(std::make_pair(-5, -5));
            } else if(GetAsyncKeyState(VK_SPACE)) {
                std::cout << std::endl; 
                File::LogFile("\r\nCoord: ", false);
                for (int ii = 0; ii < static_cast<int>(Coord.size()); ++ii) {
                    File::LogFile( std::to_string(Coord[ii].first) + "," + std::to_string(Coord[ii].second), false);
                    std::cout << "{" << Coord[ii].first << "," << Coord[ii].second << "}" << std::endl;
                    if (ii < static_cast<int>(Coord.size()) - 1) {
                        std::cout << ", ";
                        File::LogFile(", ", false);
                    }
                }

                Coord.clear();

                ++territory;

                Sleep(500);
            }
        }

    }
    std::cout << "Record Telemetry ended." << std::endl;

}
#include "system/inputs.hpp"
#include "system/file.hpp"
#include "utils.hpp"
#include "basicOperations.hpp"
#include "menusInterface.hpp"

#include <windows.h>
#include <chrono>
#include <thread>
#include <filesystem>
#include <iostream>

namespace {
    bool FindDofusExe(COLORREF color)
    {
        bool ret = false;

        /* It is the desiRED  color */
        if(((int(GetRValue(color)) < DOFUS_EXE_POS_COLOR_RED_1   + ERROR_GET_COLOUR_SMALL) &&
            (int(GetRValue(color)) > DOFUS_EXE_POS_COLOR_RED_1   - ERROR_GET_COLOUR_SMALL) &&
            (int(GetGValue(color)) < DOFUS_EXE_POS_COLOR_GREEN_1 + ERROR_GET_COLOUR_SMALL) &&
            (int(GetGValue(color)) > DOFUS_EXE_POS_COLOR_GREEN_1 - ERROR_GET_COLOUR_SMALL) &&
            (int(GetBValue(color)) < DOFUS_EXE_POS_COLOR_BLUE_1  + ERROR_GET_COLOUR_SMALL) &&
            (int(GetBValue(color)) > DOFUS_EXE_POS_COLOR_BLUE_1  - ERROR_GET_COLOUR_SMALL))
            ||
            ((int(GetRValue(color)) < DOFUS_EXE_POS_COLOR_RED_2   + ERROR_GET_COLOUR_SMALL) &&
            (int(GetRValue(color)) > DOFUS_EXE_POS_COLOR_RED_2   - ERROR_GET_COLOUR_SMALL) &&
            (int(GetGValue(color)) < DOFUS_EXE_POS_COLOR_GREEN_2 + ERROR_GET_COLOUR_SMALL) &&
            (int(GetGValue(color)) > DOFUS_EXE_POS_COLOR_GREEN_2 - ERROR_GET_COLOUR_SMALL) &&
            (int(GetBValue(color)) < DOFUS_EXE_POS_COLOR_BLUE_2  + ERROR_GET_COLOUR_SMALL) &&
            (int(GetBValue(color)) > DOFUS_EXE_POS_COLOR_BLUE_2  - ERROR_GET_COLOUR_SMALL)) )
        {
            ret = true;
            File::LogFile("FindDofusExe (dot) it is found!", true);
        }

        return ret;
    }
}

void inputs::PressKey(int keyParam)
{
    SHORT key;
    UINT mappedkey;
    INPUT input = { 0 };
    key = VkKeyScan(keyParam);
    mappedkey = MapVirtualKey(LOBYTE(key), 0);
    input.type = INPUT_KEYBOARD;
    input.ki.dwFlags = KEYEVENTF_SCANCODE;
    input.ki.wScan = mappedkey;
    SendInput(1, &input, sizeof(input));
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(input));
}

void inputs::PressCtrlKey(int keyParam)
{
    SHORT key;
    UINT mappedkey;
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;

    // Press the "Ctrl" key
    ip.ki.wVk = VK_CONTROL;
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    // Press the key
    key = VkKeyScan(keyParam);
    mappedkey = MapVirtualKey(LOBYTE(key), 0);
    ip.ki.dwFlags = KEYEVENTF_SCANCODE;
    ip.ki.wScan = mappedkey;
    SendInput(1, &ip, sizeof(INPUT));
    std::this_thread::sleep_for(std::chrono::milliseconds(30));

    // Release the key
    ip.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    // Release the "Ctrl" key
    ip.ki.wVk = VK_CONTROL;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    //Sleep(SECONDS); // pause for 1 second
}

bool inputs::ClickOnExe()
{
    int x = DOFUS_EXE_POS_X_1;
    int y = DOFUS_EXE_POS_Y_1;
    COLORREF color;

    for(int ii = 0; ii < 200; ii += 2) {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        color = basicOperations::GetColor(x+ii, y, false);

        if(FindDofusExe(color)) {
            Click(x+ii, y);
            return true;
        }
    }

    return false;
}

void inputs::Click(int x, int y)
{
    int ruletNumber = basicOperations::RuletaInput(10, 20);

    // Press it!
    SetCursorPos(x, y);
    std::this_thread::sleep_for(std::chrono::milliseconds(30));
    mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);

    std::this_thread::sleep_for(std::chrono::milliseconds(10 * ruletNumber));
}

void inputs::DebugPoints()
{
    show::MenuDebugPoints();
    while (true) {
        if (GetAsyncKeyState(VK_LCONTROL)) {
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            POINT cursorPos;
            GetCursorPos(&cursorPos);
            std::cout << "Mouse X = " << cursorPos.x << std::endl;
            std::cout << "Mouse Y = " << cursorPos.y << std::endl;
            COLORREF color = basicOperations::GetColor(cursorPos.x, cursorPos.y, true);
        } else if(GetAsyncKeyState(VK_LSHIFT)) {
            RecordTelemetry();
        }
    }
}

void inputs::RecordTelemetry()
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
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
            } else if(GetAsyncKeyState(VK_NUMPAD1) < 0) {
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                Coord.push_back(std::make_pair(-1, -1));
            } else if(GetAsyncKeyState(VK_NUMPAD2) < 0) {
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                Coord.push_back(std::make_pair(-2, -2));
            } else if(GetAsyncKeyState(VK_NUMPAD3) < 0) {
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                Coord.push_back(std::make_pair(-3, -3));
            } else if(GetAsyncKeyState(VK_NUMPAD4) < 0) {
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                Coord.push_back(std::make_pair(-4, -4));
            } else if(GetAsyncKeyState(VK_NUMPAD5) < 0) {
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
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
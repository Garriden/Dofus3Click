#include "inputs.hpp"
#include "basicOperations.hpp"

#include <iostream>
#include <windows.h>
#include <chrono>
#include <thread>

void ShowMenuDebugPoints()
{
    std::cout << "TITLE Debug points"                   << std::endl;
    std::cout << "==================================="  << std::endl;
    std::cout << "press CTRL  to get a point"           << std::endl;
    std::cout << "press SHIFT to record telemetry"      << std::endl;
    std::cout << "  - Click to save the point"          << std::endl;
    std::cout << "  - SPACE to change map (subvector)"  << std::endl;
    std::cout << "  - ESC   to end the telemetry"       << std::endl;
    std::cout << "  - You can put numpads numbers"      << std::endl;
    std::cout << "==================================="  << std::endl;
}

/*
 * Give information of the coordenates of real clicks.
 */
void DebugPoints()
{
    ShowMenuDebugPoints();
    while (true) {
        if (GetAsyncKeyState(VK_LCONTROL)) {
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            POINT cursorPos;
            GetCursorPos(&cursorPos);
            std::cout << "Mouse X = " << cursorPos.x << std::endl;
            std::cout << "Mouse Y = " << cursorPos.y << std::endl;
            COLORREF color = GetColor(cursorPos.x, cursorPos.y, true);
        } else if(GetAsyncKeyState(VK_LSHIFT)) {
            //recordTelemetry();
        }
    }
}
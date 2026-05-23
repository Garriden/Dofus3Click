#include "system/inputs.hpp"
#include "menusInterface.hpp"
#include "menus.hpp"
#include "train.hpp"
#include "OpenCVWrapper.hpp" //#include "openCVOperations.hpp"

#include "checks.hpp"
#include "fight.hpp"

#include "roadmap.hpp"
#include "zaap.hpp"

#include <windows.h>
#include <stdio.h>






int main()
{
    // Activating the console in the other screen.
    AllocConsole();
    HWND consoleWindow = GetConsoleWindow();
    if(consoleWindow != NULL) {
        if(GetSystemMetrics(SM_CMONITORS) > 1) {
            SetWindowPos(consoleWindow, 0, -600, -300, 600, 1000, 0);
        } else {
            SetWindowPos(consoleWindow, 0, 0, 0, 340, 900, 0);
        }
    }

    //inputs::GetWindowsVersion();
    
    //AskPj();
    while(true) {
        show::MainMenu();
        inputs::PressCtrlKey(0);  // Reset Ctrl.
        inputs::PressShiftKey(0); // Reset Shift.
        int in;
        std::cin >> in;
        switch(in) {
            case 0:
            default:
                return 0;
                break;
            case 1:
                inputs::DebugPoints();
                break;
            case 2:
                menu::Farmer();
                break;
            case 3:
                menu::Wood();
                break;
            case 4:
                menu::Mineral();
                break;
            case 5:
                menu::Alchemist();
                break;
            case 6:
                menu::Fisherman();
                break;
            case 9:
                menu::DailyMissions();
                break;
            case 10:
            {
                menu::FindEnemiesMenu();
                break;
            }
            case 11: // Find enemies directly.
            {
                inputs::ClickOnExe();

                while(1) {
                    Train train;
                    train.IterateBetweenMaps();
                }
                break;
            }
            case 70:
                //LogFile("Slow PC.");
                //#undef SECONDS
                //#define SECONDS (1250);
                break;
            case 71:
                //current_pj_ = "ENU";
                //invos_ = true;
                //heal_ = true;
                //LogFile("Playing as Enutrof.");
                break;
            case 99: //debug
                //char buffer[MAX_PATH];
                //GetCurrentDirectoryA(MAX_PATH, buffer);
                //std::string currentPath(buffer);
                //File::LogFile("Current directory: " + currentPath, true);

                std::this_thread::sleep_for(std::chrono::seconds(1));
                inputs::ClickOnExe();
                std::this_thread::sleep_for(std::chrono::seconds(5));

                //std::this_thread::sleep_for(std::chrono::seconds(3));
                //check::AmILevelUp();

                //check::AmIDefeated();
                //zaap::CheckZaapAstrub();
                //check::IsMenuPrincipalBox();

                //std::this_thread::sleep_for(std::chrono::seconds(3));

                //inputs::ShiftClick(1000, 300);

                //if(check::IsFight()) {
                //    Fight fight(0);
                //    fight.Start();
                //}

                //std::this_thread::sleep_for(std::chrono::seconds(2));
#if USE_OPENCV

                double confidenceThreshold = 0.80;
                int XPos = -1;
                int YPos = -1;
                //bool success = OpenCVOperations::FindImage("Images/Zaap/zaapInterface.PNG", XPos, YPos);
                //bool success = OpenCVOperations::CheckPj("Feca"); // TODO: OCR tesseract find text. (see branch)

                //OpenCVOperations::CountMobsByTextLines();
                int mobs = Wrapper_CountMobsByTextLines();
                File::LogFile("Wrapper returned safely! Mobs: " + std::to_string(mobs), true);

#endif
                std::this_thread::sleep_for(std::chrono::seconds(1));
                //Roadmap roadmap(Profession::TEST, "hola", nullptr, nullptr,
                //    {"", "../../Telemetry/test.csv", /*"../../Telemetry/Fisher/Ganaderoslv80_2.csv"*/});
                //roadmap.Start();
                
            break;
        }
    }

    return 0;
}
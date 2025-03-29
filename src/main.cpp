#include "system/inputs.hpp"
#include "menusInterface.hpp"
#include "menus.hpp"


#include "checks.hpp"
#include "fight.hpp"
#include "roadmap.hpp"


#include <windows.h>
#include <iostream>

int main()
{
    std::cout << "holaaaaaaa" << std::endl;

    // Activeting the console in the other screen.
    AllocConsole();
    HWND consoleWindow = GetConsoleWindow();
    if (consoleWindow != NULL) {
        SetWindowPos(consoleWindow, 0, -600, -300, 600, 1000, 0);
    }
    
    //AskPj();
    while(true) {
        show::MainMenu();
        inputs::PressCtrlKey(0); // Reset Ctrl.
        int in;
        std::cin >> in;
        switch(in) {
            case 0:
            default:
                return 0; //system("exit");
                break;
            case 1:
                inputs::DebugPoints();
                break;
            case 2:
                //FarmerMenu();
                break;
            case 3:
                menu::Wood();
                break;
            case 4:
                //MineralMenu();
                break;
            case 5:
                //AlchemistMenu();
                break;
            case 6:
                //FishermanMenu();
                break;
            case 9:
                //DailyMissionsMenu();
                break;
            case 10:
                //FindEnemiesMenu();
                break;
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
                //if(check::IsFight()) {
                //    Fight fight(0);
                //    fight.Start();
                //}

                //Sleep(5000);
                //roadmap::ExecuteRoadMap("../../Telemetry/Wood/astrubAshLv1.csv");
                //FindExe();
            break;
        }
    }

    return 0;
}
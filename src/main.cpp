#include<windows.h>
#include <iostream>

int main()
{
    std::cout << "holaaaaaaa" << std::endl;

    // TODO: External console
    //HWND hwnd = GetConsoleWindow();
    //MoveWindow(hwnd, 0, 0,200, 400,TRUE);

    //AskPj();
    while(true) {
        //showMainMenu();
        int in;
        std::cin >> in;
        switch(in) {
            case 0:
            default:
                return 0; //system("exit");
                break;
            case 1:
                //DebugPoints();
                break;
            case 2:
                //FarmerMenu();
                break;
            case 3:
                //WoodMenu();
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
            case 90: //debug
                Sleep(5000);
                //if(!restart_roadmap_) ExecuteRoadMap("Fisher/SufokianShorelinelv40_4");
                //FindExe();
            break;
        }
    }

    return 0;
}
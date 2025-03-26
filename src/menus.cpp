#include "menus.hpp"
#include "menusInterface.hpp"
#include "basicOperations.hpp"
#include "roadmap.hpp"
#include "zaap.hpp"
#include "checksRoadmap.hpp"
#include "system/inputs.hpp"
#include "system/file.hpp"
#include <iostream>
#include <thread>
#include <chrono>

void menu::Wood()
{
    show::WoodMenu();
    //Wood wood();

    int in, x, y;
    std::cin >> in;

    if(!inputs::ClickOnExe()) {
        File::LogFile("! Error Cannot find Dofus exe!", true);
        return;
    }

    switch(in) {
        case 0:
        default:
            break;

        case 1:
            File::LogFile("lv.1  [ASTRUB] . . . ", true);
            Roadmap roadmap(Profession::WOOD, "Astrub");
            roadmap.Start();
            //Astrub();
            break;
    }
}
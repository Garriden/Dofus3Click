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

    switch(in) 
    {
        case 0:
        default:
            break;
        case 1:
        {
            File::LogFile("lv.1  [ASTRUB] . . . ", true);
            Roadmap roadmap(Profession::WOOD, "Astrub", &checkRoadmap::CheckWoodLv1, &zaap::CheckZaapAstrub,
                {"../../Telemetry/Wood/fromAstrubZaapToWoodLv1.csv", "../../Telemetry/Wood/astrubAshLv1.csv"});
            roadmap.Start();
            //Astrub();
            break;
        }
        case 2:
        {
            File::LogFile("lv.20 [AMAKNA]        (linde) . . . ", true);
            Roadmap roadmap(Profession::WOOD, "linde", &zaap::CheckZaapLinde, &zaap::CheckZaapLinde,
                {"", "../../Telemetry/Wood/fromLindeZaapToWoodLv20.csv", "../../Telemetry/Wood/amaknaCheLv20.csv", 
                 "../../Telemetry/Wood/amaknaWoodTaller.csv", "../../Telemetry/Wood/amaknaCheLv20FromTallerToFinish.csv",
                 "../../Telemetry/Wood/formAmaknaCheLv20FinishToStart.csv"});
            roadmap.Start();
            break;
        }
    }
}
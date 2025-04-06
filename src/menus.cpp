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

    int in;
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
        case 4:
        {
            File::LogFile("lv.70 [BOMBU]        (llanura) . . . ", true);
            Roadmap roadmap(Profession::WOOD, "puerka", &zaap::CheckZaapPuerkazos, &zaap::CheckZaapPuerkazos,
                {"", "../../Telemetry/Wood/bombu1.csv", "../../Telemetry/Wood/bombu2.csv",  "../../Telemetry/Wood/bombu3.csv",
                     "../../Telemetry/Wood/bombu4.csv", "../../Telemetry/Wood/bombu5.csv"});
            roadmap.Start();
            break;
        }
        case 8:
        {
            File::LogFile("[OTOMAI]         (coast) . . . ", true);
            Roadmap roadmap(Profession::WOOD, "costero", &checkRoadmap::CheckOtomaiCoast, &zaap::CheckZaapOtoCoast,
                {"../../Telemetry/Wood/fromCoastToWoodOtomai.csv", "../../Telemetry/Wood/otomaiWoodCoast.csv", "../../Telemetry/Wood/fromOtomaiCenterToCoastInitial.csv"});
            roadmap.Start();
            break;
        }
        case 9:
        {
            File::LogFile("[OTOMAI]         (all) . . . ", true);
            Roadmap roadmap(Profession::WOOD, "costero", &checkRoadmap::CheckOtomaiCoast, &zaap::CheckZaapOtoCoast,
                {"../../Telemetry/Wood/fromCoastToWoodOtomai.csv", "../../Telemetry/Wood/otomaiWood.csv"});
            roadmap.Start();
            break;
        }
        case 10:
        {
            File::LogFile("[KOALAKS]      (ganaderos) . . . ", true);
            Roadmap roadmap(Profession::WOOD, "ganaderos", &zaap::CheckZaapKoalak, &zaap::CheckZaapKoalak,
                {"../../Telemetry/Wood/fromBreedToWoodKoalak.csv", "../../Telemetry/Wood/koalak.csv", 
                 "../../Telemetry/Wood/kaliptusMiddle.csv", "../../Telemetry/Wood/fromBreedToWoodKoalak.csv"});
            roadmap.Start();
            break;
        }
    }
}

void menu::FindEnemiesMenu()
{
    show::FindEnemiesMenu();

    int in;
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
            File::LogFile("1  = Jabatos               (Astrub)", true);
            Roadmap roadmap(Profession::TRAIN, "astrub", &zaap::CheckZaapAstrub, &zaap::CheckZaapAstrub,
                {"../../Telemetry/Train/astrub.csv", ""});
            roadmap.Start();
            break;
        }
        case 2:
        {
            File::LogFile("2  = Abraknidos             (Linde)", true);
            Roadmap roadmap(Profession::TRAIN, "linde", &zaap::CheckZaapLinde, &zaap::CheckZaapLinde,
                {"../../Telemetry/Train/linde.csv", ""});
            roadmap.Start();
            break;
        }
        case 4:
        {
            File::LogFile("4  = Cochinillos           (Puerka)", true);
            Roadmap roadmap(Profession::TRAIN, "puerka", &zaap::CheckZaapPuerkazos, &zaap::CheckZaapPuerkazos,
                {"../../Telemetry/Train/puerka.csv", ""});
            roadmap.Start();
            break;
        }
        case 6:
        {
            File::LogFile("6  = Cocodrilos         (Ganaderos)", true);
            Roadmap roadmap(Profession::TRAIN, "ganaderos", &zaap::CheckZaapKoalak, &zaap::CheckZaapKoalak,
                {"../../Telemetry/Train/cocodrilos.csv", ""});
            roadmap.Start();
            break;
        }
        case 10:
        {
            File::LogFile("10 = Kokokos                 (Moon)", true);
            Roadmap roadmap(Profession::TRAIN, "moon", &zaap::CheckZaapMoon, &zaap::CheckZaapMoon,
                {"../../Telemetry/Train/moon.csv", ""});
            roadmap.Start();
            break;
        }
        case 20:
        {
            File::LogFile("20 = Jalamuts               (Burgo)", true);
            Roadmap roadmap(Profession::TRAIN, "burgo", &zaap::CheckZaapBurgo, &zaap::CheckZaapBurgo,
                {"../../Telemetry/Train/burgo.csv", ""});
            roadmap.Start();
            break;
        }

        

    }

}
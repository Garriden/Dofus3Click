#include "roadmap.hpp"
#include "fight.hpp"
#include "utils.hpp"
#include "system/inputs.hpp"
#include "system/file.hpp"
#include "basicOperations.hpp"
#include "checks.hpp"
#include "checksRoadmap.hpp"
#include "zaap.hpp"

Roadmap::Roadmap() :
    _profession{},
    _zaap{""},
    _roadmapFiles{}
{
    std::cout << "Roadmap constructor called" << std::endl;
}

Roadmap::Roadmap(Profession profession, std::string zaap, std::vector<std::string> roadmapFiles) :
    _profession{profession},
    _zaap{zaap},
    _roadmapFiles{roadmapFiles}
{
    File::LogFile(("Roadmap started. Profession: " + std::to_string(_profession)).c_str(), true);

    if(_roadmapFiles.size() < 2) {
        File::LogFile("ERROR: _roadmapFiles < 2.  Firt roadmap must be: from zaap to initial position. \
                        And at least have a second roadmap where it does the proper roadmap.", true);
        //return;
    }
}

Roadmap::~Roadmap()
{
    File::LogFile("Roadmap ended!", true);
}

void Roadmap::Start()
{
    int step = RoadmapState::SET_PODS_SET;

    while(1) {
        switch(step) {
        case RoadmapState::SET_PODS_SET:
            SetPodsSet();
            step = RoadmapState::SET_PRIVATE_MODE;
            break;
        case RoadmapState::SET_PRIVATE_MODE:
            if(!check::IsPrivateMode()) {
                inputs::ClickPrivateMode();
            }
            step = RoadmapState::CHECK_INITIAL_POSITION;
            break;
        case RoadmapState::CHECK_INITIAL_POSITION:
            if(checkRoadmap::CheckWoodLv1() && _roadmapFiles[0] != "") {
                step = RoadmapState::EXECUTE_ROADMAP;
            } else {
                step = RoadmapState::CHECK_ZAAP_POSITION;
            }
            break;
        case RoadmapState::CHECK_ZAAP_POSITION:
            if(zaap::CheckZaapAstrub()) {
                step = RoadmapState::GO_TO_INITIAL_MAP;
            } else {
                step = RoadmapState::GO_TO_ZAAP;
            }
            break;
        case RoadmapState::GO_TO_ZAAP:
            File::LogFile("Going to initial Zaap ... ", true);
            inputs::PressCtrlKey('8'); // Recall Poti.
            step = RoadmapState::GO_TO_INITIAL_MAP;
            break;
        case RoadmapState::GO_TO_INITIAL_MAP:
            if(_roadmapFiles[0] != "") {
                ExecuteRoadMap(_roadmapFiles[0]/*"../../Telemetry/Wood/fromAstrubZaapToWoodLv1.csv"*/);
            }
            step = RoadmapState::EXECUTE_ROADMAP;
            break;
        case RoadmapState::EXECUTE_ROADMAP:
            for(int roadmapIndex = 1; roadmapIndex < _roadmapFiles.size(); ++roadmapIndex) {
                if(E_OK != ExecuteRoadMap(_roadmapFiles[roadmapIndex]/*"../../Telemetry/Wood/astrubAshLv1.csv"*/)) {
                    //step = RoadmapState::GO_TO_ZAAP;
                    step = -1;
                }
                //step = RoadmapState::AFTER_FIGHT_SET;
            }

            if(_profession == Profession::LOWERING_PODS) {
                step = -1;
            } else {
                step = RoadmapState::EXECUTE_ROADMAP;
            }

            break;
        /*case RoadmapState::AFTER_FIGHT_SET:
            //AfterFightSet();
            step = RoadmapState::AFTER_FIGHT_SIT;
            break;
        case RoadmapState::AFTER_FIGHT_SIT:
            //AfterFightSit();
            step = -1;
            break;*/
        default:
            return;
            break;
        }
    }

}

int Roadmap::ExecuteRoadMap(std::string name)
{
    File::LogFile("ExecuteRoadMap: " + name, true);
    std::vector<std::vector<std::pair<int, int> > > roadmap = File::ReadFileAndBuildMap(name);

    for(int ii = 0; ii < static_cast<int>(roadmap.size()); ++ii) {
        //File::LogFile("map: " + std::to_string(ii), true);
        //if(restart_roadmap_) {
        //    return;
        //}
        if(E_OK != ClickIdentities(roadmap[ii])) {
            return E_KO;
        }
        //if (restart_roadmap_) {
        //    return;
        //}
    }

    return E_OK;
}


int Roadmap::ClickIdentities(const std::vector<std::pair<int, int> > map)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    int ruletNumber = 1;
    int x = 0;
    int y = 0;

    for(int ii = 0; ii < map.size(); ++ii) {
        //File::LogFile("ii: " + std::to_string(ii), true);
        //if(!restart_roadmap_) {
            ruletNumber = basicOperations::RuletaInput(0, 9) + 1;

            std::this_thread::sleep_for(std::chrono::seconds(8));
            std::this_thread::sleep_for(std::chrono::milliseconds(ruletNumber * 100));

            if(check::IsFight()) {
                Fight fight;
                fight.Start();
            }

            if(_profession != Profession::LOWERING_PODS && check::AmIFull()) {
                Roadmap goToBank(Profession::LOWERING_PODS, "",
                    {"", "../../Telemetry/ZaapToBank/astrubBankTransaction.csv", "../../Telemetry/ZaapToBank/fromAstrubZaapToBank.csv"});
                goToBank.Start();
            }

            std::cout << "c: " <<  map.size() << "    " << map[ii].first << " . " << map[ii].second << std::endl;
            inputs::Click(map[ii].first, map[ii].second);

        //}
    }

    // Change map
    // Sometimes it doesn't change propperly because of "Acción imposible" Dofus error...
    // Catch when screen goes black to detect the map change. Repeat last click if not changed properly.

    // Wait for Black Screen
    bool mapChanged = false;
    int retries = 0;
    while(!mapChanged && retries < 10) {
        for(int ii = 0; !mapChanged && ii < 500; ++ii) {
            if(check::IsBlackScreen()) {
                mapChanged = true;
                //File::LogFile("Backscreen detected! mapChanged", false);
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }

        if(!mapChanged) { // Invalid action, try again.
            File::LogFile(" NO! mapChanged... Clicking again...", true);
            inputs::Click(map[map.size()-1].first, map[map.size()-1].second + retries);
            ++retries;
        }
    }
    if(retries >= 10) {
        File::LogFile("Stuck! So many retries for invalid action...", true);
        return E_KO;
    }
    //std::this_thread::sleep_for(std::chrono::seconds(1));


    //IsFight();

    //if(AmITalkingWithNPJ() || IsMercant() || IsErrorWindow()) {
    //    PressEscape();
    //    std::this_thread::sleep_for(std::chrono::seconds(7));
    //}

    //if(IsMainMenuWindow()) {
    //    PressEscape();
    //}
/*
    if(lowering_pods_ || (!CheckPods() && !restart_roadmap_)) {
        //LogFile("Change maaaaap");
        Sleep(17 * SECONDS + ruletNumber * 100);

        IsFight();

        if (IsMercantMode()) {
            PressEscape();
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
        ruletNumber = Ruleta10();

        x = (map[map.size() - 1].first)  - (ruletNumber / 4);
        y = (map[map.size() - 1].second) - (ruletNumber / 2);

        // Don't hit treasure hunt window 
        if((x < 355) && ((y > 200) && (y < 250))) {
            y = 300;
        }

        // Don't hit office level up window 
        if((x < 355) && ((y > 570) && (y < 715))) {
            y = 750;
        }

        SetCursorPos(x, y);
        Sleep(ruletNumber * 10);

        mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
        Sleep(ruletNumber);
        mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);

        Sleep(3 * SECONDS + ruletNumber * 100);
        
    }
    */
    return E_OK;
}

// Todo: sned to inputs
void Roadmap::ChangeObjectsMenu()
{
    if(check::IsSpellsMenu()) {
        inputs::ClickSwitchBottomMenu();
    } else {
        //File::LogFile("Already Objects menu.", true);
    }
}

void Roadmap::ChangeSpellsMenu()
{
    if(check::IsSpellsMenu()) {
        //File::LogFile("Already Spells menu.", true);
    } else {
        inputs::ClickSwitchBottomMenu();
    }

}

void Roadmap::SetPodsSet()
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    Roadmap::ChangeObjectsMenu();
    std::this_thread::sleep_for(std::chrono::seconds(2));

    inputs::ChangeMenuBar(5, false);

    std::this_thread::sleep_for(std::chrono::seconds(1));
    inputs::PressCtrlKey('3'); // Pods Set
    std::this_thread::sleep_for(std::chrono::seconds(1));
}
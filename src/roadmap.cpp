#include "roadmap.hpp"
#include "utils.hpp"
#include "system/inputs.hpp"
#include "system/file.hpp"
#include "basicOperations.hpp"
#include "checks.hpp"

void roadmap::ExecuteRoadMap(std::string name)
{
    File::LogFile("  ExecuteRoadMap: " + name, true);
    std::vector<std::vector<std::pair<int, int> > > roadmap = File::ReadFileAndBuildMap(name);

    for(int ii = 0; ii < static_cast<int>(roadmap.size()); ++ii) {
        File::LogFile("ii: " + std::to_string(ii), true);
        //if(restart_roadmap_) {
        //    return;
        //}
        ClickIdentities(roadmap[ii]);
        //if (restart_roadmap_) {
        //    return;
        //}
    }
}


void roadmap::ClickIdentities(const std::vector<std::pair<int, int> > map)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    int ruletNumber = 1;
    int x = 0;
    int y = 0;

    //std::cout << "bbbbbbbb: " <<  map.size() << "    " << map[0].first << " . " << map[0].second << std::endl;
    for(int ii = 0; ii < map.size(); ++ii) {
        //File::LogFile("ii: " + std::to_string(ii), true);
        //if(!restart_roadmap_) {
            ruletNumber = basicOperations::RuletaInput(0, 9) + 1;

            std::this_thread::sleep_for(std::chrono::seconds(10));
            std::this_thread::sleep_for(std::chrono::milliseconds(ruletNumber * 100));

            //CheckFight(); TODO

            inputs::Click(map[ii].first, map[ii].second);
        //}
    }

    // Change map
    // Sometimes it doesn't change propperly because of "Acción imposible" Dofus error...
    // Catch when screen goes black to detect the map change. Repeat last click if not changed properly.


    // Wait for Black Screen
    bool mapChanged = false;
    int retries = 0;
    while(!mapChanged && retries < 3) {
        for(int ii = 0; !mapChanged && ii < 500; ++ii) {
            if(check::IsBlackScreen()) {
                mapChanged = true;
                File::LogFile("Backscreen detected! mapChanged", false);
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }

        if(!mapChanged) { // Invalid action, try again.
            File::LogFile(" NO! mapChanged... Clicking again...", true);
            inputs::Click(map[map.size()-1].first, map[map.size()-1].second);
            ++retries;
        }
    }
    //std::this_thread::sleep_for(std::chrono::seconds(1));


    //CheckFight();

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

        CheckFight();

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
}
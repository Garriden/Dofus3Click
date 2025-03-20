//#include "Checks.h"
//#include "Zaap.h"
//#include "OldMapings.h"
//#include "FightStrategy.h"
#include <string>
#include <vector>

namespace roadmap {
    /*
    * Go from map to map following the route. With sleeps.
    *
    * For every map:
    *   - Click all the identities. (hardcoded)
    *   - Move to the another map.
    * 
    * in: name, the file name (.csv) where to pull the telemetry.
    */
    void ExecuteRoadMap(std::string name);

    /*
    * Chop all the identities.
    *
    * Get the all the coordenates (identities location), avoiding the last one (next map move).
    * - Click the first identity, do a small sleep.
    * - Click quickly all the other identities or put a delay between them (DELAY_BETWEEN_CHOPPS).
    *
    * in: map, the vector of Coordenates extracted from telemetry. 
    */
    void ClickIdentities(const std::vector<std::pair<int, int> > map);

    /*
    * Open the consumables inventory and keeps pressing (unfolding bags of resources),
    *  until it is detected a Mimilk or a Recall Potion.
    */
    //void OpenAllBags();

    /*
    * From to Zaap Astrub, go to the bank and save all resources.
    */
    //void SaveItInTheBank();

    /*
    * Retun true if I was full and I lowered pods, false otherwise.
    */
    //bool CheckPods();

    /*
    * If I am a Ghost, execute the roadmap to the closer fenix.
    */
    //void GhostRoadmap();

    /*
    * Old Roadmaps
    */
    //void MineralIronTirihRoadMap();
    //void WoodKoalakRoadMap();
    //void YewOtomaiRoadMap();
    //void OtomaiCenterRoadMap();
    //void YewOtomaiRightRoadMap();
    //void YewOtomaiLeftRoadMap();
    //void OtomaiFromLeftToCenterRoadMap();
    //void OtomaiFromCenterToLeftRoadMap();
    //void WoodAstrubRoadMap();
}
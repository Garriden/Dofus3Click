#include "system/inputs.hpp"

namespace zaap {
    /*
    * Click on the actual zaap (Astrub) and write the destination zaap name.
    * 
    * in: zaap_file, the name of the file where is the destination zaap written. 
    */
    void ClickZaap(std::string zaapName);

    // Check if I'm in the zaap interface.
    bool CheckZaapInterface();

    // Check if I am in Astrub zaap.
    bool CheckZaapAstrub();

    // Check if I am in Linde zaap.
    bool CheckZaapLinde();

    // Check if I am in Cania (Pig plains, Puerkazos) zaap.
    bool CheckZaapPuerkazos();

    //Check if I am in Otomai Coast zaap.
    bool CheckZaapOtoCoast();

    // Check if I am in Koalak breeders village zaap.
    bool CheckZaapKoalak();

    // Check if I am in Burgo(Frigost) zaap.
    bool CheckZaapBurgo();

    // Check if I am in Sepultados(Frigost) zaap.
    bool CheckZaapSeputados();

    // Check if I am in Golfo(Sufokia) zaap.
    bool CheckZaapGolfo();

    // Check if I am in Sufokia zaap.
    bool CheckZaapSufokia();

    // Check if I am in Moon island zaap.
    bool CheckZaapMoon();

    // Check if I am in Llanuras Rocosas zaap.
    bool CheckZaapRocosas();

    // Check if I am in Rincon zaap.
    bool CheckZaapRincon();

    /*
    * Check if I am in Gobball corner zaap.
    */
    //bool CheckZaapGobball();

    /*
    * Check if I am in Cania Massif zaap.
    */
    //bool CheckZaapCaniaMassif();

    /*
    * Check if I am in Moon island zaap.
    */
   // bool CheckZaapMoon();

    /*
    * Check if I am in Sufokian Shoreline zaap.
    */
    //bool CheckZaapSufokianShoreline();
}
#include "utils.hpp"
//#include "Config.h"
//#include "Logs.h"
#include <windows.h>

namespace basicOperations {
    /*
    * Prints the screen size in pixels (resolution: 1920/1080).
    */
    //void GetScreenSize();

    /*
    * Returns a random number between x and y.
    * 
    * in: min, minimum range number.
    * in: max, maximum range number.
    */
    int RuletaInput(int min, int max);

    /*
    * Returns the pixel color RGB(red, green, blue) of x and y positions (coordenates).
    *
    * in: x, pixel in cordenate x.
    * in: y, pixel in cordenate y.
    * in: printRGB, if ture, it prints the RGB color in the console for debug.
    */
    COLORREF GetColor(int x, int y, bool printRGB);
}
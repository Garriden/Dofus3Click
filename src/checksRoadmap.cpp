#include "checksRoadmap.hpp"

bool checkRoadmap::CheckWoodLv1()
{
    bool ret = false;

    COLORREF color1 = basicOperations::GetColor(I_AM_IN_WOOD_LV1_POS_X_1, I_AM_IN_WOOD_LV1_POS_Y_1, true);
    COLORREF color2 = basicOperations::GetColor(I_AM_IN_WOOD_LV1_POS_X_2, I_AM_IN_WOOD_LV1_POS_Y_2, true);
    COLORREF color3 = basicOperations::GetColor(I_AM_IN_WOOD_LV1_POS_X_3, I_AM_IN_WOOD_LV1_POS_Y_3, true);

    // It is the desi color 
    if ((int(GetRValue(color1)) < I_AM_IN_WOOD_LV1_COLOR_RED_1    + ERROR_GET_COLOUR_SOME) &&
        (int(GetRValue(color1)) > I_AM_IN_WOOD_LV1_COLOR_RED_1    - ERROR_GET_COLOUR_SOME) &&
        (int(GetGValue(color1)) < I_AM_IN_WOOD_LV1_COLOR_GREEN_1  + ERROR_GET_COLOUR_SOME) &&
        (int(GetGValue(color1)) > I_AM_IN_WOOD_LV1_COLOR_GREEN_1  - ERROR_GET_COLOUR_SOME) &&
        (int(GetBValue(color1)) < I_AM_IN_WOOD_LV1_COLOR_BLUE_1   + ERROR_GET_COLOUR_SOME) &&
        (int(GetBValue(color1)) > I_AM_IN_WOOD_LV1_COLOR_BLUE_1   - ERROR_GET_COLOUR_SOME)
        &&
        (int(GetRValue(color2)) < I_AM_IN_WOOD_LV1_COLOR_RED_2    + ERROR_GET_COLOUR_SOME) &&
        (int(GetRValue(color2)) > I_AM_IN_WOOD_LV1_COLOR_RED_2    - ERROR_GET_COLOUR_SOME) &&
        (int(GetGValue(color2)) < I_AM_IN_WOOD_LV1_COLOR_GREEN_2  + ERROR_GET_COLOUR_SOME) &&
        (int(GetGValue(color2)) > I_AM_IN_WOOD_LV1_COLOR_GREEN_2  - ERROR_GET_COLOUR_SOME) &&
        (int(GetBValue(color2)) < I_AM_IN_WOOD_LV1_COLOR_BLUE_2   + ERROR_GET_COLOUR_SOME) &&
        (int(GetBValue(color2)) > I_AM_IN_WOOD_LV1_COLOR_BLUE_2   - ERROR_GET_COLOUR_SOME)
        &&
        (int(GetRValue(color3)) < I_AM_IN_WOOD_LV1_COLOR_RED_3    + ERROR_GET_COLOUR_SOME) &&
        (int(GetRValue(color3)) > I_AM_IN_WOOD_LV1_COLOR_RED_3    - ERROR_GET_COLOUR_SOME) &&
        (int(GetGValue(color3)) < I_AM_IN_WOOD_LV1_COLOR_GREEN_3  + ERROR_GET_COLOUR_SOME) &&
        (int(GetGValue(color3)) > I_AM_IN_WOOD_LV1_COLOR_GREEN_3  - ERROR_GET_COLOUR_SOME) &&
        (int(GetBValue(color3)) < I_AM_IN_WOOD_LV1_COLOR_BLUE_3   + ERROR_GET_COLOUR_SOME) &&
        (int(GetBValue(color3)) > I_AM_IN_WOOD_LV1_COLOR_BLUE_3   - ERROR_GET_COLOUR_SOME)
        )
    {
        ret = true;
        File::LogFile("I am at the beggining of Wood lv 1 Roadmap!", true);
    }

    return ret;
}
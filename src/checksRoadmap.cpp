#include "checksRoadmap.hpp"

bool checkRoadmap::CheckWoodLv1()
{
    bool ret = false;

    COLORREF color1 = basicOperations::GetColor(I_AM_IN_WOOD_LV1_POS_X_1, I_AM_IN_WOOD_LV1_POS_Y_1, false);
    COLORREF color2 = basicOperations::GetColor(I_AM_IN_WOOD_LV1_POS_X_2, I_AM_IN_WOOD_LV1_POS_Y_2, false);
    COLORREF color3 = basicOperations::GetColor(I_AM_IN_WOOD_LV1_POS_X_3, I_AM_IN_WOOD_LV1_POS_Y_3, false);

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

bool checkRoadmap::CheckOtomaiCoast()
{
    bool ret = false;

    COLORREF color1 = basicOperations::GetColor(I_AM_IN_WOOD_OTO_COAST_POS_X_1, I_AM_IN_WOOD_OTO_COAST_POS_Y_1, false);
    COLORREF color2 = basicOperations::GetColor(I_AM_IN_WOOD_OTO_COAST_POS_X_2, I_AM_IN_WOOD_OTO_COAST_POS_Y_2, false);
    COLORREF color3 = basicOperations::GetColor(I_AM_IN_WOOD_OTO_COAST_POS_X_3, I_AM_IN_WOOD_OTO_COAST_POS_Y_3, false);

    // It is the desi color 
    if ((int(GetRValue(color1)) < I_AM_IN_WOOD_OTO_COAST_COLOR_RED_1    + ERROR_GET_COLOUR_SOME) &&
        (int(GetRValue(color1)) > I_AM_IN_WOOD_OTO_COAST_COLOR_RED_1    - ERROR_GET_COLOUR_SOME) &&
        (int(GetGValue(color1)) < I_AM_IN_WOOD_OTO_COAST_COLOR_GREEN_1  + ERROR_GET_COLOUR_SOME) &&
        (int(GetGValue(color1)) > I_AM_IN_WOOD_OTO_COAST_COLOR_GREEN_1  - ERROR_GET_COLOUR_SOME) &&
        (int(GetBValue(color1)) < I_AM_IN_WOOD_OTO_COAST_COLOR_BLUE_1   + ERROR_GET_COLOUR_SOME) &&
        (int(GetBValue(color1)) > I_AM_IN_WOOD_OTO_COAST_COLOR_BLUE_1   - ERROR_GET_COLOUR_SOME)
        &&
        (int(GetRValue(color2)) < I_AM_IN_WOOD_OTO_COAST_COLOR_RED_2    + ERROR_GET_COLOUR_SOME) &&
        (int(GetRValue(color2)) > I_AM_IN_WOOD_OTO_COAST_COLOR_RED_2    - ERROR_GET_COLOUR_SOME) &&
        (int(GetGValue(color2)) < I_AM_IN_WOOD_OTO_COAST_COLOR_GREEN_2  + ERROR_GET_COLOUR_SOME) &&
        (int(GetGValue(color2)) > I_AM_IN_WOOD_OTO_COAST_COLOR_GREEN_2  - ERROR_GET_COLOUR_SOME) &&
        (int(GetBValue(color2)) < I_AM_IN_WOOD_OTO_COAST_COLOR_BLUE_2   + ERROR_GET_COLOUR_SOME) &&
        (int(GetBValue(color2)) > I_AM_IN_WOOD_OTO_COAST_COLOR_BLUE_2   - ERROR_GET_COLOUR_SOME)
        &&
        (int(GetRValue(color3)) < I_AM_IN_WOOD_OTO_COAST_COLOR_RED_3     + ERROR_GET_COLOUR_SOME) &&
        (int(GetRValue(color3)) > I_AM_IN_WOOD_OTO_COAST_COLOR_RED_3     - ERROR_GET_COLOUR_SOME) &&
        (int(GetGValue(color3)) < I_AM_IN_WOOD_OTO_COAST_COLOR_GREEN_3   + ERROR_GET_COLOUR_SOME) &&
        (int(GetGValue(color3)) > I_AM_IN_WOOD_OTO_COAST_COLOR_GREEN_3   - ERROR_GET_COLOUR_SOME) &&
        (int(GetBValue(color3)) < I_AM_IN_WOOD_OTO_COAST_COLOR_BLUE_3    + ERROR_GET_COLOUR_SOME) &&
        (int(GetBValue(color3)) > I_AM_IN_WOOD_OTO_COAST_COLOR_BLUE_3    - ERROR_GET_COLOUR_SOME)
        )
    {
        ret = true;
        File::LogFile("I am at the beggining of Wood OTO coast Roadmap!", true);
    }

    return ret;
}

bool checkRoadmap::CheckKoalaksLagos()
{
    bool ret = false;

    COLORREF color1 = basicOperations::GetColor(I_AM_IN_KOALAK_LAKE_POS_X_1, I_AM_IN_KOALAK_LAKE_POS_Y_1, false);
    COLORREF color2 = basicOperations::GetColor(I_AM_IN_KOALAK_LAKE_POS_X_2, I_AM_IN_KOALAK_LAKE_POS_Y_2, false);
    COLORREF color3 = basicOperations::GetColor(I_AM_IN_KOALAK_LAKE_POS_X_3, I_AM_IN_KOALAK_LAKE_POS_Y_3, false);

    // It is the desi color 
    if ((int(GetRValue(color1)) < I_AM_IN_KOALAK_LAKE_COLOR_RED_1    + ERROR_GET_COLOUR_SOME) &&
        (int(GetRValue(color1)) > I_AM_IN_KOALAK_LAKE_COLOR_RED_1    - ERROR_GET_COLOUR_SOME) &&
        (int(GetGValue(color1)) < I_AM_IN_KOALAK_LAKE_COLOR_GREEN_1  + ERROR_GET_COLOUR_SOME) &&
        (int(GetGValue(color1)) > I_AM_IN_KOALAK_LAKE_COLOR_GREEN_1  - ERROR_GET_COLOUR_SOME) &&
        (int(GetBValue(color1)) < I_AM_IN_KOALAK_LAKE_COLOR_BLUE_1   + ERROR_GET_COLOUR_SOME) &&
        (int(GetBValue(color1)) > I_AM_IN_KOALAK_LAKE_COLOR_BLUE_1   - ERROR_GET_COLOUR_SOME)
        &&
        (int(GetRValue(color2)) < I_AM_IN_KOALAK_LAKE_COLOR_RED_2    + ERROR_GET_COLOUR_SOME) &&
        (int(GetRValue(color2)) > I_AM_IN_KOALAK_LAKE_COLOR_RED_2    - ERROR_GET_COLOUR_SOME) &&
        (int(GetGValue(color2)) < I_AM_IN_KOALAK_LAKE_COLOR_GREEN_2  + ERROR_GET_COLOUR_SOME) &&
        (int(GetGValue(color2)) > I_AM_IN_KOALAK_LAKE_COLOR_GREEN_2  - ERROR_GET_COLOUR_SOME) &&
        (int(GetBValue(color2)) < I_AM_IN_KOALAK_LAKE_COLOR_BLUE_2   + ERROR_GET_COLOUR_SOME) &&
        (int(GetBValue(color2)) > I_AM_IN_KOALAK_LAKE_COLOR_BLUE_2   - ERROR_GET_COLOUR_SOME)
        &&
        (int(GetRValue(color3)) < I_AM_IN_KOALAK_LAKE_COLOR_RED_3     + ERROR_GET_COLOUR_SOME) &&
        (int(GetRValue(color3)) > I_AM_IN_KOALAK_LAKE_COLOR_RED_3     - ERROR_GET_COLOUR_SOME) &&
        (int(GetGValue(color3)) < I_AM_IN_KOALAK_LAKE_COLOR_GREEN_3   + ERROR_GET_COLOUR_SOME) &&
        (int(GetGValue(color3)) > I_AM_IN_KOALAK_LAKE_COLOR_GREEN_3   - ERROR_GET_COLOUR_SOME) &&
        (int(GetBValue(color3)) < I_AM_IN_KOALAK_LAKE_COLOR_BLUE_3    + ERROR_GET_COLOUR_SOME) &&
        (int(GetBValue(color3)) > I_AM_IN_KOALAK_LAKE_COLOR_BLUE_3    - ERROR_GET_COLOUR_SOME)
        )
    {
        ret = true;
        File::LogFile("I am at the beggining of KOALAK_LAKE Roadmap!", true);
    }

    return ret;
}

bool checkRoadmap::CheckTirith()
{
    bool ret = false;

    COLORREF color1 = basicOperations::GetColor(I_AM_IN_TIRITH_POS_X_1, I_AM_IN_TIRITH_POS_Y_1, false);
    COLORREF color2 = basicOperations::GetColor(I_AM_IN_TIRITH_POS_X_2, I_AM_IN_TIRITH_POS_Y_2, false);
    COLORREF color3 = basicOperations::GetColor(I_AM_IN_TIRITH_POS_X_3, I_AM_IN_TIRITH_POS_Y_3, false);

    if ((int(GetRValue(color1)) < I_AM_IN_TIRITH_COLOR_RED_1    + ERROR_GET_COLOUR_SOME) &&
        (int(GetRValue(color1)) > I_AM_IN_TIRITH_COLOR_RED_1    - ERROR_GET_COLOUR_SOME) &&
        (int(GetGValue(color1)) < I_AM_IN_TIRITH_COLOR_GREEN_1  + ERROR_GET_COLOUR_SOME) &&
        (int(GetGValue(color1)) > I_AM_IN_TIRITH_COLOR_GREEN_1  - ERROR_GET_COLOUR_SOME) &&
        (int(GetBValue(color1)) < I_AM_IN_TIRITH_COLOR_BLUE_1   + ERROR_GET_COLOUR_SOME) &&
        (int(GetBValue(color1)) > I_AM_IN_TIRITH_COLOR_BLUE_1   - ERROR_GET_COLOUR_SOME)
        &&
        (int(GetRValue(color2)) < I_AM_IN_TIRITH_COLOR_RED_2    + ERROR_GET_COLOUR_SOME) &&
        (int(GetRValue(color2)) > I_AM_IN_TIRITH_COLOR_RED_2    - ERROR_GET_COLOUR_SOME) &&
        (int(GetGValue(color2)) < I_AM_IN_TIRITH_COLOR_GREEN_2  + ERROR_GET_COLOUR_SOME) &&
        (int(GetGValue(color2)) > I_AM_IN_TIRITH_COLOR_GREEN_2  - ERROR_GET_COLOUR_SOME) &&
        (int(GetBValue(color2)) < I_AM_IN_TIRITH_COLOR_BLUE_2   + ERROR_GET_COLOUR_SOME) &&
        (int(GetBValue(color2)) > I_AM_IN_TIRITH_COLOR_BLUE_2   - ERROR_GET_COLOUR_SOME)
        &&
        (int(GetRValue(color3)) < I_AM_IN_TIRITH_COLOR_RED_3     + ERROR_GET_COLOUR_SOME) &&
        (int(GetRValue(color3)) > I_AM_IN_TIRITH_COLOR_RED_3     - ERROR_GET_COLOUR_SOME) &&
        (int(GetGValue(color3)) < I_AM_IN_TIRITH_COLOR_GREEN_3   + ERROR_GET_COLOUR_SOME) &&
        (int(GetGValue(color3)) > I_AM_IN_TIRITH_COLOR_GREEN_3   - ERROR_GET_COLOUR_SOME) &&
        (int(GetBValue(color3)) < I_AM_IN_TIRITH_COLOR_BLUE_3    + ERROR_GET_COLOUR_SOME) &&
        (int(GetBValue(color3)) > I_AM_IN_TIRITH_COLOR_BLUE_3    - ERROR_GET_COLOUR_SOME)
        )
    {
        ret = true;
        File::LogFile("I am inside TIRITH!", true);
    }

    return ret;
}

bool checkRoadmap::CheckAlamo()
{
    bool ret = false;

    COLORREF color1 = basicOperations::GetColor(I_AM_IN_ALAMO_POS_X_1, I_AM_IN_ALAMO_POS_Y_1, false);
    COLORREF color2 = basicOperations::GetColor(I_AM_IN_ALAMO_POS_X_2, I_AM_IN_ALAMO_POS_Y_2, false);
    COLORREF color3 = basicOperations::GetColor(I_AM_IN_ALAMO_POS_X_3, I_AM_IN_ALAMO_POS_Y_3, false);

    if ((int(GetRValue(color1)) < I_AM_IN_ALAMO_COLOR_RED_1    + ERROR_GET_COLOUR_SOME) &&
        (int(GetRValue(color1)) > I_AM_IN_ALAMO_COLOR_RED_1    - ERROR_GET_COLOUR_SOME) &&
        (int(GetGValue(color1)) < I_AM_IN_ALAMO_COLOR_GREEN_1  + ERROR_GET_COLOUR_SOME) &&
        (int(GetGValue(color1)) > I_AM_IN_ALAMO_COLOR_GREEN_1  - ERROR_GET_COLOUR_SOME) &&
        (int(GetBValue(color1)) < I_AM_IN_ALAMO_COLOR_BLUE_1   + ERROR_GET_COLOUR_SOME) &&
        (int(GetBValue(color1)) > I_AM_IN_ALAMO_COLOR_BLUE_1   - ERROR_GET_COLOUR_SOME)
        &&
        (int(GetRValue(color2)) < I_AM_IN_ALAMO_COLOR_RED_2    + ERROR_GET_COLOUR_SOME) &&
        (int(GetRValue(color2)) > I_AM_IN_ALAMO_COLOR_RED_2    - ERROR_GET_COLOUR_SOME) &&
        (int(GetGValue(color2)) < I_AM_IN_ALAMO_COLOR_GREEN_2  + ERROR_GET_COLOUR_SOME) &&
        (int(GetGValue(color2)) > I_AM_IN_ALAMO_COLOR_GREEN_2  - ERROR_GET_COLOUR_SOME) &&
        (int(GetBValue(color2)) < I_AM_IN_ALAMO_COLOR_BLUE_2   + ERROR_GET_COLOUR_SOME) &&
        (int(GetBValue(color2)) > I_AM_IN_ALAMO_COLOR_BLUE_2   - ERROR_GET_COLOUR_SOME)
        &&
        (int(GetRValue(color3)) < I_AM_IN_ALAMO_COLOR_RED_3     + ERROR_GET_COLOUR_SOME) &&
        (int(GetRValue(color3)) > I_AM_IN_ALAMO_COLOR_RED_3     - ERROR_GET_COLOUR_SOME) &&
        (int(GetGValue(color3)) < I_AM_IN_ALAMO_COLOR_GREEN_3   + ERROR_GET_COLOUR_SOME) &&
        (int(GetGValue(color3)) > I_AM_IN_ALAMO_COLOR_GREEN_3   - ERROR_GET_COLOUR_SOME) &&
        (int(GetBValue(color3)) < I_AM_IN_ALAMO_COLOR_BLUE_3    + ERROR_GET_COLOUR_SOME) &&
        (int(GetBValue(color3)) > I_AM_IN_ALAMO_COLOR_BLUE_3    - ERROR_GET_COLOUR_SOME)
        )
    {
        ret = true;
        File::LogFile("I on the first map of Alamo Wood (Frigost)!", true);
    }

    return ret;
}



#include "checks.hpp"

bool check::IsFight()
{
    bool ret = false;

    COLORREF color1 = basicOperations::GetColor(IT_IS_MY_TURN_POS_X_3, IT_IS_MY_TURN_POS_Y_3, false);
    COLORREF color2 = basicOperations::GetColor(IT_IS_MY_TURN_POS_X_4, IT_IS_MY_TURN_POS_Y_4, false);

    // It is the desiRED  color 
    if ((int(GetRValue(color1)) < IT_IS_MY_TURN_COLOR_RED    + ERROR_GET_COLOUR_SMALL) &&
        (int(GetRValue(color1)) > IT_IS_MY_TURN_COLOR_RED    - ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color1)) < IT_IS_MY_TURN_COLOR_GREEN  + ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color1)) > IT_IS_MY_TURN_COLOR_GREEN  - ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color1)) < IT_IS_MY_TURN_COLOR_BLUE   + ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color1)) > IT_IS_MY_TURN_COLOR_BLUE   - ERROR_GET_COLOUR_SMALL)
        &&
        (int(GetRValue(color2)) < IT_IS_MY_TURN_COLOR_RED    + ERROR_GET_COLOUR_SMALL) &&
        (int(GetRValue(color2)) > IT_IS_MY_TURN_COLOR_RED    - ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color2)) < IT_IS_MY_TURN_COLOR_GREEN  + ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color2)) > IT_IS_MY_TURN_COLOR_GREEN  - ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color2)) < IT_IS_MY_TURN_COLOR_BLUE   + ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color2)) > IT_IS_MY_TURN_COLOR_BLUE   - ERROR_GET_COLOUR_SMALL) )
    {
        ret = true;
        //File::LogFile("It is my turn!", true);
    }

    return ret;
}

bool check::IsAlmostTheEndOfTheTurn()
{
    bool ret = false;

    COLORREF color1 = basicOperations::GetColor(IT_IS_MY_TURN_POS_X_3, IT_IS_MY_TURN_POS_Y_3, false);
    COLORREF color2 = basicOperations::GetColor(IT_IS_MY_TURN_POS_X_1, IT_IS_MY_TURN_POS_Y_1, false);

    // color1 == organe, color2 != orange. 
    if ((int(GetRValue(color1)) < IT_IS_MY_TURN_COLOR_RED    + ERROR_GET_COLOUR_SMALL) &&
        (int(GetRValue(color1)) > IT_IS_MY_TURN_COLOR_RED    - ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color1)) < IT_IS_MY_TURN_COLOR_GREEN  + ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color1)) > IT_IS_MY_TURN_COLOR_GREEN  - ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color1)) < IT_IS_MY_TURN_COLOR_BLUE   + ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color1)) > IT_IS_MY_TURN_COLOR_BLUE   - ERROR_GET_COLOUR_SMALL)
        &&
        (int(GetRValue(color2)) < IT_IS_NOT_MY_TURN_COLOR_RED    + ERROR_GET_COLOUR_SMALL) &&
        (int(GetRValue(color2)) > IT_IS_NOT_MY_TURN_COLOR_RED    - ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color2)) < IT_IS_NOT_MY_TURN_COLOR_GREEN  + ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color2)) > IT_IS_NOT_MY_TURN_COLOR_GREEN  - ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color2)) < IT_IS_NOT_MY_TURN_COLOR_BLUE   + ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color2)) > IT_IS_NOT_MY_TURN_COLOR_BLUE   - ERROR_GET_COLOUR_SMALL) )
    {
        ret = true;
        //File::LogFile("It is almost end of a turn!", true);
    }

    return ret;
}

bool check::AmIFull()
{
    bool ret = false;

    COLORREF color = basicOperations::GetColor(CHECK_PODS_POS_X, CHECK_PODS_POS_Y, false);

    if ((int(GetRValue(color)) < CHECK_PODS_COLOR_RED   + ERROR_GET_COLOUR_SMALL) &&
        (int(GetRValue(color)) > CHECK_PODS_COLOR_RED   - ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color)) < CHECK_PODS_COLOR_GREEN + ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color)) > CHECK_PODS_COLOR_GREEN - ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color)) < CHECK_PODS_COLOR_BLUE  + ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color)) > CHECK_PODS_COLOR_BLUE  - ERROR_GET_COLOUR_SMALL)
        )
    {
        File::LogFile("I am full! (pods)", true);
        ret = true;
    }

    return ret;
}

bool check::HaveIHealth()
{
    bool ret = false;

    COLORREF colorHealth = basicOperations::GetColor(HEALTH_POS_X, HEALTH_POS_Y, false);

    if ((int(GetRValue(colorHealth)) < HEALTH_COLOR_RED   + ERROR_GET_COLOUR_SMALL) &&
        (int(GetRValue(colorHealth)) > HEALTH_COLOR_RED   - ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(colorHealth)) < HEALTH_COLOR_GREEN + ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(colorHealth)) > HEALTH_COLOR_GREEN - ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(colorHealth)) < HEALTH_COLOR_BLUE  + ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(colorHealth)) > HEALTH_COLOR_BLUE  - ERROR_GET_COLOUR_SMALL)
        )
    {
        ret = true;
        File::LogFile("I have enough health.", true);
    }
    return ret;
}

bool check::IsPrivateMode()
{
    bool ret = false;

    COLORREF color = basicOperations::GetColor(PRIVATE_MODE_POS_X_1, PRIVATE_MODE_POS_Y_1, false);

    /* It is the desired color */
    if(((int(GetRValue(color)) < PRIVATE_MODE_POS_COLOR_RED_1   + ERROR_GET_COLOUR_QUITE) &&
        (int(GetRValue(color)) > PRIVATE_MODE_POS_COLOR_RED_1   - ERROR_GET_COLOUR_QUITE) &&
        (int(GetGValue(color)) < PRIVATE_MODE_POS_COLOR_GREEN_1 + ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color)) > PRIVATE_MODE_POS_COLOR_GREEN_1 - ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color)) < PRIVATE_MODE_POS_COLOR_BLUE_1  + ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color)) > PRIVATE_MODE_POS_COLOR_BLUE_1  - ERROR_GET_COLOUR_SMALL))
        )
    {
        ret = true;
        File::LogFile("Private mode (dot) it is found!", true);
    }

    return ret;
}

/*
bool IsMimilk(COLORREF color)
{
    bool ret = false;

    // It is the desiRED  color
    if ((int(GetRValue(color)) < INVENTARY_CONSUMABLES_MIMILK_COLOR_RED    + ERROR_GET_COLOUR) &&
        (int(GetRValue(color)) > INVENTARY_CONSUMABLES_MIMILK_COLOR_RED    - ERROR_GET_COLOUR) &&
        (int(GetGValue(color)) < INVENTARY_CONSUMABLES_MIMILK_COLOR_GREEN + ERROR_GET_COLOUR) &&
        (int(GetGValue(color)) > INVENTARY_CONSUMABLES_MIMILK_COLOR_GREEN - ERROR_GET_COLOUR) &&
        (int(GetBValue(color)) < INVENTARY_CONSUMABLES_MIMILK_COLOR_BLUE  + ERROR_GET_COLOUR) &&
        (int(GetBValue(color)) > INVENTARY_CONSUMABLES_MIMILK_COLOR_BLUE  - ERROR_GET_COLOUR)
        )
    {
        ret = true;
        LogFile("Mimilk found!");
    }

    return ret;
}

bool IsRecallPoti(COLORREF color)
{
    bool ret = false;

    // It is the desiRED color 
    if ((int(GetRValue(color)) < INVENTARY_CONSUMABLES_RECALL_POTI_COLOR_RED   + ERROR_GET_COLOUR) &&
        (int(GetRValue(color)) > INVENTARY_CONSUMABLES_RECALL_POTI_COLOR_RED   - ERROR_GET_COLOUR) &&
        (int(GetGValue(color)) < INVENTARY_CONSUMABLES_RECALL_POTI_COLOR_GREEN + ERROR_GET_COLOUR) &&
        (int(GetGValue(color)) > INVENTARY_CONSUMABLES_RECALL_POTI_COLOR_GREEN - ERROR_GET_COLOUR) &&
        (int(GetBValue(color)) < INVENTARY_CONSUMABLES_RECALL_POTI_COLOR_BLUE  + ERROR_GET_COLOUR) &&
        (int(GetBValue(color)) > INVENTARY_CONSUMABLES_RECALL_POTI_COLOR_BLUE  - ERROR_GET_COLOUR)
        )
    {
        ret = true;
        LogFile("Recall Poti found!");
    }

    return ret;
}

bool IsBrakPoti(COLORREF color)
{
    bool ret = false;

    // It is the desired color
    if ((int(GetRValue(color)) < INVENTARY_CONSUMABLES_BRAK_POTI_COLOR_RED   + ERROR_GET_COLOUR) &&
        (int(GetRValue(color)) > INVENTARY_CONSUMABLES_BRAK_POTI_COLOR_RED   - ERROR_GET_COLOUR) &&
        (int(GetGValue(color)) < INVENTARY_CONSUMABLES_BRAK_POTI_COLOR_GREEN + ERROR_GET_COLOUR) &&
        (int(GetGValue(color)) > INVENTARY_CONSUMABLES_BRAK_POTI_COLOR_GREEN - ERROR_GET_COLOUR) &&
        (int(GetBValue(color)) < INVENTARY_CONSUMABLES_BRAK_POTI_COLOR_BLUE  + ERROR_GET_COLOUR) &&
        (int(GetBValue(color)) > INVENTARY_CONSUMABLES_BRAK_POTI_COLOR_BLUE  - ERROR_GET_COLOUR)
        )
    {
        ret = true;
        LogFile("Brak Poti found!");
    }

    return ret;
}

bool IsErrorWindow()
{
    bool ret = false;
    //LogFile("is the error window? ");

    COLORREF color1 = GetColor(IS_ERROR_WINDOW_POS_X_1, IS_ERROR_WINDOW_POS_Y_1);
    COLORREF color2 = GetColor(IS_ERROR_WINDOW_POS_X_2, IS_ERROR_WINDOW_POS_Y_2);
    COLORREF color3 = GetColor(IS_ERROR_WINDOW_POS_X_3, IS_ERROR_WINDOW_POS_Y_3);

    // It is the desiRED   color 
    if ((int(GetRValue(color1)) < IS_ERROR_WINDOW_COLOR_RED   + ERROR_GET_COLOUR_QUITE) &&
        (int(GetRValue(color1)) > IS_ERROR_WINDOW_COLOR_RED   - ERROR_GET_COLOUR_QUITE) &&
        (int(GetGValue(color1)) < IS_ERROR_WINDOW_COLOR_GREEN + ERROR_GET_COLOUR_QUITE) &&
        (int(GetGValue(color1)) > IS_ERROR_WINDOW_COLOR_GREEN - ERROR_GET_COLOUR_QUITE) &&
        (int(GetBValue(color1)) < IS_ERROR_WINDOW_COLOR_BLUE  + ERROR_GET_COLOUR_QUITE) &&
        (int(GetBValue(color1)) > IS_ERROR_WINDOW_COLOR_BLUE  - ERROR_GET_COLOUR_QUITE)
        &&
        (int(GetRValue(color2)) < IS_ERROR_WINDOW_COLOR_RED   + ERROR_GET_COLOUR_QUITE) &&
        (int(GetRValue(color2)) > IS_ERROR_WINDOW_COLOR_RED   - ERROR_GET_COLOUR_QUITE) &&
        (int(GetGValue(color2)) < IS_ERROR_WINDOW_COLOR_GREEN + ERROR_GET_COLOUR_QUITE) &&
        (int(GetGValue(color2)) > IS_ERROR_WINDOW_COLOR_GREEN - ERROR_GET_COLOUR_QUITE) &&
        (int(GetBValue(color2)) < IS_ERROR_WINDOW_COLOR_BLUE  + ERROR_GET_COLOUR_QUITE) &&
        (int(GetBValue(color2)) > IS_ERROR_WINDOW_COLOR_BLUE  - ERROR_GET_COLOUR_QUITE)
        &&
        (int(GetRValue(color3)) < IS_ERROR_WINDOW_COLOR_RED   + ERROR_GET_COLOUR_QUITE) &&
        (int(GetRValue(color3)) > IS_ERROR_WINDOW_COLOR_RED   - ERROR_GET_COLOUR_QUITE) &&
        (int(GetGValue(color3)) < IS_ERROR_WINDOW_COLOR_GREEN + ERROR_GET_COLOUR_QUITE) &&
        (int(GetGValue(color3)) > IS_ERROR_WINDOW_COLOR_GREEN - ERROR_GET_COLOUR_QUITE) &&
        (int(GetBValue(color3)) < IS_ERROR_WINDOW_COLOR_BLUE  + ERROR_GET_COLOUR_QUITE) &&
        (int(GetBValue(color3)) > IS_ERROR_WINDOW_COLOR_BLUE  - ERROR_GET_COLOUR_QUITE)
        )
    {
        LogFile("Is the error window! YES");
        ret = true;
    }

    return ret;
}

bool IsMainMenuWindow()
{
    bool ret = false;
    //LogFile("is the error window? ");

    COLORREF color1 = GetColor(IS_MAIN_MENU_WINDOW_POS_X_1, IS_MAIN_MENU_WINDOW_POS_Y_1);
    COLORREF color2 = GetColor(IS_MAIN_MENU_WINDOW_POS_X_2, IS_MAIN_MENU_WINDOW_POS_Y_2);
    COLORREF color3 = GetColor(IS_MAIN_MENU_WINDOW_POS_X_3, IS_MAIN_MENU_WINDOW_POS_Y_3);

    // It is the desiRED   color 
    if ((int(GetRValue(color1)) < IS_MAIN_MENU_WINDOW_COLOR_RED_1   + ERROR_GET_COLOUR_SMALL) &&
        (int(GetRValue(color1)) > IS_MAIN_MENU_WINDOW_COLOR_RED_1   - ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color1)) < IS_MAIN_MENU_WINDOW_COLOR_GREEN_1 + ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color1)) > IS_MAIN_MENU_WINDOW_COLOR_GREEN_1 - ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color1)) < IS_MAIN_MENU_WINDOW_COLOR_BLUE_1  + ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color1)) > IS_MAIN_MENU_WINDOW_COLOR_BLUE_1  - ERROR_GET_COLOUR_SMALL)
        &&
        (int(GetRValue(color2)) < IS_MAIN_MENU_WINDOW_COLOR_RED_2   + ERROR_GET_COLOUR_SMALL) &&
        (int(GetRValue(color2)) > IS_MAIN_MENU_WINDOW_COLOR_RED_2   - ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color2)) < IS_MAIN_MENU_WINDOW_COLOR_GREEN_2 + ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color2)) > IS_MAIN_MENU_WINDOW_COLOR_GREEN_2 - ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color2)) < IS_MAIN_MENU_WINDOW_COLOR_BLUE_2  + ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color2)) > IS_MAIN_MENU_WINDOW_COLOR_BLUE_2  - ERROR_GET_COLOUR_SMALL)
        &&
        (int(GetRValue(color3)) < IS_MAIN_MENU_WINDOW_COLOR_RED_3   + ERROR_GET_COLOUR_SMALL) &&
        (int(GetRValue(color3)) > IS_MAIN_MENU_WINDOW_COLOR_RED_3   - ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color3)) < IS_MAIN_MENU_WINDOW_COLOR_GREEN_3 + ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color3)) > IS_MAIN_MENU_WINDOW_COLOR_GREEN_3 - ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color3)) < IS_MAIN_MENU_WINDOW_COLOR_BLUE_3  + ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color3)) > IS_MAIN_MENU_WINDOW_COLOR_BLUE_3  - ERROR_GET_COLOUR_SMALL)
        )
    {
        LogFile("Is the MAIN_MENU window! YES");
        ret = true;
    }

    return ret;
 }

bool IsRedCellPreFight(COLORREF color)
{
    bool ret = false;

    // It is the desiRED   color 
    if ((int(GetRValue(color)) < PRE_FIGHT_RED_POSITION_COLOR_RED   + ERROR_GET_COLOUR_SMALL) &&
        (int(GetRValue(color)) > PRE_FIGHT_RED_POSITION_COLOR_RED   - ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color)) < PRE_FIGHT_RED_POSITION_COLOR_GREEN + ERROR_GET_COLOUR) &&
        (int(GetGValue(color)) > PRE_FIGHT_RED_POSITION_COLOR_GREEN - ERROR_GET_COLOUR) &&
        (int(GetBValue(color)) < PRE_FIGHT_RED_POSITION_COLOR_BLUE  + ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color)) > PRE_FIGHT_RED_POSITION_COLOR_BLUE  - ERROR_GET_COLOUR_SMALL)
        )
    {
        //LogFile("RED   CELL!: ");
        ret = true;
    }

    return ret;
}

bool IsTheObjectBarActive()
{
    //std::cout << "is the IsTheObjectBarActive? :" << std::endl;

    bool ret = false;

    COLORREF color1 = GetColor(REST_POS_X, REST_POS_Y);

    Sleep(200);

    // It is the desiRED   color 
    if ((int(GetRValue(color1)) < REST_POS_COLOR_RED   + ERROR_GET_COLOUR) && (int(GetRValue(color1)) > REST_POS_COLOR_RED   - ERROR_GET_COLOUR) &&
        (int(GetGValue(color1)) < REST_POS_COLOR_GREEN + ERROR_GET_COLOUR) && (int(GetGValue(color1)) > REST_POS_COLOR_GREEN - ERROR_GET_COLOUR) &&
        (int(GetBValue(color1)) < REST_POS_COLOR_BLUE  + ERROR_GET_COLOUR) && (int(GetBValue(color1)) > REST_POS_COLOR_BLUE  - ERROR_GET_COLOUR))
    {
        LogFile("Object bar active!");
        ret = true;
    }

    return ret;
}

bool IsTheFightFinished()
{
    bool ret = false;

    COLORREF color1 = GetColor(IS_THE_FIGHT_FINISHED_POS_X_1, IS_THE_FIGHT_FINISHED_POS_Y_1);
    COLORREF color2 = GetColor(IS_THE_FIGHT_FINISHED_POS_X_2, IS_THE_FIGHT_FINISHED_POS_Y_2);
    COLORREF color3 = GetColor(IS_THE_FIGHT_FINISHED_POS_X_3, IS_THE_FIGHT_FINISHED_POS_Y_3);

    // It is the desiRED   color 
    if ((int(GetRValue(color1)) < IS_THE_FIGHT_FINISHED_COLOR_RED_1   + ERROR_GET_COLOUR) &&
        (int(GetRValue(color1)) > IS_THE_FIGHT_FINISHED_COLOR_RED_1   - ERROR_GET_COLOUR) &&
        (int(GetGValue(color1)) < IS_THE_FIGHT_FINISHED_COLOR_GREEN_1 + ERROR_GET_COLOUR) &&
        (int(GetGValue(color1)) > IS_THE_FIGHT_FINISHED_COLOR_GREEN_1 - ERROR_GET_COLOUR) &&
        (int(GetBValue(color1)) < IS_THE_FIGHT_FINISHED_COLOR_BLUE_1  + ERROR_GET_COLOUR) &&
        (int(GetBValue(color1)) > IS_THE_FIGHT_FINISHED_COLOR_BLUE_1  - ERROR_GET_COLOUR)
        &&
        (int(GetRValue(color2)) < IS_THE_FIGHT_FINISHED_COLOR_RED_2   + ERROR_GET_COLOUR) &&
        (int(GetRValue(color2)) > IS_THE_FIGHT_FINISHED_COLOR_RED_2   - ERROR_GET_COLOUR) &&
        (int(GetGValue(color2)) < IS_THE_FIGHT_FINISHED_COLOR_GREEN_2 + ERROR_GET_COLOUR) &&
        (int(GetGValue(color2)) > IS_THE_FIGHT_FINISHED_COLOR_GREEN_2 - ERROR_GET_COLOUR) &&
        (int(GetBValue(color2)) < IS_THE_FIGHT_FINISHED_COLOR_BLUE_2  + ERROR_GET_COLOUR) &&
        (int(GetBValue(color2)) > IS_THE_FIGHT_FINISHED_COLOR_BLUE_2  - ERROR_GET_COLOUR)
        &&
        (int(GetRValue(color3)) < IS_THE_FIGHT_FINISHED_COLOR_RED_3   + ERROR_GET_COLOUR) &&
        (int(GetRValue(color3)) > IS_THE_FIGHT_FINISHED_COLOR_RED_3   - ERROR_GET_COLOUR) &&
        (int(GetGValue(color3)) < IS_THE_FIGHT_FINISHED_COLOR_GREEN_3 + ERROR_GET_COLOUR) &&
        (int(GetGValue(color3)) > IS_THE_FIGHT_FINISHED_COLOR_GREEN_3 - ERROR_GET_COLOUR) &&
        (int(GetBValue(color3)) < IS_THE_FIGHT_FINISHED_COLOR_BLUE_3  + ERROR_GET_COLOUR) &&
        (int(GetBValue(color3)) > IS_THE_FIGHT_FINISHED_COLOR_BLUE_3  - ERROR_GET_COLOUR)
        )
    {
        ret = true;
        //LogFile("Fight finished.");
    }

    return ret;
}
*/
bool check::AmIDefeated()
{
    bool ret = false;
    //LogFile("Am I defeated? ");

    COLORREF color1 = basicOperations::GetColor(I_LOST_THE_FIGHT_POS_X_1, I_LOST_THE_FIGHT_POS_Y_1, false);
    COLORREF color2 = basicOperations::GetColor(I_LOST_THE_FIGHT_POS_X_2, I_LOST_THE_FIGHT_POS_Y_2, false);

    // It is the desiRED   color 
    if ((int(GetRValue(color1)) < I_LOST_THE_FIGHT_COLOR_RED_1   + ERROR_GET_COLOUR_SOME) &&
        (int(GetRValue(color1)) > I_LOST_THE_FIGHT_COLOR_RED_1   - ERROR_GET_COLOUR_SOME) &&
        (int(GetGValue(color1)) < I_LOST_THE_FIGHT_COLOR_GREEN_1 + ERROR_GET_COLOUR_SOME) &&
        (int(GetGValue(color1)) > I_LOST_THE_FIGHT_COLOR_GREEN_1 - ERROR_GET_COLOUR_SOME) &&
        (int(GetBValue(color1)) < I_LOST_THE_FIGHT_COLOR_BLUE_1  + ERROR_GET_COLOUR_SOME) &&
        (int(GetBValue(color1)) > I_LOST_THE_FIGHT_COLOR_BLUE_1  - ERROR_GET_COLOUR_SOME)
        &&
        (int(GetRValue(color2)) < I_LOST_THE_FIGHT_COLOR_RED_2   + ERROR_GET_COLOUR_SOME) &&
        (int(GetRValue(color2)) > I_LOST_THE_FIGHT_COLOR_RED_2   - ERROR_GET_COLOUR_SOME) &&
        (int(GetGValue(color2)) < I_LOST_THE_FIGHT_COLOR_GREEN_2 + ERROR_GET_COLOUR_SOME) &&
        (int(GetGValue(color2)) > I_LOST_THE_FIGHT_COLOR_GREEN_2 - ERROR_GET_COLOUR_SOME) &&
        (int(GetBValue(color2)) < I_LOST_THE_FIGHT_COLOR_BLUE_2  + ERROR_GET_COLOUR_SOME) &&
        (int(GetBValue(color2)) > I_LOST_THE_FIGHT_COLOR_BLUE_2  - ERROR_GET_COLOUR_SOME)
        )
    {
        File::LogFile("I Am defeated!", true);
        ret = true;
    }

    return ret;
}

bool check::IWonTheFight()
{
    bool ret = false;
    //LogFile("Am I defeated? ");

    COLORREF color1 = basicOperations::GetColor(I_WON_THE_FIGHT_POS_X_1, I_WON_THE_FIGHT_POS_Y_1, false);
    COLORREF color2 = basicOperations::GetColor(I_WON_THE_FIGHT_POS_X_2, I_WON_THE_FIGHT_POS_Y_2, false);
    COLORREF color3 = basicOperations::GetColor(I_WON_THE_FIGHT_POS_X_3, I_WON_THE_FIGHT_POS_Y_3, false);

    // It is the desiRED color
    if ((int(GetRValue(color1)) < I_WON_THE_FIGHT_COLOR_RED_1   + ERROR_GET_COLOUR) &&
        (int(GetRValue(color1)) > I_WON_THE_FIGHT_COLOR_RED_1   - ERROR_GET_COLOUR) &&
        (int(GetGValue(color1)) < I_WON_THE_FIGHT_COLOR_GREEN_1 + ERROR_GET_COLOUR) &&
        (int(GetGValue(color1)) > I_WON_THE_FIGHT_COLOR_GREEN_1 - ERROR_GET_COLOUR) &&
        (int(GetBValue(color1)) < I_WON_THE_FIGHT_COLOR_BLUE_1  + ERROR_GET_COLOUR) &&
        (int(GetBValue(color1)) > I_WON_THE_FIGHT_COLOR_BLUE_1  - ERROR_GET_COLOUR)
        &&
        (int(GetRValue(color2)) < I_WON_THE_FIGHT_COLOR_RED_2   + ERROR_GET_COLOUR) &&
        (int(GetRValue(color2)) > I_WON_THE_FIGHT_COLOR_RED_2   - ERROR_GET_COLOUR) &&
        (int(GetGValue(color2)) < I_WON_THE_FIGHT_COLOR_GREEN_2 + ERROR_GET_COLOUR) &&
        (int(GetGValue(color2)) > I_WON_THE_FIGHT_COLOR_GREEN_2 - ERROR_GET_COLOUR) &&
        (int(GetBValue(color2)) < I_WON_THE_FIGHT_COLOR_BLUE_2  + ERROR_GET_COLOUR) &&
        (int(GetBValue(color2)) > I_WON_THE_FIGHT_COLOR_BLUE_2  - ERROR_GET_COLOUR)
        ||
        (int(GetRValue(color3)) < I_WON_THE_FIGHT_COLOR_RED_3   + ERROR_GET_COLOUR_SMALL) &&
        (int(GetRValue(color3)) > I_WON_THE_FIGHT_COLOR_RED_3   - ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color3)) < I_WON_THE_FIGHT_COLOR_GREEN_3 + ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color3)) > I_WON_THE_FIGHT_COLOR_GREEN_3 - ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color3)) < I_WON_THE_FIGHT_COLOR_BLUE_3  + ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color3)) > I_WON_THE_FIGHT_COLOR_BLUE_3  - ERROR_GET_COLOUR_SMALL)
        )
    {
        File::LogFile("I won the fight!", true);
        ret = true;
    }

    return ret;
}

bool check::IsFightFinished()
{
    return IWonTheFight() || AmIDefeated();
}

bool check::IsBlack(int x, int y)
{
    bool ret = false;

    COLORREF color = basicOperations::GetColor(x, y, false);

    // It is the desiRED   color
    if ((int(GetRValue(color)) < BLACK_COLOR_RED   + ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color)) < BLACK_COLOR_GREEN + ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color)) < BLACK_COLOR_BLUE  + ERROR_GET_COLOUR_SMALL))
    {
        //File::LogFile("IS BLACK!", false);
        ret = true;
    }

    return ret;
}

bool check::IsBlackScreen()
{
    return  check::IsBlack(BLACK_SCREEN_POS_X_1, BLACK_SCREEN_POS_Y_1) &&
            check::IsBlack(BLACK_SCREEN_POS_X_2, BLACK_SCREEN_POS_Y_2) &&
            check::IsBlack(BLACK_SCREEN_POS_X_3, BLACK_SCREEN_POS_Y_3) &&
            check::IsBlack(BLACK_SCREEN_POS_X_3, BLACK_SCREEN_POS_Y_4) &&
            check::IsBlack(BLACK_SCREEN_POS_X_3, BLACK_SCREEN_POS_Y_5) &&
            check::IsBlack(BLACK_SCREEN_POS_X_3, BLACK_SCREEN_POS_Y_6) &&
            check::IsBlack(BLACK_SCREEN_POS_X_3, BLACK_SCREEN_POS_Y_7) &&
            check::IsBlack(BLACK_SCREEN_POS_X_4, BLACK_SCREEN_POS_Y_8);
}

/*
bool AmILevelUp()
{
    //std::cout << "Am I LevelUp? " << std::endl;

    bool ret = false;

    COLORREF color1 = GetColor(I_AM_LEVEL_UP_POS_X_1, I_AM_LEVEL_UP_POS_Y_1);
    COLORREF color2 = GetColor(I_AM_LEVEL_UP_POS_X_2, I_AM_LEVEL_UP_POS_Y_2);
    COLORREF color3 = GetColor(I_AM_LEVEL_UP_POS_X_3, I_AM_LEVEL_UP_POS_Y_3);
    COLORREF color4 = GetColor(I_AM_LEVEL_UP_BIG_POS_X_3, I_AM_LEVEL_UP_BIG_POS_Y_3);

    // It is the desiRED   color 
    if ((int(GetRValue(color1)) < I_AM_LEVEL_UP_COLOR_RED_1   + ERROR_GET_COLOUR_SMALL) &&
        (int(GetRValue(color1)) > I_AM_LEVEL_UP_COLOR_RED_1   - ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color1)) < I_AM_LEVEL_UP_COLOR_GREEN_1 + ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color1)) > I_AM_LEVEL_UP_COLOR_GREEN_1 - ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color1)) < I_AM_LEVEL_UP_COLOR_BLUE_1  + ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color1)) > I_AM_LEVEL_UP_COLOR_BLUE_1  - ERROR_GET_COLOUR_SMALL)
        &&
        (int(GetRValue(color2)) < I_AM_LEVEL_UP_COLOR_RED_2   + ERROR_GET_COLOUR_SMALL) &&
        (int(GetRValue(color2)) > I_AM_LEVEL_UP_COLOR_RED_2   - ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color2)) < I_AM_LEVEL_UP_COLOR_GREEN_2 + ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color2)) > I_AM_LEVEL_UP_COLOR_GREEN_2 - ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color2)) < I_AM_LEVEL_UP_COLOR_BLUE_2  + ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color2)) > I_AM_LEVEL_UP_COLOR_BLUE_2  - ERROR_GET_COLOUR_SMALL)
        &&
        ((
        (int(GetRValue(color3)) < I_AM_LEVEL_UP_COLOR_RED_3   + ERROR_GET_COLOUR_SMALL) &&
        (int(GetRValue(color3)) > I_AM_LEVEL_UP_COLOR_RED_3   - ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color3)) < I_AM_LEVEL_UP_COLOR_GREEN_3 + ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color3)) > I_AM_LEVEL_UP_COLOR_GREEN_3 - ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color3)) < I_AM_LEVEL_UP_COLOR_BLUE_3  + ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color3)) > I_AM_LEVEL_UP_COLOR_BLUE_3  - ERROR_GET_COLOUR_SMALL)
        ) || (
        (int(GetRValue(color4)) < I_AM_LEVEL_UP_COLOR_RED_3   + ERROR_GET_COLOUR_SMALL) &&
        (int(GetRValue(color4)) > I_AM_LEVEL_UP_COLOR_RED_3   - ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color4)) < I_AM_LEVEL_UP_COLOR_GREEN_3 + ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color4)) > I_AM_LEVEL_UP_COLOR_GREEN_3 - ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color4)) < I_AM_LEVEL_UP_COLOR_BLUE_3  + ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color4)) > I_AM_LEVEL_UP_COLOR_BLUE_3  - ERROR_GET_COLOUR_SMALL)
        )))
    {
        LogFile("I just level UP!");
        ret = true;
    }

    return ret;
}

bool AmIDead()
{
    //LogFile("Am I dead? ");

    bool ret = false;

    COLORREF color1 = GetColor(AM_I_DEAD_POS_X_1, AM_I_DEAD_POS_Y_1);
    COLORREF color2 = GetColor(AM_I_DEAD_POS_X_2, AM_I_DEAD_POS_Y_2);
    COLORREF color3 = GetColor(AM_I_DEAD_POS_X_3, AM_I_DEAD_POS_Y_3);

    // It is the desiRED   color 
    if ((int(GetRValue(color1)) < AM_I_DEAD_COLOR_RED_1   + ERROR_GET_COLOUR_QUITE) &&
        (int(GetRValue(color1)) > AM_I_DEAD_COLOR_RED_1   - ERROR_GET_COLOUR_QUITE) &&
        (int(GetGValue(color1)) < AM_I_DEAD_COLOR_GREEN_1 + ERROR_GET_COLOUR_QUITE) &&
        (int(GetGValue(color1)) > AM_I_DEAD_COLOR_GREEN_1 - ERROR_GET_COLOUR_QUITE) &&
        (int(GetBValue(color1)) < AM_I_DEAD_COLOR_BLUE_1  + ERROR_GET_COLOUR_QUITE) &&
        (int(GetBValue(color1)) > AM_I_DEAD_COLOR_BLUE_1  - ERROR_GET_COLOUR_QUITE)
        &&
        (int(GetRValue(color2)) < AM_I_DEAD_COLOR_RED_2   + ERROR_GET_COLOUR_QUITE) &&
        (int(GetRValue(color2)) > AM_I_DEAD_COLOR_RED_2   - ERROR_GET_COLOUR_QUITE) &&
        (int(GetGValue(color2)) < AM_I_DEAD_COLOR_GREEN_2 + ERROR_GET_COLOUR_QUITE) &&
        (int(GetGValue(color2)) > AM_I_DEAD_COLOR_GREEN_2 - ERROR_GET_COLOUR_QUITE) &&
        (int(GetBValue(color2)) < AM_I_DEAD_COLOR_BLUE_2  + ERROR_GET_COLOUR_QUITE) &&
        (int(GetBValue(color2)) > AM_I_DEAD_COLOR_BLUE_2  - ERROR_GET_COLOUR_QUITE)
        &&
        (int(GetRValue(color3)) < AM_I_DEAD_COLOR_RED_3   + ERROR_GET_COLOUR_QUITE) &&
        (int(GetRValue(color3)) > AM_I_DEAD_COLOR_RED_3   - ERROR_GET_COLOUR_QUITE) &&
        (int(GetGValue(color3)) < AM_I_DEAD_COLOR_GREEN_3 + ERROR_GET_COLOUR_QUITE) &&
        (int(GetGValue(color3)) > AM_I_DEAD_COLOR_GREEN_3 - ERROR_GET_COLOUR_QUITE) &&
        (int(GetBValue(color3)) < AM_I_DEAD_COLOR_BLUE_3  + ERROR_GET_COLOUR_QUITE) &&
        (int(GetBValue(color3)) > AM_I_DEAD_COLOR_BLUE_3  - ERROR_GET_COLOUR_QUITE))
    {
        LogFile(" Yeah...     am ded");
        ret = true;
    }

    return ret;
}

bool AmITalkingWithNPJ()
{
    bool ret = false;

    if(talking_with_npj_disable_check_) {
        return ret;
    }

    COLORREF color1 = GetColor(NPJ_TALKING_POS_X, NPJ_TALKING_POS_Y_1);
    COLORREF color2 = GetColor(NPJ_TALKING_POS_X, NPJ_TALKING_POS_Y_2);
    COLORREF color3 = GetColor(NPJ_TALKING_POS_X, NPJ_TALKING_POS_Y_3);

    // It is the desiRED   color 
    if ((int(GetRValue(color1)) < GREY_COLOR_RED   + ERROR_GET_COLOUR_SOME) && (int(GetRValue(color1)) > GREY_COLOR_RED   - ERROR_GET_COLOUR_SOME) &&
        (int(GetGValue(color1)) < GREY_COLOR_GREEN + ERROR_GET_COLOUR_SOME) && (int(GetGValue(color1)) > GREY_COLOR_GREEN - ERROR_GET_COLOUR_SOME) &&
        (int(GetBValue(color1)) < GREY_COLOR_BLUE  + ERROR_GET_COLOUR_SOME) && (int(GetBValue(color1)) > GREY_COLOR_BLUE  - ERROR_GET_COLOUR_SOME)
        &&
        (int(GetRValue(color2)) < GREY_COLOR_RED   + ERROR_GET_COLOUR_SOME) && (int(GetRValue(color2)) > GREY_COLOR_RED   - ERROR_GET_COLOUR_SOME) &&
        (int(GetGValue(color2)) < GREY_COLOR_GREEN + ERROR_GET_COLOUR_SOME) && (int(GetGValue(color2)) > GREY_COLOR_GREEN - ERROR_GET_COLOUR_SOME) &&
        (int(GetBValue(color2)) < GREY_COLOR_BLUE  + ERROR_GET_COLOUR_SOME) && (int(GetBValue(color2)) > GREY_COLOR_BLUE  - ERROR_GET_COLOUR_SOME)
        &&
        (int(GetRValue(color3)) < GREY_COLOR_RED   + ERROR_GET_COLOUR_SOME) && (int(GetRValue(color3)) > GREY_COLOR_RED   - ERROR_GET_COLOUR_SOME) &&
        (int(GetGValue(color3)) < GREY_COLOR_GREEN + ERROR_GET_COLOUR_SOME) && (int(GetGValue(color3)) > GREY_COLOR_GREEN - ERROR_GET_COLOUR_SOME) &&
        (int(GetBValue(color3)) < GREY_COLOR_BLUE  + ERROR_GET_COLOUR_SOME) && (int(GetBValue(color3)) > GREY_COLOR_BLUE  - ERROR_GET_COLOUR_SOME)
        )
    {
        ret = true;
        LogFile("Talking with an NPJ");
    }

    color1 = GetColor(NPJ_TALKING_POS_X_2, NPJ_TALKING_POS_Y_2_1);
    color2 = GetColor(NPJ_TALKING_POS_X_2, NPJ_TALKING_POS_Y_2_2);
    color3 = GetColor(NPJ_TALKING_POS_X_2, NPJ_TALKING_POS_Y_2_3);

    // It is the desiRED   color 
    if ((int(GetRValue(color1)) < GREY_COLOR_RED   + ERROR_GET_COLOUR) && (int(GetRValue(color1)) > GREY_COLOR_RED   - ERROR_GET_COLOUR) &&
        (int(GetGValue(color1)) < GREY_COLOR_GREEN + ERROR_GET_COLOUR) && (int(GetGValue(color1)) > GREY_COLOR_GREEN - ERROR_GET_COLOUR) &&
        (int(GetBValue(color1)) < GREY_COLOR_BLUE  + ERROR_GET_COLOUR) && (int(GetBValue(color1)) > GREY_COLOR_BLUE  - ERROR_GET_COLOUR)
        &&
        (int(GetRValue(color2)) < GREY_COLOR_RED   + ERROR_GET_COLOUR) && (int(GetRValue(color2)) > GREY_COLOR_RED   - ERROR_GET_COLOUR) &&
        (int(GetGValue(color2)) < GREY_COLOR_GREEN + ERROR_GET_COLOUR) && (int(GetGValue(color2)) > GREY_COLOR_GREEN - ERROR_GET_COLOUR) &&
        (int(GetBValue(color2)) < GREY_COLOR_BLUE  + ERROR_GET_COLOUR) && (int(GetBValue(color2)) > GREY_COLOR_BLUE  - ERROR_GET_COLOUR)
        &&
        (int(GetRValue(color3)) < GREY_COLOR_RED   + ERROR_GET_COLOUR) && (int(GetRValue(color3)) > GREY_COLOR_RED   - ERROR_GET_COLOUR) &&
        (int(GetGValue(color3)) < GREY_COLOR_GREEN + ERROR_GET_COLOUR) && (int(GetGValue(color3)) > GREY_COLOR_GREEN - ERROR_GET_COLOUR) &&
        (int(GetBValue(color3)) < GREY_COLOR_BLUE  + ERROR_GET_COLOUR) && (int(GetBValue(color3)) > GREY_COLOR_BLUE  - ERROR_GET_COLOUR)
        )
    {
        ret = true;
        LogFile("Talking with NPJ");
    }

    return ret;
}

bool IsMercant()
{
    bool ret = false;
    if(talking_with_npj_disable_check_) {
        return ret;
    }
    //std::cout << "Is Mercant?" << std::endl;

    COLORREF color1 = GetColor(IS_MERCANT_POS_X_1, IS_MERCANT_POS_Y_1);
    COLORREF color2 = GetColor(IS_MERCANT_POS_X_2, IS_MERCANT_POS_Y_2);
    COLORREF color3 = GetColor(IS_MERCANT_POS_X_3, IS_MERCANT_POS_Y_3);

    // It is the desiRED   color 
    if ((int(GetRValue(color1)) < IS_MERCANT_COLOR_RED   + ERROR_GET_COLOUR_SMALL) &&
        (int(GetRValue(color1)) > IS_MERCANT_COLOR_RED   - ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color1)) < IS_MERCANT_COLOR_GREEN + ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color1)) > IS_MERCANT_COLOR_GREEN - ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color1)) < IS_MERCANT_COLOR_BLUE  + ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color1)) > IS_MERCANT_COLOR_BLUE  - ERROR_GET_COLOUR_SMALL)
        &&
        (int(GetRValue(color2)) < IS_MERCANT_COLOR_RED   + ERROR_GET_COLOUR_SMALL) &&
        (int(GetRValue(color2)) > IS_MERCANT_COLOR_RED   - ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color2)) < IS_MERCANT_COLOR_GREEN + ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color2)) > IS_MERCANT_COLOR_GREEN - ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color2)) < IS_MERCANT_COLOR_BLUE  + ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color2)) > IS_MERCANT_COLOR_BLUE  - ERROR_GET_COLOUR_SMALL)
        &&
        (int(GetRValue(color3)) < IS_MERCANT_COLOR_RED   + ERROR_GET_COLOUR_SMALL) &&
        (int(GetRValue(color3)) > IS_MERCANT_COLOR_RED   - ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color3)) < IS_MERCANT_COLOR_GREEN + ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color3)) > IS_MERCANT_COLOR_GREEN - ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color3)) < IS_MERCANT_COLOR_BLUE  + ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color3)) > IS_MERCANT_COLOR_BLUE  - ERROR_GET_COLOUR_SMALL)
        )
    {
        LogFile("Is mercant!");
        ret = true;
    }

    return ret;
}

bool IsMercantMode()
{
    bool ret = false;
    if (talking_with_npj_disable_check_) {
        return ret;
    }

    COLORREF color1 = GetColor(IS_MERCANT_MODE_POS_X_1, IS_MERCANT_MODE_POS_Y_1);
    COLORREF color2 = GetColor(IS_MERCANT_MODE_POS_X_2, IS_MERCANT_MODE_POS_Y_2);
    COLORREF color3 = GetColor(IS_MERCANT_MODE_POS_X_3, IS_MERCANT_MODE_POS_Y_3);

    // It is the desiRED   color 
    if ((int(GetRValue(color1)) < IS_MERCANT_MODE_COLOR_RED   + ERROR_GET_COLOUR_SMALL) &&
        (int(GetRValue(color1)) > IS_MERCANT_MODE_COLOR_RED   - ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color1)) < IS_MERCANT_MODE_COLOR_GREEN + ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color1)) > IS_MERCANT_MODE_COLOR_GREEN - ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color1)) < IS_MERCANT_MODE_COLOR_BLUE  + ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color1)) > IS_MERCANT_MODE_COLOR_BLUE  - ERROR_GET_COLOUR_SMALL)
        &&
        (int(GetRValue(color2)) < IS_MERCANT_MODE_COLOR_RED_AUX   + ERROR_GET_COLOUR_SMALL) &&
        (int(GetRValue(color2)) > IS_MERCANT_MODE_COLOR_RED_AUX   - ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color2)) < IS_MERCANT_MODE_COLOR_GREEN_AUX + ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color2)) > IS_MERCANT_MODE_COLOR_GREEN_AUX - ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color2)) < IS_MERCANT_MODE_COLOR_BLUE_AUX  + ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color2)) > IS_MERCANT_MODE_COLOR_BLUE_AUX  - ERROR_GET_COLOUR_SMALL)
        &&
        (int(GetRValue(color3)) < IS_MERCANT_MODE_COLOR_RED   + ERROR_GET_COLOUR_SMALL) &&
        (int(GetRValue(color3)) > IS_MERCANT_MODE_COLOR_RED   - ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color3)) < IS_MERCANT_MODE_COLOR_GREEN + ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color3)) > IS_MERCANT_MODE_COLOR_GREEN - ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color3)) < IS_MERCANT_MODE_COLOR_BLUE  + ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color3)) > IS_MERCANT_MODE_COLOR_BLUE  - ERROR_GET_COLOUR_SMALL)
        )
    {
        LogFile("Entering mercant mode!");
        ret = true;
    }

    return ret;
}


*/

bool check::IsSpellsMenu()
{
    bool ret = false;

    COLORREF color1 = basicOperations::GetColor(IS_ORANGE_CAC_WEAPON_POS_X_1, IS_ORANGE_CAC_WEAPON_POS_Y_1, false);
    COLORREF color2 = basicOperations::GetColor(IS_ORANGE_CAC_WEAPON_POS_X_2, IS_ORANGE_CAC_WEAPON_POS_Y_2, false);
    COLORREF color3 = basicOperations::GetColor(IS_ORANGE_CAC_WEAPON_POS_X_3, IS_ORANGE_CAC_WEAPON_POS_Y_3, false);

    // If the bottom-rightmost icon is a CaC weapon (has orange). Then the bottom menu is a spells menu.
    if ((int(GetRValue(color1)) < IS_ORANGE_CAC_WEAPON_COLOR_RED    + ERROR_GET_COLOUR_SMALL) &&
        (int(GetRValue(color1)) > IS_ORANGE_CAC_WEAPON_COLOR_RED    - ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color1)) < IS_ORANGE_CAC_WEAPON_COLOR_GREEN  + ERROR_GET_COLOUR_SOME) &&
        (int(GetGValue(color1)) > IS_ORANGE_CAC_WEAPON_COLOR_GREEN  - ERROR_GET_COLOUR_SOME) &&
        (int(GetBValue(color1)) < IS_ORANGE_CAC_WEAPON_COLOR_BLUE   + ERROR_GET_COLOUR) &&
        (int(GetBValue(color1)) > IS_ORANGE_CAC_WEAPON_COLOR_BLUE   - ERROR_GET_COLOUR)
        ||
        (int(GetRValue(color2)) < IS_ORANGE_CAC_WEAPON_COLOR_RED    + ERROR_GET_COLOUR_SMALL) &&
        (int(GetRValue(color2)) > IS_ORANGE_CAC_WEAPON_COLOR_RED    - ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color2)) < IS_ORANGE_CAC_WEAPON_COLOR_GREEN  + ERROR_GET_COLOUR_SOME ) &&
        (int(GetGValue(color2)) > IS_ORANGE_CAC_WEAPON_COLOR_GREEN  - ERROR_GET_COLOUR_SOME ) &&
        (int(GetBValue(color2)) < IS_ORANGE_CAC_WEAPON_COLOR_BLUE   + ERROR_GET_COLOUR) &&
        (int(GetBValue(color2)) > IS_ORANGE_CAC_WEAPON_COLOR_BLUE   - ERROR_GET_COLOUR)
        ||
        (int(GetRValue(color3)) < IS_ORANGE_CAC_WEAPON_COLOR_RED    + ERROR_GET_COLOUR_SMALL) &&
        (int(GetRValue(color3)) > IS_ORANGE_CAC_WEAPON_COLOR_RED    - ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color3)) < IS_ORANGE_CAC_WEAPON_COLOR_GREEN  + ERROR_GET_COLOUR_SOME ) &&
        (int(GetGValue(color3)) > IS_ORANGE_CAC_WEAPON_COLOR_GREEN  - ERROR_GET_COLOUR_SOME ) &&
        (int(GetBValue(color3)) < IS_ORANGE_CAC_WEAPON_COLOR_BLUE   + ERROR_GET_COLOUR) &&
        (int(GetBValue(color3)) > IS_ORANGE_CAC_WEAPON_COLOR_BLUE   - ERROR_GET_COLOUR) )
    {
        File::LogFile("Is the spells menu!", true);
        ret = true;
    }

    return ret;
}

bool check::IsEmptyResource()
{
    bool ret = false;

    COLORREF color1 = basicOperations::GetColor(INVENTARY_CONVERT_RESOURCES_X_4, INVENTARY_CONVERT_RESOURCES_Y_4, true);

    // Check if the first position in the inventary is empty (dark black).
    if ((int(GetRValue(color1)) < INVENTARY_NO_RESOURCES_COLOR_RED    + ERROR_GET_COLOUR_SMALL) &&
        (int(GetRValue(color1)) > INVENTARY_NO_RESOURCES_COLOR_RED    - ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color1)) < INVENTARY_NO_RESOURCES_COLOR_GREEN  + ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color1)) > INVENTARY_NO_RESOURCES_COLOR_GREEN  - ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color1)) < INVENTARY_NO_RESOURCES_COLOR_BLUE   + ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color1)) > INVENTARY_NO_RESOURCES_COLOR_BLUE   - ERROR_GET_COLOUR_SMALL)
        )
    {
        File::LogFile("Inventary empty!", true);
        ret = true;
    }

    return ret;
}
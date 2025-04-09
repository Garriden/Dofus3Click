#include "checks.hpp"

bool check::IsFight()
{
    bool ret = false;

    COLORREF color1  = basicOperations::GetColor(IT_IS_MY_TURN_POS_X_3, IT_IS_MY_TURN_POS_Y_3, false);
    COLORREF color2  = basicOperations::GetColor(IT_IS_MY_TURN_POS_X_4, IT_IS_MY_TURN_POS_Y_4, false);
    COLORREF color11 = basicOperations::GetColor(IT_IS_MY_TURN_BOTTOM_POS_X_1, IT_IS_MY_TURN_BOTTOM_POS_Y_1, false);
    COLORREF color22 = basicOperations::GetColor(IT_IS_MY_TURN_BOTTOM_POS_X_2, IT_IS_MY_TURN_BOTTOM_POS_Y_2, false);

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
        (int(GetBValue(color2)) > IT_IS_MY_TURN_COLOR_BLUE   - ERROR_GET_COLOUR_SMALL) 
        ||
        (int(GetRValue(color11)) < IT_IS_MY_TURN_COLOR_RED    + ERROR_GET_COLOUR_SMALL) &&
        (int(GetRValue(color11)) > IT_IS_MY_TURN_COLOR_RED    - ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color11)) < IT_IS_MY_TURN_COLOR_GREEN  + ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color11)) > IT_IS_MY_TURN_COLOR_GREEN  - ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color11)) < IT_IS_MY_TURN_COLOR_BLUE   + ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color11)) > IT_IS_MY_TURN_COLOR_BLUE   - ERROR_GET_COLOUR_SMALL)
        &&
        (int(GetRValue(color22)) < IT_IS_MY_TURN_COLOR_RED    + ERROR_GET_COLOUR_SMALL) &&
        (int(GetRValue(color22)) > IT_IS_MY_TURN_COLOR_RED    - ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color22)) < IT_IS_MY_TURN_COLOR_GREEN  + ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color22)) > IT_IS_MY_TURN_COLOR_GREEN  - ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color22)) < IT_IS_MY_TURN_COLOR_BLUE   + ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color22)) > IT_IS_MY_TURN_COLOR_BLUE   - ERROR_GET_COLOUR_SMALL) 
        )
    {
        ret = true;
        //File::LogFile("It is my turn!", true);
    }

    return ret;
}

bool check::IsAlmostTheEndOfTheTurn()
{
    bool ret = false;

    //COLORREF color1 = basicOperations::GetColor(IT_IS_MY_TURN_POS_X_4, IT_IS_MY_TURN_POS_Y_4, false);
    //COLORREF color2 = basicOperations::GetColor(IT_IS_MY_TURN_POS_X_3, IT_IS_MY_TURN_POS_Y_3, false);
    COLORREF colorFarest = basicOperations::GetColor(IT_IS_MY_TURN_POS_X_1, IT_IS_MY_TURN_POS_Y_1, false);

    //bool isColor1Orange = false;
    //bool isColor2Orange = false;
    //bool isColor3Orange = false;
    bool iscolorFarestOrange = false;
/*
    // color1 == organe, colorbase != orange. 
    if((int(GetRValue(color1)) < IT_IS_MY_TURN_COLOR_RED    + ERROR_GET_COLOUR_SMALL) &&
       (int(GetRValue(color1)) > IT_IS_MY_TURN_COLOR_RED    - ERROR_GET_COLOUR_SMALL) &&
       (int(GetGValue(color1)) < IT_IS_MY_TURN_COLOR_GREEN  + ERROR_GET_COLOUR_SMALL) &&
       (int(GetGValue(color1)) > IT_IS_MY_TURN_COLOR_GREEN  - ERROR_GET_COLOUR_SMALL) &&
       (int(GetBValue(color1)) < IT_IS_MY_TURN_COLOR_BLUE   + ERROR_GET_COLOUR_SMALL) &&
       (int(GetBValue(color1)) > IT_IS_MY_TURN_COLOR_BLUE   - ERROR_GET_COLOUR_SMALL)) 
       {
            isColor1Orange = true;
            //File::LogFile("Color1 is Orange", true);
       } else {
            //File::LogFile("Color1 is NOT Orange", true);
        }

    if((int(GetRValue(color2)) < IT_IS_MY_TURN_COLOR_RED    + ERROR_GET_COLOUR_SMALL) &&
       (int(GetRValue(color2)) > IT_IS_MY_TURN_COLOR_RED    - ERROR_GET_COLOUR_SMALL) &&
       (int(GetGValue(color2)) < IT_IS_MY_TURN_COLOR_GREEN  + ERROR_GET_COLOUR_SMALL) &&
       (int(GetGValue(color2)) > IT_IS_MY_TURN_COLOR_GREEN  - ERROR_GET_COLOUR_SMALL) &&
       (int(GetBValue(color2)) < IT_IS_MY_TURN_COLOR_BLUE   + ERROR_GET_COLOUR_SMALL) &&
       (int(GetBValue(color2)) > IT_IS_MY_TURN_COLOR_BLUE   - ERROR_GET_COLOUR_SMALL)) 
       {
            isColor2Orange = true;
            //File::LogFile("Color2 is Orange", true);
       } else {
            //File::LogFile("Color2 is NOT Orange", true);
       }
    */
    if((int(GetRValue(colorFarest)) < IT_IS_MY_TURN_COLOR_RED    + ERROR_GET_COLOUR_SMALL) &&
       (int(GetRValue(colorFarest)) > IT_IS_MY_TURN_COLOR_RED    - ERROR_GET_COLOUR_SMALL) &&
       (int(GetGValue(colorFarest)) < IT_IS_MY_TURN_COLOR_GREEN  + ERROR_GET_COLOUR_SMALL) &&
       (int(GetGValue(colorFarest)) > IT_IS_MY_TURN_COLOR_GREEN  - ERROR_GET_COLOUR_SMALL) &&
       (int(GetBValue(colorFarest)) < IT_IS_MY_TURN_COLOR_BLUE   + ERROR_GET_COLOUR_SMALL) &&
       (int(GetBValue(colorFarest)) > IT_IS_MY_TURN_COLOR_BLUE   - ERROR_GET_COLOUR_SMALL) )
        {
            iscolorFarestOrange = true;
            //File::LogFile("colorFarest is Orange", true);
        } else {
            //File::LogFile("colorFarest is NOT Orange", true);
        }

    if(IsFight() && !iscolorFarestOrange) {
        ret = true;
        //File::LogFile("It is almost end of a turn!", true);
    }
    //File::LogFile("---", true);
    return ret;
}

bool check::AmIFull()
{
    bool ret = false;

    COLORREF color  = basicOperations::GetColor(CHECK_PODS_POS_X_1, CHECK_PODS_POS_Y_1, false);
    COLORREF color2 = basicOperations::GetColor(CHECK_PODS_POS_X_2, CHECK_PODS_POS_Y_2, false);

    if ((int(GetRValue(color)) < CHECK_PODS_COLOR_RED   + ERROR_GET_COLOUR_QUITE) &&
        (int(GetRValue(color)) > CHECK_PODS_COLOR_RED   - ERROR_GET_COLOUR_QUITE) &&
        (int(GetGValue(color)) < CHECK_PODS_COLOR_GREEN + ERROR_GET_COLOUR_QUITE) &&
        (int(GetGValue(color)) > CHECK_PODS_COLOR_GREEN - ERROR_GET_COLOUR_QUITE) &&
        (int(GetBValue(color)) < CHECK_PODS_COLOR_BLUE  + ERROR_GET_COLOUR_QUITE) &&
        (int(GetBValue(color)) > CHECK_PODS_COLOR_BLUE  - ERROR_GET_COLOUR_QUITE)
        ||
        (int(GetRValue(color2)) < CHECK_PODS_COLOR_RED   + ERROR_GET_COLOUR_QUITE) &&
        (int(GetRValue(color2)) > CHECK_PODS_COLOR_RED   - ERROR_GET_COLOUR_QUITE) &&
        (int(GetGValue(color2)) < CHECK_PODS_COLOR_GREEN + ERROR_GET_COLOUR_QUITE) &&
        (int(GetGValue(color2)) > CHECK_PODS_COLOR_GREEN - ERROR_GET_COLOUR_QUITE) &&
        (int(GetBValue(color2)) < CHECK_PODS_COLOR_BLUE  + ERROR_GET_COLOUR_QUITE) &&
        (int(GetBValue(color2)) > CHECK_PODS_COLOR_BLUE  - ERROR_GET_COLOUR_QUITE)
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

    COLORREF colorHealth  = basicOperations::GetColor(HEALTH_POS_X, HEALTH_POS_Y, false);
    COLORREF colorHealth2 = basicOperations::GetColor(HEALTH_POS_X_2, HEALTH_POS_Y_2, false);

    if(((int(GetRValue(colorHealth)) < HEALTH_COLOR_RED   + ERROR_GET_COLOUR_QUITE) &&
        (int(GetRValue(colorHealth)) > HEALTH_COLOR_RED   - ERROR_GET_COLOUR_QUITE) &&
        (int(GetGValue(colorHealth)) < HEALTH_COLOR_GREEN + ERROR_GET_COLOUR_QUITE) &&
        (int(GetGValue(colorHealth)) > HEALTH_COLOR_GREEN - ERROR_GET_COLOUR_QUITE) &&
        (int(GetBValue(colorHealth)) < HEALTH_COLOR_BLUE  + ERROR_GET_COLOUR_QUITE) &&
        (int(GetBValue(colorHealth)) > HEALTH_COLOR_BLUE  - ERROR_GET_COLOUR_QUITE))
        ||
       ((int(GetRValue(colorHealth2)) < HEALTH_COLOR_RED_2   + ERROR_GET_COLOUR_QUITE) &&
        (int(GetRValue(colorHealth2)) > HEALTH_COLOR_RED_2   - ERROR_GET_COLOUR_QUITE) &&
        (int(GetGValue(colorHealth2)) < HEALTH_COLOR_GREEN_2 + ERROR_GET_COLOUR_QUITE) &&
        (int(GetGValue(colorHealth2)) > HEALTH_COLOR_GREEN_2 - ERROR_GET_COLOUR_QUITE) &&
        (int(GetBValue(colorHealth2)) < HEALTH_COLOR_BLUE_2  + ERROR_GET_COLOUR_QUITE) &&
        (int(GetBValue(colorHealth2)) > HEALTH_COLOR_BLUE_2  - ERROR_GET_COLOUR_QUITE))
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

bool check::IsRecallPoti()
{
    bool ret = false;

    COLORREF color1 = basicOperations::GetColor(RECALL_POTI_POS_X_1, RECALL_POTI_POS_Y_1, false);
    COLORREF color2 = basicOperations::GetColor(RECALL_POTI_POS_X_2, RECALL_POTI_POS_Y_2, false);

    if ((int(GetRValue(color1)) < RECALL_POTI_COLOR_RED_1   + ERROR_GET_COLOUR) &&
        (int(GetRValue(color1)) > RECALL_POTI_COLOR_RED_1   - ERROR_GET_COLOUR) &&
        (int(GetGValue(color1)) < RECALL_POTI_COLOR_GREEN_1 + ERROR_GET_COLOUR) &&
        (int(GetGValue(color1)) > RECALL_POTI_COLOR_GREEN_1 - ERROR_GET_COLOUR) &&
        (int(GetBValue(color1)) < RECALL_POTI_COLOR_BLUE_1  + ERROR_GET_COLOUR) &&
        (int(GetBValue(color1)) > RECALL_POTI_COLOR_BLUE_1  - ERROR_GET_COLOUR)
        &&
        (int(GetRValue(color2)) < RECALL_POTI_COLOR_RED_2   + ERROR_GET_COLOUR) &&
        (int(GetRValue(color2)) > RECALL_POTI_COLOR_RED_2   - ERROR_GET_COLOUR) &&
        (int(GetGValue(color2)) < RECALL_POTI_COLOR_GREEN_2 + ERROR_GET_COLOUR) &&
        (int(GetGValue(color2)) > RECALL_POTI_COLOR_GREEN_2 - ERROR_GET_COLOUR) &&
        (int(GetBValue(color2)) < RECALL_POTI_COLOR_BLUE_2  + ERROR_GET_COLOUR) &&
        (int(GetBValue(color2)) > RECALL_POTI_COLOR_BLUE_2  - ERROR_GET_COLOUR)
        )
    {
        ret = true;
        //File::LogFile("Recall Poti found!", true);
    }

    return ret;
}

/*
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
*/
bool check::IsMenuPrincipalBox()
{
    bool ret = false;

    COLORREF color1 = basicOperations::GetColor(IS_MENU_PRINCIPAL_POS_X_1, IS_MENU_PRINCIPAL_POS_Y_1, false);
    COLORREF color2 = basicOperations::GetColor(IS_MENU_PRINCIPAL_POS_X_2, IS_MENU_PRINCIPAL_POS_Y_2, false);
    COLORREF color3 = basicOperations::GetColor(IS_MENU_PRINCIPAL_POS_X_3, IS_MENU_PRINCIPAL_POS_Y_3, false);

    if ((int(GetRValue(color1)) < IS_MENU_PRINCIPAL_RED_1   + ERROR_GET_COLOUR_SMALL) &&
        (int(GetRValue(color1)) > IS_MENU_PRINCIPAL_RED_1   - ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color1)) < IS_MENU_PRINCIPAL_GREEN_1 + ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color1)) > IS_MENU_PRINCIPAL_GREEN_1 - ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color1)) < IS_MENU_PRINCIPAL_BLUE_1  + ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color1)) > IS_MENU_PRINCIPAL_BLUE_1  - ERROR_GET_COLOUR_SMALL)
        &&
        (int(GetRValue(color2)) < IS_MENU_PRINCIPAL_RED_2   + ERROR_GET_COLOUR_SMALL) &&
        (int(GetRValue(color2)) > IS_MENU_PRINCIPAL_RED_2   - ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color2)) < IS_MENU_PRINCIPAL_GREEN_2 + ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color2)) > IS_MENU_PRINCIPAL_GREEN_2 - ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color2)) < IS_MENU_PRINCIPAL_BLUE_2  + ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color2)) > IS_MENU_PRINCIPAL_BLUE_2  - ERROR_GET_COLOUR_SMALL)
        &&
        (int(GetRValue(color3)) < IS_MENU_PRINCIPAL_RED_3   + ERROR_GET_COLOUR_SMALL) &&
        (int(GetRValue(color3)) > IS_MENU_PRINCIPAL_RED_3   - ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color3)) < IS_MENU_PRINCIPAL_GREEN_3 + ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color3)) > IS_MENU_PRINCIPAL_GREEN_3 - ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color3)) < IS_MENU_PRINCIPAL_BLUE_3  + ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color3)) > IS_MENU_PRINCIPAL_BLUE_3  - ERROR_GET_COLOUR_SMALL)
        )
    {
        File::LogFile("Is the menu principal window!", true);
        ret = true;
    }

    return ret;
 }

bool check::AmIDefeated()
{
    bool ret = false;
    //LogFile("Am I defeated? ");

    COLORREF color1 = basicOperations::GetColor(I_LOST_THE_FIGHT_POS_X_1, I_LOST_THE_FIGHT_POS_Y_1, false);
    COLORREF color2 = basicOperations::GetColor(I_LOST_THE_FIGHT_POS_X_2, I_LOST_THE_FIGHT_POS_Y_2, false);
    COLORREF color3 = basicOperations::GetColor(LOW_ENERGY_BOX_POS_X_1, LOW_ENERGY_BOX_POS_Y_1, false);
    COLORREF color4 = basicOperations::GetColor(LOW_ENERGY_BOX_POS_X_2, LOW_ENERGY_BOX_POS_Y_2, false);

    // It is the desired color 
    if(((int(GetRValue(color1)) < I_LOST_THE_FIGHT_COLOR_RED_1   + ERROR_GET_COLOUR_SOME) &&
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
        (int(GetBValue(color2)) > I_LOST_THE_FIGHT_COLOR_BLUE_2  - ERROR_GET_COLOUR_SOME))
        ||
       ((int(GetRValue(color3)) < LOW_ENERGY_BOX_COLOR_RED_1   + ERROR_GET_COLOUR_SMALL) &&
        (int(GetRValue(color3)) > LOW_ENERGY_BOX_COLOR_RED_1   - ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color3)) < LOW_ENERGY_BOX_COLOR_GREEN_1 + ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color3)) > LOW_ENERGY_BOX_COLOR_GREEN_1 - ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color3)) < LOW_ENERGY_BOX_COLOR_BLUE_1  + ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color3)) > LOW_ENERGY_BOX_COLOR_BLUE_1  - ERROR_GET_COLOUR_SMALL)
        &&
        (int(GetRValue(color4)) < LOW_ENERGY_BOX_COLOR_RED_2   + ERROR_GET_COLOUR_SMALL) &&
        (int(GetRValue(color4)) > LOW_ENERGY_BOX_COLOR_RED_2   - ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color4)) < LOW_ENERGY_BOX_COLOR_GREEN_2 + ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color4)) > LOW_ENERGY_BOX_COLOR_GREEN_2 - ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color4)) < LOW_ENERGY_BOX_COLOR_BLUE_2  + ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color4)) > LOW_ENERGY_BOX_COLOR_BLUE_2  - ERROR_GET_COLOUR_SMALL))
        )
    {
        File::LogFile("I Am defeated!", true);
        ret = true;
    }

    return ret;
}

bool check::IsFenixBox()
{
    bool ret = false;

    COLORREF color1 = basicOperations::GetColor(FENIX_BOX_POS_X_1, FENIX_BOX_POS_Y_1, false);
    COLORREF color2 = basicOperations::GetColor(FENIX_BOX_POS_X_2, FENIX_BOX_POS_Y_2, false);
    COLORREF color3 = basicOperations::GetColor(FENIX_BOX_POS_X_3, FENIX_BOX_POS_Y_3, false);

    // It is the desired color 
    if( (int(GetRValue(color1)) < FENIX_BOX_COLOR_RED_1   + ERROR_GET_COLOUR_SMALL) &&
        (int(GetRValue(color1)) > FENIX_BOX_COLOR_RED_1   - ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color1)) < FENIX_BOX_COLOR_GREEN_1 + ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color1)) > FENIX_BOX_COLOR_GREEN_1 - ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color1)) < FENIX_BOX_COLOR_BLUE_1  + ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color1)) > FENIX_BOX_COLOR_BLUE_1  - ERROR_GET_COLOUR_SMALL)
        &&
        (int(GetRValue(color2)) < FENIX_BOX_COLOR_RED_2   + ERROR_GET_COLOUR_SMALL) &&
        (int(GetRValue(color2)) > FENIX_BOX_COLOR_RED_2   - ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color2)) < FENIX_BOX_COLOR_GREEN_2 + ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color2)) > FENIX_BOX_COLOR_GREEN_2 - ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color2)) < FENIX_BOX_COLOR_BLUE_2  + ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color2)) > FENIX_BOX_COLOR_BLUE_2  - ERROR_GET_COLOUR_SMALL)
        &&
        (int(GetRValue(color3)) < FENIX_BOX_COLOR_RED_3   + ERROR_GET_COLOUR) &&
        (int(GetRValue(color3)) > FENIX_BOX_COLOR_RED_3   - ERROR_GET_COLOUR) &&
        (int(GetGValue(color3)) < FENIX_BOX_COLOR_GREEN_3 + ERROR_GET_COLOUR) &&
        (int(GetGValue(color3)) > FENIX_BOX_COLOR_GREEN_3 - ERROR_GET_COLOUR) &&
        (int(GetBValue(color3)) < FENIX_BOX_COLOR_BLUE_3  + ERROR_GET_COLOUR) &&
        (int(GetBValue(color3)) > FENIX_BOX_COLOR_BLUE_3  - ERROR_GET_COLOUR)
        )
    {
        File::LogFile("I Am a ghost, Fenix message!", true);
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
    return IWonTheFight() || IsFenixBox() || AmIDefeated() || AmILevelUp();
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


bool check::AmILevelUp()
{
    //std::cout << "Am I LevelUp? " << std::endl;

    bool ret = false;

    COLORREF color1 = basicOperations::GetColor(I_AM_LEVEL_UP_POS_X_1, I_AM_LEVEL_UP_POS_Y_1, false);
    COLORREF color2 = basicOperations::GetColor(I_AM_LEVEL_UP_POS_X_2, I_AM_LEVEL_UP_POS_Y_2, false);
    COLORREF color3 = basicOperations::GetColor(I_AM_LEVEL_UP_POS_X_3, I_AM_LEVEL_UP_POS_Y_3, false);
    COLORREF color4 = basicOperations::GetColor(I_AM_LEVEL_UP_BIG_POS_X_3, I_AM_LEVEL_UP_BIG_POS_Y_3, false);

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
        File::LogFile("I just level UP!", true);
        ret = true;
    }

    return ret;
}
/*

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
        //File::LogFile("Is the spells menu!", true);
        return true;
    }

    color1 = basicOperations::GetColor(IS_SIT_POS_X_1, IS_SIT_POS_Y_1, false);
    color2 = basicOperations::GetColor(IS_SIT_POS_X_2, IS_SIT_POS_Y_2, false);

    // If the second icon on the bottom bar is sit emote. Then the bottom menu is a object menu.
    if ((int(GetRValue(color1)) < IS_SIT_COLOR_RED_1    + ERROR_GET_COLOUR_SMALL) &&
        (int(GetRValue(color1)) > IS_SIT_COLOR_RED_1    - ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color1)) < IS_SIT_COLOR_GREEN_1  + ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color1)) > IS_SIT_COLOR_GREEN_1  - ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color1)) < IS_SIT_COLOR_BLUE_1   + ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color1)) > IS_SIT_COLOR_BLUE_1   - ERROR_GET_COLOUR_SMALL)
        ||
        (int(GetRValue(color2)) < IS_SIT_COLOR_RED_2    + ERROR_GET_COLOUR_SMALL) &&
        (int(GetRValue(color2)) > IS_SIT_COLOR_RED_2    - ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color2)) < IS_SIT_COLOR_GREEN_2  + ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color2)) > IS_SIT_COLOR_GREEN_2  - ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color2)) < IS_SIT_COLOR_BLUE_2   + ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color2)) > IS_SIT_COLOR_BLUE_2   - ERROR_GET_COLOUR_SMALL) )
    {
        //File::LogFile("sit icon found, is objects menu!", true);
        return false;
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


bool check::WaitMapToChange()
{
    int blackScreenFlag = false;
    for(int ii = 0; ii < 500; ++ii) {
        if(!blackScreenFlag) { // No black screen yet, keep trying until black screen detected.
            if(IsBlackScreen()) {
                blackScreenFlag = true;
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
            }
        } else { //blackScreen detected.
            if(!IsBlackScreen()) { // detect black screen + black fade off.
                //File::LogFile("Backscreen transition detected!", false);
                return true;
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
    return false;
}
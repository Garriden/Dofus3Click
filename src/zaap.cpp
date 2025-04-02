#include "zaap.hpp"
#include "utils.hpp"
#include "basicOperations.hpp"
#include "system/file.hpp"
#include "system/inputs.hpp"

void zaap::ClickZaap(std::string zaapName)
{
    std::this_thread::sleep_for(std::chrono::seconds(8));

    int retriesClickZaap = 0;
    while(!CheckZaapInterface() && retriesClickZaap++ < 10) {
    
        // Press the Zaap
        inputs::Click(ASTRUB_ZAAP_POS_X - retriesClickZaap, ASTRUB_ZAAP_POS_Y + retriesClickZaap);

        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    // Click Zaap tab.
    inputs::Click(ZAAP_INTERFACE_POS_X, ZAAP_INTERFACE_POS_Y);
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // Click Zaap writting space.
    inputs::Click(ZAAP_INTERFACE_WRITE_POS_X, ZAAP_INTERFACE_WRITE_POS_Y);
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // Write desired Zaap name
    inputs::KeyboardWrite(zaapName);
    std::this_thread::sleep_for(std::chrono::seconds(1));

    inputs::PressEnter();
    std::this_thread::sleep_for(std::chrono::seconds(5));
}

bool zaap::CheckZaapInterface()
{
    bool ret = false;

    COLORREF color1 = basicOperations::GetColor(ZAAP_INTERFACE_POS_X, ZAAP_INTERFACE_POS_Y, true);

    if ((int(GetRValue(color1)) < ZAAP_INTERFACE_COLOR_RED_1   + ERROR_GET_COLOUR_SMALL) &&
        (int(GetRValue(color1)) > ZAAP_INTERFACE_COLOR_RED_1   - ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color1)) < ZAAP_INTERFACE_COLOR_GREEN_1 + ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color1)) > ZAAP_INTERFACE_COLOR_GREEN_1 - ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color1)) < ZAAP_INTERFACE_COLOR_BLUE_1  + ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color1)) > ZAAP_INTERFACE_COLOR_BLUE_1  - ERROR_GET_COLOUR_SMALL) )
    {
        File::LogFile("I am in the zaap interface.", true);
        ret = true;
    }

    std::this_thread::sleep_for(std::chrono::seconds(1));

    return ret;
}


bool zaap::CheckZaapAstrub()
{
    bool ret = false;

    COLORREF color1 = basicOperations::GetColor(I_AM_IN_ASTRUB_ZAAP_POS_X_1, I_AM_IN_ASTRUB_ZAAP_POS_Y_1, true);
    COLORREF color2 = basicOperations::GetColor(I_AM_IN_ASTRUB_ZAAP_POS_X_2, I_AM_IN_ASTRUB_ZAAP_POS_Y_2, true);
    COLORREF color3 = basicOperations::GetColor(I_AM_IN_ASTRUB_ZAAP_POS_X_3, I_AM_IN_ASTRUB_ZAAP_POS_Y_3, true);

    if ((int(GetRValue(color1)) < I_AM_IN_ASTRUB_ZAAP_COLOR_RED_1   + ERROR_GET_COLOUR_SMALL) &&
        (int(GetRValue(color1)) > I_AM_IN_ASTRUB_ZAAP_COLOR_RED_1   - ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color1)) < I_AM_IN_ASTRUB_ZAAP_COLOR_GREEN_1 + ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color1)) > I_AM_IN_ASTRUB_ZAAP_COLOR_GREEN_1 - ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color1)) < I_AM_IN_ASTRUB_ZAAP_COLOR_BLUE_1  + ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color1)) > I_AM_IN_ASTRUB_ZAAP_COLOR_BLUE_1  - ERROR_GET_COLOUR_SMALL)
        &&
        (int(GetRValue(color2)) < I_AM_IN_ASTRUB_ZAAP_COLOR_RED_2   + ERROR_GET_COLOUR_SMALL) &&
        (int(GetRValue(color2)) > I_AM_IN_ASTRUB_ZAAP_COLOR_RED_2   - ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color2)) < I_AM_IN_ASTRUB_ZAAP_COLOR_GREEN_2 + ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color2)) > I_AM_IN_ASTRUB_ZAAP_COLOR_GREEN_2 - ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color2)) < I_AM_IN_ASTRUB_ZAAP_COLOR_BLUE_2  + ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color2)) > I_AM_IN_ASTRUB_ZAAP_COLOR_BLUE_2  - ERROR_GET_COLOUR_SMALL)
        &&
        (int(GetRValue(color3)) < I_AM_IN_ASTRUB_ZAAP_COLOR_RED_3   + ERROR_GET_COLOUR_SMALL) &&
        (int(GetRValue(color3)) > I_AM_IN_ASTRUB_ZAAP_COLOR_RED_3   - ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color3)) < I_AM_IN_ASTRUB_ZAAP_COLOR_GREEN_3 + ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color3)) > I_AM_IN_ASTRUB_ZAAP_COLOR_GREEN_3 - ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color3)) < I_AM_IN_ASTRUB_ZAAP_COLOR_BLUE_3  + ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color3)) > I_AM_IN_ASTRUB_ZAAP_COLOR_BLUE_3  - ERROR_GET_COLOUR_SMALL)
        )
    {
        File::LogFile("I am in Astrub Zaap!", true);
        ret = true;
    }

    std::this_thread::sleep_for(std::chrono::seconds(1));

    return ret;
}

bool zaap::CheckZaapLinde()
{
    bool ret = false;
    File::LogFile("Is Linde Zaap ?", true);

    COLORREF color1 = basicOperations::GetColor(I_AM_IN_LINDE_ZAAP_POS_X_1, I_AM_IN_LINDE_ZAAP_POS_Y_1, false);
    COLORREF color2 = basicOperations::GetColor(I_AM_IN_LINDE_ZAAP_POS_X_2, I_AM_IN_LINDE_ZAAP_POS_Y_2, false);
    COLORREF color3 = basicOperations::GetColor(I_AM_IN_LINDE_ZAAP_POS_X_3, I_AM_IN_LINDE_ZAAP_POS_Y_3, false);

    if ((int(GetRValue(color1)) < I_AM_IN_LINDE_ZAAP_COLOR_RED_1   + ERROR_GET_COLOUR_SMALL) &&
        (int(GetRValue(color1)) > I_AM_IN_LINDE_ZAAP_COLOR_RED_1   - ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color1)) < I_AM_IN_LINDE_ZAAP_COLOR_GREEN_1 + ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color1)) > I_AM_IN_LINDE_ZAAP_COLOR_GREEN_1 - ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color1)) < I_AM_IN_LINDE_ZAAP_COLOR_BLUE_1  + ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color1)) > I_AM_IN_LINDE_ZAAP_COLOR_BLUE_1  - ERROR_GET_COLOUR_SMALL)
        &&
        (int(GetRValue(color2)) < I_AM_IN_LINDE_ZAAP_COLOR_RED_2   + ERROR_GET_COLOUR_SMALL) &&
        (int(GetRValue(color2)) > I_AM_IN_LINDE_ZAAP_COLOR_RED_2   - ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color2)) < I_AM_IN_LINDE_ZAAP_COLOR_GREEN_2 + ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color2)) > I_AM_IN_LINDE_ZAAP_COLOR_GREEN_2 - ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color2)) < I_AM_IN_LINDE_ZAAP_COLOR_BLUE_2  + ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color2)) > I_AM_IN_LINDE_ZAAP_COLOR_BLUE_2  - ERROR_GET_COLOUR_SMALL)
        &&
        (int(GetRValue(color3)) < I_AM_IN_LINDE_ZAAP_COLOR_RED_3   + ERROR_GET_COLOUR_SMALL) &&
        (int(GetRValue(color3)) > I_AM_IN_LINDE_ZAAP_COLOR_RED_3   - ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color3)) < I_AM_IN_LINDE_ZAAP_COLOR_GREEN_3 + ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color3)) > I_AM_IN_LINDE_ZAAP_COLOR_GREEN_3 - ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color3)) < I_AM_IN_LINDE_ZAAP_COLOR_BLUE_3  + ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color3)) > I_AM_IN_LINDE_ZAAP_COLOR_BLUE_3  - ERROR_GET_COLOUR_SMALL)
        )
    {
        File::LogFile("I am in Linde Zaap!", true);
        ret = true;
    }

    return ret;
}
/*
bool CheckZaapOtoCoast()
{
	bool ret = false;
	//LogFile("CheckZaap Otomai Coast?");

	COLORREF color1 = GetColor(I_AM_IN_OTO_COAST_ZAAP_POS_X_1, I_AM_IN_OTO_COAST_ZAAP_POS_Y_1);
	COLORREF color2 = GetColor(I_AM_IN_OTO_COAST_ZAAP_POS_X_2, I_AM_IN_OTO_COAST_ZAAP_POS_Y_2);
	COLORREF color3 = GetColor(I_AM_IN_OTO_COAST_ZAAP_POS_X_3, I_AM_IN_OTO_COAST_ZAAP_POS_Y_3);

	if ((int(GetRValue(color1)) < I_AM_IN_OTO_COAST_ZAAP_COLOR_RED_1   + ERROR_GET_COLOUR_SMALL) &&
		(int(GetRValue(color1)) > I_AM_IN_OTO_COAST_ZAAP_COLOR_RED_1   - ERROR_GET_COLOUR_SMALL) &&
		(int(GetGValue(color1)) < I_AM_IN_OTO_COAST_ZAAP_COLOR_GREEN_1 + ERROR_GET_COLOUR_SMALL) &&
		(int(GetGValue(color1)) > I_AM_IN_OTO_COAST_ZAAP_COLOR_GREEN_1 - ERROR_GET_COLOUR_SMALL) &&
		(int(GetBValue(color1)) < I_AM_IN_OTO_COAST_ZAAP_COLOR_BLUE_1  + ERROR_GET_COLOUR_SMALL) &&
		(int(GetBValue(color1)) > I_AM_IN_OTO_COAST_ZAAP_COLOR_BLUE_1  - ERROR_GET_COLOUR_SMALL)
		&&
		(int(GetRValue(color2)) < I_AM_IN_OTO_COAST_ZAAP_COLOR_RED_2   + ERROR_GET_COLOUR_SMALL) &&
		(int(GetRValue(color2)) > I_AM_IN_OTO_COAST_ZAAP_COLOR_RED_2   - ERROR_GET_COLOUR_SMALL) &&
		(int(GetGValue(color2)) < I_AM_IN_OTO_COAST_ZAAP_COLOR_GREEN_2 + ERROR_GET_COLOUR_SMALL) &&
		(int(GetGValue(color2)) > I_AM_IN_OTO_COAST_ZAAP_COLOR_GREEN_2 - ERROR_GET_COLOUR_SMALL) &&
		(int(GetBValue(color2)) < I_AM_IN_OTO_COAST_ZAAP_COLOR_BLUE_2  + ERROR_GET_COLOUR_SMALL) &&
		(int(GetBValue(color2)) > I_AM_IN_OTO_COAST_ZAAP_COLOR_BLUE_2  - ERROR_GET_COLOUR_SMALL)
		&&
		(int(GetRValue(color3)) < I_AM_IN_OTO_COAST_ZAAP_COLOR_RED_3   + ERROR_GET_COLOUR_SMALL) &&
		(int(GetRValue(color3)) > I_AM_IN_OTO_COAST_ZAAP_COLOR_RED_3   - ERROR_GET_COLOUR_SMALL) &&
		(int(GetGValue(color3)) < I_AM_IN_OTO_COAST_ZAAP_COLOR_GREEN_3 + ERROR_GET_COLOUR_SMALL) &&
		(int(GetGValue(color3)) > I_AM_IN_OTO_COAST_ZAAP_COLOR_GREEN_3 - ERROR_GET_COLOUR_SMALL) &&
		(int(GetBValue(color3)) < I_AM_IN_OTO_COAST_ZAAP_COLOR_BLUE_3  + ERROR_GET_COLOUR_SMALL) &&
		(int(GetBValue(color3)) > I_AM_IN_OTO_COAST_ZAAP_COLOR_BLUE_3  - ERROR_GET_COLOUR_SMALL)
		)
	{
		LogFile("I'm in Otomai Coast Zaap ! ALL OK!!");
		ret = true;
	}

	return ret;
}

bool CheckZaapKoalak()
{
	bool ret = false;
	//LogFile("CheckZaap Koalak Breeder Village?");

	COLORREF color1 = GetColor(I_AM_IN_KOALAK_ZAAP_POS_X_1, I_AM_IN_KOALAK_ZAAP_POS_Y_1);
	COLORREF color2 = GetColor(I_AM_IN_KOALAK_ZAAP_POS_X_2, I_AM_IN_KOALAK_ZAAP_POS_Y_2);
	COLORREF color3 = GetColor(I_AM_IN_KOALAK_ZAAP_POS_X_3, I_AM_IN_KOALAK_ZAAP_POS_Y_3);

	if ((int(GetRValue(color1)) < I_AM_IN_KOALAK_ZAAP_COLOR_RED_1   + ERROR_GET_COLOUR_SMALL) &&
		(int(GetRValue(color1)) > I_AM_IN_KOALAK_ZAAP_COLOR_RED_1   - ERROR_GET_COLOUR_SMALL) &&
		(int(GetGValue(color1)) < I_AM_IN_KOALAK_ZAAP_COLOR_GREEN_1 + ERROR_GET_COLOUR_SMALL) &&
		(int(GetGValue(color1)) > I_AM_IN_KOALAK_ZAAP_COLOR_GREEN_1 - ERROR_GET_COLOUR_SMALL) &&
		(int(GetBValue(color1)) < I_AM_IN_KOALAK_ZAAP_COLOR_BLUE_1  + ERROR_GET_COLOUR_SMALL) &&
		(int(GetBValue(color1)) > I_AM_IN_KOALAK_ZAAP_COLOR_BLUE_1  - ERROR_GET_COLOUR_SMALL)
		&&
		(int(GetRValue(color2)) < I_AM_IN_KOALAK_ZAAP_COLOR_RED_2   + ERROR_GET_COLOUR_SMALL) &&
		(int(GetRValue(color2)) > I_AM_IN_KOALAK_ZAAP_COLOR_RED_2   - ERROR_GET_COLOUR_SMALL) &&
		(int(GetGValue(color2)) < I_AM_IN_KOALAK_ZAAP_COLOR_GREEN_2 + ERROR_GET_COLOUR_SMALL) &&
		(int(GetGValue(color2)) > I_AM_IN_KOALAK_ZAAP_COLOR_GREEN_2 - ERROR_GET_COLOUR_SMALL) &&
		(int(GetBValue(color2)) < I_AM_IN_KOALAK_ZAAP_COLOR_BLUE_2  + ERROR_GET_COLOUR_SMALL) &&
		(int(GetBValue(color2)) > I_AM_IN_KOALAK_ZAAP_COLOR_BLUE_2  - ERROR_GET_COLOUR_SMALL)
		&&
		(int(GetRValue(color3)) < I_AM_IN_KOALAK_ZAAP_COLOR_RED_3   + ERROR_GET_COLOUR_SMALL) &&
		(int(GetRValue(color3)) > I_AM_IN_KOALAK_ZAAP_COLOR_RED_3   - ERROR_GET_COLOUR_SMALL) &&
		(int(GetGValue(color3)) < I_AM_IN_KOALAK_ZAAP_COLOR_GREEN_3 + ERROR_GET_COLOUR_SMALL) &&
		(int(GetGValue(color3)) > I_AM_IN_KOALAK_ZAAP_COLOR_GREEN_3 - ERROR_GET_COLOUR_SMALL) &&
		(int(GetBValue(color3)) < I_AM_IN_KOALAK_ZAAP_COLOR_BLUE_3  + ERROR_GET_COLOUR_SMALL) &&
		(int(GetBValue(color3)) > I_AM_IN_KOALAK_ZAAP_COLOR_BLUE_3  - ERROR_GET_COLOUR_SMALL)
		)
	{
		LogFile("I'm in Koalak Zaap ! ALL OK!!");
		ret = true;
	}

	return ret;
}
*/
bool zaap::CheckZaapPuerkazos()
{
    bool ret = false;
    File::LogFile("CheckZaap Pig plains ?", true);

    COLORREF color1 = basicOperations::GetColor(I_AM_IN_PUERKAZOS_ZAAP_POS_X_1, I_AM_IN_PUERKAZOS_ZAAP_POS_Y_1, true);
    COLORREF color2 = basicOperations::GetColor(I_AM_IN_PUERKAZOS_ZAAP_POS_X_2, I_AM_IN_PUERKAZOS_ZAAP_POS_Y_2, true);
    COLORREF color3 = basicOperations::GetColor(I_AM_IN_PUERKAZOS_ZAAP_POS_X_3, I_AM_IN_PUERKAZOS_ZAAP_POS_Y_3, true);

    if ((int(GetRValue(color1)) < I_AM_IN_PUERKAZOS_ZAAP_COLOR_RED_1   + ERROR_GET_COLOUR_SMALL) &&
        (int(GetRValue(color1)) > I_AM_IN_PUERKAZOS_ZAAP_COLOR_RED_1   - ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color1)) < I_AM_IN_PUERKAZOS_ZAAP_COLOR_GREEN_1 + ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color1)) > I_AM_IN_PUERKAZOS_ZAAP_COLOR_GREEN_1 - ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color1)) < I_AM_IN_PUERKAZOS_ZAAP_COLOR_BLUE_1  + ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color1)) > I_AM_IN_PUERKAZOS_ZAAP_COLOR_BLUE_1  - ERROR_GET_COLOUR_SMALL)
            &&
        (int(GetRValue(color2)) < I_AM_IN_PUERKAZOS_ZAAP_COLOR_RED_2   + ERROR_GET_COLOUR_SMALL) &&
        (int(GetRValue(color2)) > I_AM_IN_PUERKAZOS_ZAAP_COLOR_RED_2   - ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color2)) < I_AM_IN_PUERKAZOS_ZAAP_COLOR_GREEN_2 + ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color2)) > I_AM_IN_PUERKAZOS_ZAAP_COLOR_GREEN_2 - ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color2)) < I_AM_IN_PUERKAZOS_ZAAP_COLOR_BLUE_2  + ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color2)) > I_AM_IN_PUERKAZOS_ZAAP_COLOR_BLUE_2  - ERROR_GET_COLOUR_SMALL)
        &&
        (int(GetRValue(color3)) < I_AM_IN_PUERKAZOS_ZAAP_COLOR_RED_3   + ERROR_GET_COLOUR_SMALL) &&
        (int(GetRValue(color3)) > I_AM_IN_PUERKAZOS_ZAAP_COLOR_RED_3   - ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color3)) < I_AM_IN_PUERKAZOS_ZAAP_COLOR_GREEN_3 + ERROR_GET_COLOUR_SMALL) &&
        (int(GetGValue(color3)) > I_AM_IN_PUERKAZOS_ZAAP_COLOR_GREEN_3 - ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color3)) < I_AM_IN_PUERKAZOS_ZAAP_COLOR_BLUE_3  + ERROR_GET_COLOUR_SMALL) &&
        (int(GetBValue(color3)) > I_AM_IN_PUERKAZOS_ZAAP_COLOR_BLUE_3  - ERROR_GET_COLOUR_SMALL)
        )
    {
        File::LogFile("I'm in Pig Plains Zaap. ALL OK!", true);
        ret = true;
    }

    return ret;
}
/*
bool CheckZaapGobball()
{
	bool ret = false;

	LogFile("CheckZaapGobball");
	COLORREF color1 = GetColor(I_AM_IN_GOBBALL_ZAAP_POS_X_1, I_AM_IN_GOBBALL_ZAAP_POS_Y_1);
	COLORREF color2 = GetColor(I_AM_IN_GOBBALL_ZAAP_POS_X_2, I_AM_IN_GOBBALL_ZAAP_POS_Y_2);
	COLORREF color3 = GetColor(I_AM_IN_GOBBALL_ZAAP_POS_X_3, I_AM_IN_GOBBALL_ZAAP_POS_Y_3);
	COLORREF color4 = GetColor(I_AM_IN_GOBBALL_ZAAP_POS_X_4, I_AM_IN_GOBBALL_ZAAP_POS_Y_4);

	if ((int(GetRValue(color1)) < I_AM_IN_GOBBALL_ZAAP_COLOR_RED_1 + ERROR_GET_COLOUR_SMALL) &&
		(int(GetRValue(color1)) > I_AM_IN_GOBBALL_ZAAP_COLOR_RED_1 - ERROR_GET_COLOUR_SMALL) &&
		(int(GetGValue(color1)) < I_AM_IN_GOBBALL_ZAAP_COLOR_GREEN_1 + ERROR_GET_COLOUR_SMALL) &&
		(int(GetGValue(color1)) > I_AM_IN_GOBBALL_ZAAP_COLOR_GREEN_1 - ERROR_GET_COLOUR_SMALL) &&
		(int(GetBValue(color1)) < I_AM_IN_GOBBALL_ZAAP_COLOR_BLUE_1 + ERROR_GET_COLOUR_SMALL) &&
		(int(GetBValue(color1)) > I_AM_IN_GOBBALL_ZAAP_COLOR_BLUE_1 - ERROR_GET_COLOUR_SMALL)
		&&
		(int(GetRValue(color2)) < I_AM_IN_GOBBALL_ZAAP_COLOR_RED_2 + ERROR_GET_COLOUR_SMALL) &&
		(int(GetRValue(color2)) > I_AM_IN_GOBBALL_ZAAP_COLOR_RED_2 - ERROR_GET_COLOUR_SMALL) &&
		(int(GetGValue(color2)) < I_AM_IN_GOBBALL_ZAAP_COLOR_GREEN_2 + ERROR_GET_COLOUR_SMALL) &&
		(int(GetGValue(color2)) > I_AM_IN_GOBBALL_ZAAP_COLOR_GREEN_2 - ERROR_GET_COLOUR_SMALL) &&
		(int(GetBValue(color2)) < I_AM_IN_GOBBALL_ZAAP_COLOR_BLUE_2 + ERROR_GET_COLOUR_SMALL) &&
		(int(GetBValue(color2)) > I_AM_IN_GOBBALL_ZAAP_COLOR_BLUE_2 - ERROR_GET_COLOUR_SMALL)
		&&
		(int(GetRValue(color3)) < I_AM_IN_GOBBALL_ZAAP_COLOR_RED_3 + ERROR_GET_COLOUR_SMALL) &&
		(int(GetRValue(color3)) > I_AM_IN_GOBBALL_ZAAP_COLOR_RED_3 - ERROR_GET_COLOUR_SMALL) &&
		(int(GetGValue(color3)) < I_AM_IN_GOBBALL_ZAAP_COLOR_GREEN_3 + ERROR_GET_COLOUR_SMALL) &&
		(int(GetGValue(color3)) > I_AM_IN_GOBBALL_ZAAP_COLOR_GREEN_3 - ERROR_GET_COLOUR_SMALL) &&
		(int(GetBValue(color3)) < I_AM_IN_GOBBALL_ZAAP_COLOR_BLUE_3 + ERROR_GET_COLOUR_SMALL) &&
		(int(GetBValue(color3)) > I_AM_IN_GOBBALL_ZAAP_COLOR_BLUE_3 - ERROR_GET_COLOUR_SMALL)
		&&
		(int(GetRValue(color4)) < I_AM_IN_GOBBALL_ZAAP_COLOR_RED_4   + ERROR_GET_COLOUR_SMALL) &&
		(int(GetRValue(color4)) > I_AM_IN_GOBBALL_ZAAP_COLOR_RED_4   - ERROR_GET_COLOUR_SMALL) &&
		(int(GetGValue(color4)) < I_AM_IN_GOBBALL_ZAAP_COLOR_GREEN_4 + ERROR_GET_COLOUR_SMALL) &&
		(int(GetGValue(color4)) > I_AM_IN_GOBBALL_ZAAP_COLOR_GREEN_4 - ERROR_GET_COLOUR_SMALL) &&
		(int(GetBValue(color4)) < I_AM_IN_GOBBALL_ZAAP_COLOR_BLUE_4  + ERROR_GET_COLOUR_SMALL) &&
		(int(GetBValue(color4)) > I_AM_IN_GOBBALL_ZAAP_COLOR_BLUE_4  - ERROR_GET_COLOUR_SMALL)
		)
	{
		LogFile("I'm in GOBBALL Zaap ! ALL OK!!");
		ret = true;
	}

	return ret;
}


bool CheckZaapCaniaMassif()
{
	bool ret = false;

	COLORREF color1 = GetColor(I_AM_IN_CANIA_MASSIF_ZAAP_POS_X_1, I_AM_IN_CANIA_MASSIF_ZAAP_POS_Y_1);
	COLORREF color2 = GetColor(I_AM_IN_CANIA_MASSIF_ZAAP_POS_X_2, I_AM_IN_CANIA_MASSIF_ZAAP_POS_Y_2);
	COLORREF color3 = GetColor(I_AM_IN_CANIA_MASSIF_ZAAP_POS_X_3, I_AM_IN_CANIA_MASSIF_ZAAP_POS_Y_3);

	if ((int(GetRValue(color1)) < I_AM_IN_CANIA_MASSIF_ZAAP_COLOR_RED_1   + ERROR_GET_COLOUR_SMALL) &&
		(int(GetRValue(color1)) > I_AM_IN_CANIA_MASSIF_ZAAP_COLOR_RED_1   - ERROR_GET_COLOUR_SMALL) &&
		(int(GetGValue(color1)) < I_AM_IN_CANIA_MASSIF_ZAAP_COLOR_GREEN_1 + ERROR_GET_COLOUR_SMALL) &&
		(int(GetGValue(color1)) > I_AM_IN_CANIA_MASSIF_ZAAP_COLOR_GREEN_1 - ERROR_GET_COLOUR_SMALL) &&
		(int(GetBValue(color1)) < I_AM_IN_CANIA_MASSIF_ZAAP_COLOR_BLUE_1  + ERROR_GET_COLOUR_SMALL) &&
		(int(GetBValue(color1)) > I_AM_IN_CANIA_MASSIF_ZAAP_COLOR_BLUE_1  - ERROR_GET_COLOUR_SMALL)
		&&
		(int(GetRValue(color2)) < I_AM_IN_CANIA_MASSIF_ZAAP_COLOR_RED_2   + ERROR_GET_COLOUR_SMALL) &&
		(int(GetRValue(color2)) > I_AM_IN_CANIA_MASSIF_ZAAP_COLOR_RED_2 -   ERROR_GET_COLOUR_SMALL) &&
		(int(GetGValue(color2)) < I_AM_IN_CANIA_MASSIF_ZAAP_COLOR_GREEN_2 + ERROR_GET_COLOUR_SMALL) &&
		(int(GetGValue(color2)) > I_AM_IN_CANIA_MASSIF_ZAAP_COLOR_GREEN_2 - ERROR_GET_COLOUR_SMALL) &&
		(int(GetBValue(color2)) < I_AM_IN_CANIA_MASSIF_ZAAP_COLOR_BLUE_2  + ERROR_GET_COLOUR_SMALL) &&
		(int(GetBValue(color2)) > I_AM_IN_CANIA_MASSIF_ZAAP_COLOR_BLUE_2  - ERROR_GET_COLOUR_SMALL)
		&&
		(int(GetRValue(color3)) < I_AM_IN_CANIA_MASSIF_ZAAP_COLOR_RED_3   + ERROR_GET_COLOUR_SMALL) &&
		(int(GetRValue(color3)) > I_AM_IN_CANIA_MASSIF_ZAAP_COLOR_RED_3   - ERROR_GET_COLOUR_SMALL) &&
		(int(GetGValue(color3)) < I_AM_IN_CANIA_MASSIF_ZAAP_COLOR_GREEN_3 + ERROR_GET_COLOUR_SMALL) &&
		(int(GetGValue(color3)) > I_AM_IN_CANIA_MASSIF_ZAAP_COLOR_GREEN_3 - ERROR_GET_COLOUR_SMALL) &&
		(int(GetBValue(color3)) < I_AM_IN_CANIA_MASSIF_ZAAP_COLOR_BLUE_3  + ERROR_GET_COLOUR_SMALL) &&
		(int(GetBValue(color3)) > I_AM_IN_CANIA_MASSIF_ZAAP_COLOR_BLUE_3  - ERROR_GET_COLOUR_SMALL)
		)
	{
		LogFile("I'm in CANIA_MASSIF Zaap ! ALL OK!!");
		ret = true;
	}

	return ret;
}

bool CheckZaapMoon()
{
	bool ret = false;

	COLORREF color1 = GetColor(I_AM_IN_MOON_ZAAP_POS_X_1, I_AM_IN_MOON_ZAAP_POS_Y_1);
	COLORREF color2 = GetColor(I_AM_IN_MOON_ZAAP_POS_X_2, I_AM_IN_MOON_ZAAP_POS_Y_2);
	COLORREF color3 = GetColor(I_AM_IN_MOON_ZAAP_POS_X_3, I_AM_IN_MOON_ZAAP_POS_Y_3);

	if ((int(GetRValue(color1)) < I_AM_IN_MOON_ZAAP_COLOR_RED_1   + ERROR_GET_COLOUR_SMALL) &&
		(int(GetRValue(color1)) > I_AM_IN_MOON_ZAAP_COLOR_RED_1   - ERROR_GET_COLOUR_SMALL) &&
		(int(GetGValue(color1)) < I_AM_IN_MOON_ZAAP_COLOR_GREEN_1 + ERROR_GET_COLOUR_SMALL) &&
		(int(GetGValue(color1)) > I_AM_IN_MOON_ZAAP_COLOR_GREEN_1 - ERROR_GET_COLOUR_SMALL) &&
		(int(GetBValue(color1)) < I_AM_IN_MOON_ZAAP_COLOR_BLUE_1  + ERROR_GET_COLOUR_SMALL) &&
		(int(GetBValue(color1)) > I_AM_IN_MOON_ZAAP_COLOR_BLUE_1  - ERROR_GET_COLOUR_SMALL)
		&&
		(int(GetRValue(color2)) < I_AM_IN_MOON_ZAAP_COLOR_RED_2   + ERROR_GET_COLOUR_SMALL) &&
		(int(GetRValue(color2)) > I_AM_IN_MOON_ZAAP_COLOR_RED_2 -   ERROR_GET_COLOUR_SMALL) &&
		(int(GetGValue(color2)) < I_AM_IN_MOON_ZAAP_COLOR_GREEN_2 + ERROR_GET_COLOUR_SMALL) &&
		(int(GetGValue(color2)) > I_AM_IN_MOON_ZAAP_COLOR_GREEN_2 - ERROR_GET_COLOUR_SMALL) &&
		(int(GetBValue(color2)) < I_AM_IN_MOON_ZAAP_COLOR_BLUE_2  + ERROR_GET_COLOUR_SMALL) &&
		(int(GetBValue(color2)) > I_AM_IN_MOON_ZAAP_COLOR_BLUE_2  - ERROR_GET_COLOUR_SMALL)
		&&
		(int(GetRValue(color3)) < I_AM_IN_MOON_ZAAP_COLOR_RED_3   + ERROR_GET_COLOUR_SMALL) &&
		(int(GetRValue(color3)) > I_AM_IN_MOON_ZAAP_COLOR_RED_3   - ERROR_GET_COLOUR_SMALL) &&
		(int(GetGValue(color3)) < I_AM_IN_MOON_ZAAP_COLOR_GREEN_3 + ERROR_GET_COLOUR_SMALL) &&
		(int(GetGValue(color3)) > I_AM_IN_MOON_ZAAP_COLOR_GREEN_3 - ERROR_GET_COLOUR_SMALL) &&
		(int(GetBValue(color3)) < I_AM_IN_MOON_ZAAP_COLOR_BLUE_3  + ERROR_GET_COLOUR_SMALL) &&
		(int(GetBValue(color3)) > I_AM_IN_MOON_ZAAP_COLOR_BLUE_3  - ERROR_GET_COLOUR_SMALL)
		)
	{
		LogFile("I'm in MOON Zaap ! ALL OK!!");
		ret = true;
	}

	return ret;
}

bool CheckZaapSufokianShoreline()
{
	bool ret = false;

	COLORREF color1 = GetColor(I_AM_IN_SUFOKIAN_SHORELINE_ZAAP_POS_X_1, I_AM_IN_SUFOKIAN_SHORELINE_ZAAP_POS_Y_1);
	COLORREF color2 = GetColor(I_AM_IN_SUFOKIAN_SHORELINE_ZAAP_POS_X_2, I_AM_IN_SUFOKIAN_SHORELINE_ZAAP_POS_Y_2);
	COLORREF color3 = GetColor(I_AM_IN_SUFOKIAN_SHORELINE_ZAAP_POS_X_3, I_AM_IN_SUFOKIAN_SHORELINE_ZAAP_POS_Y_3);

	if ((int(GetRValue(color1)) < I_AM_IN_SUFOKIAN_SHORELINE_ZAAP_COLOR_RED_1   + ERROR_GET_COLOUR_SMALL) &&
		(int(GetRValue(color1)) > I_AM_IN_SUFOKIAN_SHORELINE_ZAAP_COLOR_RED_1   - ERROR_GET_COLOUR_SMALL) &&
		(int(GetGValue(color1)) < I_AM_IN_SUFOKIAN_SHORELINE_ZAAP_COLOR_GREEN_1 + ERROR_GET_COLOUR_SMALL) &&
		(int(GetGValue(color1)) > I_AM_IN_SUFOKIAN_SHORELINE_ZAAP_COLOR_GREEN_1 - ERROR_GET_COLOUR_SMALL) &&
		(int(GetBValue(color1)) < I_AM_IN_SUFOKIAN_SHORELINE_ZAAP_COLOR_BLUE_1  + ERROR_GET_COLOUR_SMALL) &&
		(int(GetBValue(color1)) > I_AM_IN_SUFOKIAN_SHORELINE_ZAAP_COLOR_BLUE_1  - ERROR_GET_COLOUR_SMALL)
		&&
		(int(GetRValue(color2)) < I_AM_IN_SUFOKIAN_SHORELINE_ZAAP_COLOR_RED_2   + ERROR_GET_COLOUR_SMALL) &&
		(int(GetRValue(color2)) > I_AM_IN_SUFOKIAN_SHORELINE_ZAAP_COLOR_RED_2 -   ERROR_GET_COLOUR_SMALL) &&
		(int(GetGValue(color2)) < I_AM_IN_SUFOKIAN_SHORELINE_ZAAP_COLOR_GREEN_2 + ERROR_GET_COLOUR_SMALL) &&
		(int(GetGValue(color2)) > I_AM_IN_SUFOKIAN_SHORELINE_ZAAP_COLOR_GREEN_2 - ERROR_GET_COLOUR_SMALL) &&
		(int(GetBValue(color2)) < I_AM_IN_SUFOKIAN_SHORELINE_ZAAP_COLOR_BLUE_2  + ERROR_GET_COLOUR_SMALL) &&
		(int(GetBValue(color2)) > I_AM_IN_SUFOKIAN_SHORELINE_ZAAP_COLOR_BLUE_2  - ERROR_GET_COLOUR_SMALL)
		&&
		(int(GetRValue(color3)) < I_AM_IN_SUFOKIAN_SHORELINE_ZAAP_COLOR_RED_3   + ERROR_GET_COLOUR_SMALL) &&
		(int(GetRValue(color3)) > I_AM_IN_SUFOKIAN_SHORELINE_ZAAP_COLOR_RED_3   - ERROR_GET_COLOUR_SMALL) &&
		(int(GetGValue(color3)) < I_AM_IN_SUFOKIAN_SHORELINE_ZAAP_COLOR_GREEN_3 + ERROR_GET_COLOUR_SMALL) &&
		(int(GetGValue(color3)) > I_AM_IN_SUFOKIAN_SHORELINE_ZAAP_COLOR_GREEN_3 - ERROR_GET_COLOUR_SMALL) &&
		(int(GetBValue(color3)) < I_AM_IN_SUFOKIAN_SHORELINE_ZAAP_COLOR_BLUE_3  + ERROR_GET_COLOUR_SMALL) &&
		(int(GetBValue(color3)) > I_AM_IN_SUFOKIAN_SHORELINE_ZAAP_COLOR_BLUE_3  - ERROR_GET_COLOUR_SMALL)
		)
	{
		LogFile("I'm in shoreline Zaap ! ALL OK!!");
		ret = true;
	}

	return ret;
}
*/
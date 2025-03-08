#include "basicOperations.hpp"

#include <iostream>

COLORREF GetColor(int x, int y, bool printRGB)
{
    HDC hdc_ = GetDC(NULL);
    COLORREF color = GetPixel(hdc_, x, y);
    ReleaseDC(NULL, hdc_);

    if(printRGB) {
        std::cout << (int(GetRValue(color))) << " " << (int(GetGValue(color))) << " " << (int(GetBValue(color)));
    }

    return color;
}

COLORREF GetColorCout(int x, int y)
{
	HDC hdc_ = GetDC(NULL);
	COLORREF color = GetPixel(hdc_, x, y);
	ReleaseDC(NULL, hdc_);

	return color;
}

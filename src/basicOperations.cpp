#include "basicOperations.hpp"

int basicOperations::RuletaInput(int min, int max)
{
    int ret = 0;
    std::mt19937 rng(static_cast<unsigned int>(std::chrono::steady_clock::now().time_since_epoch().count()));
    ret = (rng()) % (abs(max - min));
    return (min + ret);
}

COLORREF basicOperations::GetColor(int x, int y, bool printRGB)
{
    HDC hdc_ = GetDC(NULL);
    COLORREF color = GetPixel(hdc_, x, y);
    ReleaseDC(NULL, hdc_);

    if(printRGB) {
        std::cout << (int(GetRValue(color))) << " " << (int(GetGValue(color))) << " " << (int(GetBValue(color))) << std::endl;
    }

    return color;
}
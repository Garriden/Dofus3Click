#include "openCVOperations.hpp"


#include "basicOperations.hpp"
#include "checks.hpp"
#include "system/inputs.hpp"
#include "system/file.hpp"




// Function to capture the entire screen on Windows
cv::Mat OpenCVOperations::CaptureEntireScreen()
{
    File::LogFile("Taking screenshot...", true);

    // Notify OS to avoid DPI scaling issues (ensures exact pixel dimensions)
    SetProcessDPIAware();

    HWND hwnd = GetDesktopWindow();
    HDC hwindowDC = GetDC(hwnd);
    HDC hwindowCompatibleDC = CreateCompatibleDC(hwindowDC);

    int width = GetSystemMetrics(SM_CXSCREEN);
    int height = GetSystemMetrics(SM_CYSCREEN);

    // Create a matrix to hold the raw pixel data (4 channels: BGRA)
    cv::Mat screenMat(height, width, CV_8UC4);

    HBITMAP hbwindow = CreateCompatibleBitmap(hwindowDC, width, height);
    SelectObject(hwindowCompatibleDC, hbwindow);
    
    // Copy screen desktop to bitmap context
    BitBlt(hwindowCompatibleDC, 0, 0, width, height, hwindowDC, 0, 0, SRCCOPY);
    GetBitmapBits(hbwindow, width * height * 4, screenMat.data);

    // Clean up memory leaks
    DeleteObject(hbwindow);
    DeleteDC(hwindowCompatibleDC);
    ReleaseDC(hwnd, hwindowDC);

    // Convert from 4-channel BGRA to OpenCV's standard 3-channel BGR
    cv::Mat finalScreen;
    cv::cvtColor(screenMat, finalScreen, cv::COLOR_BGRA2BGR);

    return finalScreen;
}

// Function to capture the playable screen on Windows
cv::Mat OpenCVOperations::CapturePlayableScreen()
{
    File::LogFile("Taking screenshot...", true);

    // Notify OS to avoid DPI scaling issues (ensures exact pixel dimensions)
    SetProcessDPIAware();

    HWND hwnd = GetDesktopWindow();
    HDC hwindowDC = GetDC(hwnd);
    HDC hwindowCompatibleDC = CreateCompatibleDC(hwindowDC);

    int startX = SCREENSHOOT_X_STARTPOSITION; // I want to capture just the clickable zone.
    int width = GetSystemMetrics(SM_CXSCREEN) - (startX * 2);
    int height = GetSystemMetrics(SM_CYSCREEN);

    // Create a matrix to hold the raw pixel data (4 channels: BGRA)
    cv::Mat screenMat(height, width, CV_8UC4);

    HBITMAP hbwindow = CreateCompatibleBitmap(hwindowDC, width, height);
    SelectObject(hwindowCompatibleDC, hbwindow);
    
    // Copy screen desktop to bitmap context
    BitBlt(hwindowCompatibleDC, 0, 0, width, height, hwindowDC, startX, 0, SRCCOPY);
    GetBitmapBits(hbwindow, width * height * 4, screenMat.data);

    // Clean up memory leaks
    DeleteObject(hbwindow);
    DeleteDC(hwindowCompatibleDC);
    ReleaseDC(hwnd, hwindowDC);

    // Convert from 4-channel BGRA to OpenCV's standard 3-channel BGR
    cv::Mat finalScreen;
    cv::cvtColor(screenMat, finalScreen, cv::COLOR_BGRA2BGR);

    return finalScreen;
}

cv::Mat OpenCVOperations::CaptureWindowBar()
{
    File::LogFile("Taking WindowBar screenshot...", true);

    // Notify OS to avoid DPI scaling issues (ensures exact pixel dimensions)
    SetProcessDPIAware();

    HWND hwnd = GetDesktopWindow();
    HDC hwindowDC = GetDC(hwnd);
    HDC hwindowCompatibleDC = CreateCompatibleDC(hwindowDC);

    int startX = 0; // I want to capture just the clickable zone.
    int width = GetSystemMetrics(SM_CXSCREEN) / 2;
    int height = 50;

    // Create a matrix to hold the raw pixel data (4 channels: BGRA)
    cv::Mat screenMat(height, width, CV_8UC4);

    HBITMAP hbwindow = CreateCompatibleBitmap(hwindowDC, width, height);
    SelectObject(hwindowCompatibleDC, hbwindow);
    
    // Copy screen desktop to bitmap context
    BitBlt(hwindowCompatibleDC, 0, 0, width, height, hwindowDC, startX, 0, SRCCOPY);
    GetBitmapBits(hbwindow, width * height * 4, screenMat.data);

    // Clean up memory leaks
    DeleteObject(hbwindow);
    DeleteDC(hwindowCompatibleDC);
    ReleaseDC(hwnd, hwindowDC);

    // Convert from 4-channel BGRA to OpenCV's standard 3-channel BGR
    cv::Mat finalScreen;
    cv::cvtColor(screenMat, finalScreen, cv::COLOR_BGR2GRAY); // BW.

    return finalScreen;

}

// Function to find the template image in the screenshot
double OpenCVOperations::FindImageInScreenshot(const cv::Mat& screenshot, const cv::Mat& templateImg, int &XPosition, int &YPosition)
{
    // Check if the template image is larger than the screenshot
    if (templateImg.cols > screenshot.cols || templateImg.rows > screenshot.rows) {
        File::LogFile("Error: Template image is larger than the screenshot.", true);
        return false;
    }

    cv::Mat result;
    // Perform template matching using Normalized Coefficient Method
    cv::matchTemplate(screenshot, templateImg, result, cv::TM_CCOEFF_NORMED);

    // Find the best match location and its confidence value
    double minVal, maxVal;
    cv::Point minLoc, maxLoc;
    cv::minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc);

    XPosition = maxLoc.x;
    YPosition = maxLoc.y;

    // Optional: Draw a rectangle around the matched region and save it to verify.
    cv::Mat visualResult = screenshot.clone();
    cv::rectangle(visualResult, maxLoc, cv::Point(maxLoc.x + templateImg.cols, maxLoc.y + templateImg.rows), cv::Scalar(0, 255, 0), 2);
    cv::imwrite("match_result.png", visualResult);

    return maxVal;
}

bool OpenCVOperations::FindImage(std::string imageToFindName, int &XPosition, int &YPosition, double acceptableThreshold)
{
    bool success = false;

    cv::Mat screenshoot = CapturePlayableScreen();

    cv::Mat imageToFind = cv::imread(imageToFindName, cv::IMREAD_COLOR);

    double threshold = FindImageInScreenshot(screenshoot, imageToFind, XPosition, YPosition);

    if(threshold >= acceptableThreshold) {
        File::LogFile("Image Found! Confidence: " + std::to_string(threshold * 100) + "%", true);
        File::LogFile("Location: X=" + std::to_string(XPosition) + ", Y=" + std::to_string(YPosition), true);
        success = true;
    } else {
        File::LogFile("Image NOT found. Highest confidence was: " + std::to_string(threshold * 100) + "%", true);
    }

    return success;
}

bool OpenCVOperations::FindImages(std::vector<std::string> imagesToFindName, int &XPosition, int &YPosition, double acceptableThreshold)
{
    bool success = false;

    for(int ii = 0; !success && ii < imagesToFindName.size(); ++ii) {
        success = FindImage(imagesToFindName[ii], XPosition, YPosition, acceptableThreshold)
    }

    return success;
}

bool OpenCVOperations::CheckPj(std::string className, double acceptableThreshold = 0.8)
{
    bool success = false;

    // Find className image path.
    std::string path = "Images/Class/"  + className + ".PNG";

    // Start image recognition.
    cv::Mat screenshoot = CaptureWindowBar();

    cv::Mat imageToFind = cv::imread(imageToFindName, cv::IMREAD_GRAYSCALE);

    int XPosition, YPosition;
    double threshold = FindImageInScreenshot(screenshoot, path, XPosition, YPosition);

    if(threshold >= acceptableThreshold) {
        File::LogFile("Pj Image Found! Confidence: " + std::to_string(threshold * 100) + "%", true);
        File::LogFile("Location: X=" + std::to_string(XPosition) + ", Y=" + std::to_string(YPosition), true);
        success = true;
    } else {
        File::LogFile("Pj Image NOT found. Highest confidence was: " + std::to_string(threshold * 100) + "%", true);
    }

    return success;
}
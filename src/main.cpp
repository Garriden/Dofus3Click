#include "system/inputs.hpp"
#include "menusInterface.hpp"
#include "menus.hpp"
#include "train.hpp"

#include "checks.hpp"
#include "fight.hpp"

#include "roadmap.hpp"
#include "zaap.hpp"

#include <windows.h>
#include <stdio.h>
#include <opencv2/opencv.hpp>

#define USE_OPENCV          true






// Function to capture the desktop screen on Windows
cv::Mat captureScreen() {
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

// Function to find the template image in the screenshot
bool findImageInScreenshot(const cv::Mat& screenshot, const cv::Mat& templateImg, double threshold = 0.8) {
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

    // For TM_CCOEFF_NORMED, maxVal ranges from -1.0 to 1.0 (1.0 is a perfect match)
    if (maxVal >= threshold) {
        File::LogFile("Image Found! Confidence: " + std::to_string(maxVal * 100) + "%", true);
        File::LogFile("Location: X=" + std::to_string(maxLoc.x) + ", Y=" + std::to_string(maxLoc.y), true);

        // Optional: Draw a rectangle around the matched region and save it to verify
        cv::Mat visualResult = screenshot.clone();
        cv::rectangle(visualResult, maxLoc, cv::Point(maxLoc.x + templateImg.cols, maxLoc.y + templateImg.rows), cv::Scalar(0, 255, 0), 2);
        cv::imwrite("match_result.png", visualResult);
        
        return true;
    }

    File::LogFile("Image NOT found. Highest confidence was: " + std::to_string(maxVal * 100) + "%", true);
    return false;
}


int main()
{
    // Activating the console in the other screen.
    AllocConsole();
    HWND consoleWindow = GetConsoleWindow();
    if(consoleWindow != NULL) {
        if(GetSystemMetrics(SM_CMONITORS) > 1) {
            SetWindowPos(consoleWindow, 0, -600, -300, 600, 1000, 0);
        } else {
            SetWindowPos(consoleWindow, 0, 0, 0, 340, 900, 0);
        }
    }

    //inputs::GetWindowsVersion();
    
    //AskPj();
    while(true) {
        show::MainMenu();
        inputs::PressCtrlKey(0);  // Reset Ctrl.
        inputs::PressShiftKey(0); // Reset Shift.
        int in;
        std::cin >> in;
        switch(in) {
            case 0:
            default:
                return 0;
                break;
            case 1:
                inputs::DebugPoints();
                break;
            case 2:
                menu::Farmer();
                break;
            case 3:
                menu::Wood();
                break;
            case 4:
                menu::Mineral();
                break;
            case 5:
                menu::Alchemist();
                break;
            case 6:
                menu::Fisherman();
                break;
            case 9:
                menu::DailyMissions();
                break;
            case 10:
            {
                menu::FindEnemiesMenu();
                break;
            }
            case 11: // Find enemies directly.
            {
                inputs::ClickOnExe();

                while(1) {
                    Train train;
                    train.IterateBetweenMaps();
                }
                break;
            }
            case 70:
                //LogFile("Slow PC.");
                //#undef SECONDS
                //#define SECONDS (1250);
                break;
            case 71:
                //current_pj_ = "ENU";
                //invos_ = true;
                //heal_ = true;
                //LogFile("Playing as Enutrof.");
                break;
            case 99: //debug

                std::this_thread::sleep_for(std::chrono::seconds(1));
                inputs::ClickOnExe();

                //std::this_thread::sleep_for(std::chrono::seconds(3));
                //check::AmILevelUp();

                //check::AmIDefeated();
                //zaap::CheckZaapAstrub();
                //check::IsMenuPrincipalBox();

                //std::this_thread::sleep_for(std::chrono::seconds(3));

                //inputs::ShiftClick(1000, 300);

                //if(check::IsFight()) {
                //    Fight fight(0);
                //    fight.Start();
                //}

                //std::this_thread::sleep_for(std::chrono::seconds(2));
#if USE_OPENCV
                // Read saved image.
                /*
                cv::Mat image;
                image = cv::imread("Images/lvup.png");
                if(!image.data) {
                    printf("No image data \n");
                } else {
                    cv::namedWindow("Display Image", cv::WINDOW_AUTOSIZE);
                    cv::imshow("Display Image", image);
                    cv::waitKey(0);
                }
                */

                char buffer[MAX_PATH];
                GetCurrentDirectoryA(MAX_PATH, buffer);
                std::string currentPath(buffer);
                File::LogFile("Current directory: " + currentPath, true);

                // 1. Load the template image you want to search for
                //cv::Mat templateImg = cv::imread("C:/Users/Garri/Desktop/Dofus3Click/Images/Zaap/zaapInterface.PNG", cv::IMREAD_COLOR);
                cv::Mat templateImg = cv::imread("Images/Zaap/zaapInterface.PNG", cv::IMREAD_COLOR);
                if (templateImg.empty()) {
                    File::LogFile("Error: Could not load image.", true);
                    return -1;
                }

                // 2. Take the screenshot
                cv::Mat screenshot = captureScreen();

                // 3. Compare them (using an 80% confidence threshold)
                double confidenceThreshold = 0.80; 
                bool success = findImageInScreenshot(screenshot, templateImg, confidenceThreshold);
#endif

                //Roadmap roadmap(Profession::TEST, "hola", nullptr, nullptr,
                //    {"", "../../Telemetry/test.csv", /*"../../Telemetry/Fisher/Ganaderoslv80_2.csv"*/});
                //roadmap.Start();
                
            break;
        }
    }

    return 0;
}
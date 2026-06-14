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
    cv::imwrite("screenshoot.png", finalScreen);

    return finalScreen;
}

// Function to capture the playable screen on Windows
cv::Mat OpenCVOperations::CapturePlayableScreenWithoutUI()
{
    File::LogFile("Taking screenshot...", true);

    // Notify OS to avoid DPI scaling issues (ensures exact pixel dimensions)
    SetProcessDPIAware();

    HWND hwnd = GetDesktopWindow();
    HDC hwindowDC = GetDC(hwnd);
    HDC hwindowCompatibleDC = CreateCompatibleDC(hwindowDC);

    int startX = SCREENSHOOT_X_STARTPOSITION; // I want to capture just the clickable zone.
    int startY = 25;
    int width = GetSystemMetrics(SM_CXSCREEN) - (startX * 2);
    int height = GetSystemMetrics(SM_CYSCREEN) - 200; // Do NOT catch the UI.

    // Create a matrix to hold the raw pixel data (4 channels: BGRA)
    cv::Mat screenMat(height, width, CV_8UC4);

    HBITMAP hbwindow = CreateCompatibleBitmap(hwindowDC, width, height);
    SelectObject(hwindowCompatibleDC, hbwindow);
    
    // Copy screen desktop to bitmap context
    BitBlt(hwindowCompatibleDC, 0, 0, width, height, hwindowDC, startX, startY, SRCCOPY);
    GetBitmapBits(hbwindow, width * height * 4, screenMat.data);

    // Clean up memory leaks
    DeleteObject(hbwindow);
    DeleteDC(hwindowCompatibleDC);
    ReleaseDC(hwnd, hwindowDC);

    // Convert from 4-channel BGRA to OpenCV's standard 3-channel BGR
    cv::Mat finalScreen;
    cv::cvtColor(screenMat, finalScreen, cv::COLOR_BGRA2BGR);
    cv::imwrite("screenshoot.png", finalScreen);

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
    int width = GetSystemMetrics(SM_CXSCREEN) / 4;
    int height = 25;

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

    // Calculate the rectangle center position.
    XPosition = maxLoc.x + (templateImg.cols / 2);
    YPosition = maxLoc.y + (templateImg.rows / 2);

    // Optional: Draw a rectangle around the matched region and save it to verify.
    cv::Mat visualResult = screenshot.clone();
    cv::rectangle(visualResult, maxLoc, cv::Point(maxLoc.x + templateImg.cols, maxLoc.y + templateImg.rows), cv::Scalar(0, 255, 0), 2);
    cv::circle(visualResult, cv::Point(XPosition, YPosition), 3, cv::Scalar(0, 0, 255), -1);
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
        success = FindImage(imagesToFindName[ii], XPosition, YPosition, acceptableThreshold);
    }

    return success;
}

bool OpenCVOperations::CheckPj(std::string className, double acceptableThreshold)
{
    bool success = false;

    // Find className image path.
    std::string path = "Images/Class/"  + className + ".PNG";

    // Start image recognition.
    cv::Mat screenshoot = CaptureWindowBar();

    cv::Mat imageToFind = cv::imread(path, cv::IMREAD_GRAYSCALE);

    int XPosition, YPosition;
    double threshold = FindImageInScreenshot(screenshoot, imageToFind, XPosition, YPosition);

    if(threshold >= acceptableThreshold) {
        File::LogFile("Pj Image Found! Confidence: " + std::to_string(threshold * 100) + "%", true);
        File::LogFile("Location: X=" + std::to_string(XPosition) + ", Y=" + std::to_string(YPosition), true);
        success = true;
    } else {
        File::LogFile("Pj Image NOT found. Highest confidence was: " + std::to_string(threshold * 100) + "%", true);
    }

    return success;
}

int OpenCVOperations::CountMobsByTextLines()
{
    int mobCount = 0;
    //inputs::PressKeyLocked('z'); // No, just put the cursor on the mob.
try {
    cv::Mat screenshoot = CapturePlayableScreenWithoutUI();
    //cv::Mat screenshoot = cv::imread("screenshoot.PNG", cv::COLOR_BGR2HSV);

    //inputs::PressKey('z'); // Release the pressed key.



    // 1. Convert directly to HSV (Keep the colors!)
    cv::Mat hsv, colorMask;
    cv::cvtColor(screenshoot, hsv, cv::COLOR_BGR2HSV);

    // 2. Color Masking: STRICTLY Dark Blue / Purple
    // OpenCV Hue is 0-179. Blue/Purple is ~100-160.
    // By forcing Hue to be >= 95, we completely exclude all grass, leaves, and trees.
    cv::Scalar lower_ui_color(95, 10, 10);    // Minimum: Blue hue, low saturation, dark
    cv::Scalar upper_ui_color(160, 180, 90);  // Maximum: Purple hue, mid saturation, somewhat dark

    cv::inRange(hsv, lower_ui_color, upper_ui_color, colorMask);

    // 3. Morphological Closing
    // The text inside the box isn't dark blue, so it creates holes in our mask.
    // This step "paints over" the text gaps to make the box one solid rectangle.
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(15, 15));
    cv::morphologyEx(colorMask, colorMask, cv::MORPH_CLOSE, kernel);

    // 4. Find the box contour
    std::vector<std::vector<cv::Point> > contours;
    cv::findContours(colorMask, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    cv::Rect tooltipRect;
    double maxArea = 0;

    for(const auto& contour : contours) {
        double area = cv::contourArea(contour);
        cv::Rect r = cv::boundingRect(contour);
        
        // Ensure it's a vertically oriented rectangle and reasonably sized
        double aspectRatio = (double)r.width / r.height;
        if(area > maxArea && r.width > 60 && r.height > 50 && aspectRatio < 2.5) {
            maxArea = area;
            tooltipRect = r;
        }
    }

    // Fallback if the box wasn't isolated cleanly
    if(tooltipRect.area() == 0) {
        File::LogFile("Tooltip window not found via Color Masking!", true);
        return 0; 
    } 

    // 5. Isolate bright text inside the cropped tooltip
    cv::Mat tooltip = screenshoot(tooltipRect);
    cv::Mat tooltipGray, binaryText;
    cv::cvtColor(tooltip, tooltipGray, cv::COLOR_BGR2GRAY);
    cv::threshold(tooltipGray, binaryText, 140, 255, cv::THRESH_BINARY);

    // 6 Group bright pixels into text rows
    cv::Mat labels, stats, centroids;
    int numComponents = cv::connectedComponentsWithStats(binaryText, labels, stats, centroids);

    std::vector<cv::Rect> rowBoxes;
    for(int i = 1; i < numComponents; i++) {
        int x = stats.at<int>(i, cv::CC_STAT_LEFT);
        int y = stats.at<int>(i, cv::CC_STAT_TOP);
        int w = stats.at<int>(i, cv::CC_STAT_WIDTH);
        int h = stats.at<int>(i, cv::CC_STAT_HEIGHT);

        if (h < 5 || w < 5) continue; // Ignore noise

        bool newRow = true;
        for (auto& box : rowBoxes) {
            if (std::abs(y - box.y) < 8) { 
                box |= cv::Rect(x, y, w, h); 
                newRow = false;
                break;
            }
        }
        if (newRow) {
            rowBoxes.push_back(cv::Rect(x, y, w, h));
        }
    }




    mobCount = std::max(0, static_cast<int>(rowBoxes.size()) - 2);

    File::LogFile(" mobCount: " + std::to_string(mobCount), true);
    std::this_thread::sleep_for(std::chrono::seconds(1));


    // Optional Visual Debugging
    //cv::rectangle(screenshoot, tooltipRect, cv::Scalar(0, 255, 0), 2);
    //cv::imshow("Detected Window", screenshoot);
    //cv::imshow("Binary Text inside Tooltip", binaryText);
    //cv::waitKey(0);

    } catch (const cv::Exception& e) {
        File::LogFile(std::string("OpenCV Exception Caught: ") + e.what(), true);
    } catch (const std::exception& e) {
        File::LogFile(std::string("Standard Exception Caught: ") + e.what(), true);
    } catch (...) {
        File::LogFile("Unknown Exception Caught!", true);
    }



    //File::LogFile(" mobCount = " + std::to_string(mobCount), true);

    return mobCount;
}
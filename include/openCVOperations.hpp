#pragma once

#include <opencv2/opencv.hpp>

/**
 * @file opemCVOperations.hpp
 * @brief Static operations, Computer vision from OpenCV.
 */

class OpenCVOperations {
    public:

        static bool FindImage(std::string imageToFindName, int &XPosition, int &YPosition, double acceptableThreshold = 0.8);

    private:

        static double FindImageInScreenshot(const cv::Mat &screenshot, const cv::Mat &templateImg, int &XPosition, int &YPosition);

        static cv::Mat CapturePlayableScreen();

        static cv::Mat CaptureEntireScreen();


};
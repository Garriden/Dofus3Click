#include "OpenCVWrapper.hpp"
#include "openCVOperations.hpp" // Your existing class
#include <iostream>

extern "C" {

    WRAPPER_API int Wrapper_CountMobsByTextLines() {
        // 1. Call your existing OpenCV logic
        // 2. The cv::Mats and std::vectors will be created here in the DLL's heap
        int count = OpenCVOperations::CountMobsByTextLines();
        
        // 3. When this function ends, the DLL destroys its own variables safely!
        return count; 
    }

    //WRAPPER_API int Wrapper_FindImage(const char* imagePath, int* outX, int* outY) {
        // We dereference the pointers so the OpenCV class can modify the original variables
    //    std::string safeCppString(imagePath);
    //    bool found = OpenCVOperations::FindImage(safeCppString, *outX, *outY);
    //    return found ? 1 : 0;
    //}

    WRAPPER_API int Wrapper_CheckPj(const char* className) {
        // 1. Safely convert to std::string inside the DLL
        std::string safeClassName(className);
        
        // 2. Call your original logic
        bool isPj = OpenCVOperations::CheckPj(safeClassName);
        
        // 3. Return 1 for true, 0 for false
        return isPj ? 1 : 0;
    }

}
#pragma once

// C++ objects like std::string or cv::Mat automatically manage their own memory behind the scenes, 
// passing them across the boundary of a DLL is incredibly dangerous. 
// They get created on one side and destroyed on the other, causing massive memory corruption.

// When compiling the DLL, we EXPORT. When the .exe includes this, we IMPORT.
#ifdef BUILD_OPENCV_WRAPPER
    #define WRAPPER_API __declspec(dllexport)
#else
    #define WRAPPER_API __declspec(dllimport)
#endif

// The extern "C" forces a pure, safe C interface boundary.
extern "C" {
    // We only return an int. No C++ objects!
    WRAPPER_API int Wrapper_CountMobsByTextLines();
    
    // Example of how you would pass data safely:
    //WRAPPER_API bool Wrapper_FindImage(const char* imagePath, int* outX, int* outY);

    WRAPPER_API int Wrapper_CheckPj(const char* className);
}
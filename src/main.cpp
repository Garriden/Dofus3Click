#include "system/inputs.hpp"
#include "menusInterface.hpp"
#include "menus.hpp"
#include "train.hpp"

#include "checks.hpp"
//#include "fight.hpp"
//#include "roadmap.hpp"
//#include "zaap.hpp"

#include <windows.h>
#include <gdiplus.h> // Screenshoot.


int GetEncoderClsid(const WCHAR* format, CLSID* pClsid) {
    UINT num = 0;           // Number of image encoders
    UINT size = 0;          // Size of the image encoder array in bytes
    Gdiplus::Status status;

    // 1. Get the required size for the encoder information array
    status = Gdiplus::GetImageEncodersSize(&num, &size);
    if(status != Gdiplus::Ok || size == 0) {
        return -1; // Failure
    }

    // 2. Allocate memory using a standard C++ vector for safety
    // The vector ensures the memory is freed automatically when it goes out of scope.
    std::vector<char> buffer(size);
    Gdiplus::ImageCodecInfo* pImageCodecInfo = (Gdiplus::ImageCodecInfo*)buffer.data();

    // 3. Get the encoder information
    status = Gdiplus::GetImageEncoders(num, size, pImageCodecInfo);
    if(status != Gdiplus::Ok) {
        return -1; // Failure
    }

    // 4. Loop through the encoders to find the matching MIME type
    for(UINT j = 0; j < num; ++j) {
        // wcscmp is a C-style function, but is standard for comparing WCHAR strings
        if(wcscmp(pImageCodecInfo[j].MimeType, format) == 0) {
            *pClsid = pImageCodecInfo[j].Clsid;
            return j; // Success, return the index
        }
    }

    // If the loop finishes, the encoder was not found
    return -1;
}







#include <windows.h>
#include <psapi.h>
#include <tchar.h>
#include <iostream>
#include <tchar.h>
#include <vector>

#define MAX_PROCESS_NAME 1024

// Generic string type definitions for TCHAR compatibility
#ifdef UNICODE
    #define tcout std::wcout
#else
    #define tcout std::cout
#endif

// Function to find and print the name for each PID
bool FindProcessIdByName(std::string s) {
    // 1. Array to hold PIDs and size variables
    DWORD aProcesses[MAX_PROCESS_NAME], cbNeeded, cProcesses;
    
    // 2. Call EnumProcesses to get the list of PIDs
    if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded)) {
        tcout << _T("ERROR: EnumProcesses failed. Error: ") << GetLastError() << _T("\n");
        return false;
    }

    // 3. Calculate how many process identifiers were returned
    cProcesses = cbNeeded / sizeof(DWORD);

    bool found = false;
    // 4. Loop through the list of PIDs
    for(unsigned int i = 0; !found && i < cProcesses; i++) {
        DWORD processID = aProcesses[i];
        
        // Skip unused/zeroed entries
        if (processID == 0) continue;
        
        TCHAR szProcessName[MAX_PATH] = _T("<unknown>");
        HANDLE hProcess = NULL;

        // 5. Open the process to get a handle
        // We need PROCESS_QUERY_INFORMATION to read process info
        hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processID);

        // 6. If we successfully opened the process, get the name
        if(hProcess != NULL) {
            HMODULE hMod;
            DWORD cbActual;

            // Get the first module handle (usually the EXE)
            if (EnumProcessModules(hProcess, &hMod, sizeof(hMod), &cbActual)) {
                // Get the base name of the module
                GetModuleBaseName(hProcess, hMod, szProcessName, sizeof(szProcessName) / sizeof(TCHAR));
            }
            
            // 7. Print the PID and the name
            //tcout << szProcessName << _T(" (PID: ") << processID << _T(")\n");
            
            if(_tcsicmp(szProcessName, s.c_str()) == 0) {
                //return true;
                found = true;
            }
            
            // 8. Close the process handle
            CloseHandle(hProcess);
        } else {
            // Print unknown processes (e.g., Idle Process, CSRSS)
            // Error code 5 (Access is denied) is common here.
            //tcout << szProcessName << _T(" (PID: ") << processID << _T("). OpenProcess Failed: ") << GetLastError() << _T("\n");
        }
    }

    return found;
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



    // ScreenShoot.
    ULONG_PTR gdiplusToken;
    Gdiplus::GdiplusStartupInput gdiplusStartupInput;
    Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

    HDC hScreenDC = GetDC(nullptr);
    HDC hMemoryDC = CreateCompatibleDC(hScreenDC);
    int width = GetDeviceCaps(hScreenDC, HORZRES);
    int height = GetDeviceCaps(hScreenDC, VERTRES);
    HBITMAP hBitmap = CreateCompatibleBitmap(hScreenDC,width,height);
    HBITMAP hOldBitmap = static_cast<HBITMAP>(SelectObject(hMemoryDC,hBitmap));

    // Catch Coordenadas photo.
    int x = 20;
    int y = 300;
    width = 400;
    height = 100;
    BitBlt(hMemoryDC, 0, 0, width, height, hScreenDC, x, y, SRCCOPY);
    hBitmap = static_cast<HBITMAP>(SelectObject(hMemoryDC,hOldBitmap));


CLSID pngClsid;
if(GetEncoderClsid(L"image/png", &pngClsid) == -1) {
    // Handle error: PNG encoder not found
    std::cout << "PNG encoder not found" << std::endl;
}

// 1. Create a GDI+ Bitmap object from the HBITMAP
Gdiplus::Bitmap image(hBitmap, NULL);

// 2. Save the GDI+ Bitmap to a file
Gdiplus::Status status = image.Save(L"screenshot.png", &pngClsid, NULL);

if (status == Gdiplus::Ok) {
    // Success!
    // The screenshot is saved as "screenshot.png"
} else {
    // Handle error
}

// 3. CLEANUP: Delete the HBITMAP created earlier (WinAPI cleanup)
DeleteObject(hBitmap);
    DeleteDC(hMemoryDC);
    DeleteDC(hScreenDC);

    //inputs::GetWindowsVersion();

    //std::string tesseract_path = "C:\\Program Files\\Tesseract-OCR\\tesseract.exe";
    std::string tesseractPath = "C:\\Program Files\\Tesseract-OCR\\tesseract.exe";
    std::string imagePath = "../../Images/captura1.png";
    std::string outputPath = "outputOCR.txt";
    
    // Note: Windows paths usually need to be quoted if they contain spaces
    std::string command = "\"" + tesseractPath + "\" " + imagePath + " " + outputPath + " -l spa";
    
    std::cout << "Executing command: " << command << std::endl;

    // 2. Execute the command.
    // The system() function returns the exit status of the command.
    int return_code = std::system(command.c_str());




    std::string dofhuntExeName = "dofhunt-win64.exe";

    if(FindProcessIdByName(dofhuntExeName)) {
        //std::cout << "DofHunt is already running. Skipping launch." << std::endl;
        std::cout << "DofHunt is already running." << std::endl;
    } else { // Start DofHunt.
        std::string dofhuntPath = "C:\\Program Files\\"+ dofhuntExeName;
        command = "start \"\" \"" + dofhuntPath + "\"";
        return_code = std::system(command.c_str());
    }





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

                std::this_thread::sleep_for(std::chrono::seconds(3));
                inputs::ClickOnExe();

                std::this_thread::sleep_for(std::chrono::seconds(3));
                check::IsMenuPrincipalBox();

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

                //Roadmap roadmap(Profession::WOOD, "golfo", nullptr, nullptr,
                //    {"", "../../Telemetry/test.csv", /*"../../Telemetry/Fisher/Ganaderoslv80_2.csv"*/});
                //roadmap.Start();
                
            break;
        }
    }

    Gdiplus::GdiplusShutdown(gdiplusToken);

    return 0;
}
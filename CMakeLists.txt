####################
#      Global      #
####################

cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 20)

#####################
#      Project      #
#####################

set(LOCAL_PROJECT_NAME        "Dofus3Click")
set(LOCAL_PROJECT_VERSION     "1.4.0")
set(LOCAL_PROJECT_DESCRIPTION "TrainImprovements")

# 1. ALWAYS declare the project first
project(${LOCAL_PROJECT_NAME}
        VERSION ${LOCAL_PROJECT_VERSION}
        DESCRIPTION ${LOCAL_PROJECT_DESCRIPTION}
        LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin")

####################
#   Dependencies   #
####################

# 2. ALWAYS find packages before building targets that need them
set(OpenCV_DIR "C:/Users/Garri/opencv/build/install")
#set(OpenCV_DIR "C:/msys64/mingw64/lib/cmake/opencv4")
find_package(OpenCV REQUIRED)

#################################
#  3. BUILD THE OPENCV PLUGIN   #
#################################

add_library(OpenCVPlugin SHARED
    src/openCVOperations.cpp
    src/OpenCVWrapper.cpp
    src/system/file.cpp
    src/system/actualTime.cpp
    include/openCVOperations.hpp
    include/OpenCVWrapper.hpp
    include/system/file.hpp
    include/system/actualTime.hpp
)

target_include_directories(OpenCVPlugin PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include ${OpenCV_INCLUDE_DIRS})
target_compile_definitions(OpenCVPlugin PRIVATE BUILD_OPENCV_WRAPPER)

# CRITICAL: OpenCV is ONLY linked to the plugin!
target_link_libraries(OpenCVPlugin PRIVATE ${OpenCV_LIBS})

target_link_options(OpenCVPlugin PRIVATE -static-libgcc -static-libstdc++)




#################################
#  4. BUILD THE MAIN EXE        #
#################################

set(MAIN_SOURCES
    src/main.cpp
    src/basicOperations.cpp
    src/checks.cpp
    src/checksRoadmap.cpp
    src/fight.cpp
    src/menusInterface.cpp
    src/menus.cpp
    src/roadmap.cpp
    src/train.cpp
    src/zaap.cpp
    src/system/inputs.cpp
    src/system/file.cpp
    src/system/actualTime.cpp
    src/fightStrategy/fightStrategy.cpp
    src/fightStrategy/professionMobStrategy.cpp
    src/fightStrategy/fecaAgiBruteStrategy.cpp
    src/fightStrategy/ocraLejanoStrategy.cpp
)

set(MAIN_HEADERS
    include/basicOperations.hpp
    include/checks.hpp
    include/checksRoadmap.hpp
    include/fight.hpp
    include/roadmap.hpp
    include/menuMappings.hpp
    include/menus.hpp
    include/menusInterface.hpp
    include/train.hpp
    include/utils.hpp
    include/zaap.hpp
    include/system/inputs.hpp
    include/system/file.hpp
    include/system/actualTime.hpp
    include/fightStrategy/fightStrategy.hpp
    include/fightStrategy/professionMobStrategy.hpp
    include/fightStrategy/fecaAgiBruteStrategy.hpp
    include/fightStrategy/ocraLejanoStrategy.hpp
)

add_executable(${LOCAL_PROJECT_NAME} ${MAIN_SOURCES} ${MAIN_HEADERS})

target_include_directories(${LOCAL_PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)


# CRITICAL: The executable links to the Plugin, NOT OpenCV!
target_link_libraries(${LOCAL_PROJECT_NAME} PRIVATE OpenCVPlugin)

# Safe to statically link the main executable
target_link_options(${LOCAL_PROJECT_NAME} PRIVATE -static-libgcc -static-libstdc++) 


####################
#   Post-Build     #
####################

# Automatically copy the Images folder to the build/bin output directory
add_custom_command(TARGET ${LOCAL_PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_CURRENT_SOURCE_DIR}/Images"
        "${CMAKE_CURRENT_BINARY_DIR}/bin/Images"
)
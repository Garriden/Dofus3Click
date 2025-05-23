####################
#      Global      #
####################

cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 20)



#####################
#      Project      #
#####################

# Project variables
set(LOCAL_PROJECT_NAME        "Dofus3Click")
set(LOCAL_PROJECT_VERSION     "0.90.0")
set(LOCAL_PROJECT_DESCRIPTION "Migration to Dofus3")

# Header files (relative to "include" directory)
set(HEADERS
    basicOperations.hpp
    checks.hpp
    checksRoadmap.hpp
    fight.hpp
    roadmap.hpp
    utils.hpp
    menuMappings.hpp
    menus.hpp
    menusInterface.hpp
    train.hpp
    zaap.hpp
    system/inputs.hpp
    system/file.hpp
    system/actualTime.hpp
    fightStrategy/fightStrategy.hpp
    fightStrategy/professionMobStrategy.hpp
    fightStrategy/fecaAgiBruteStrategy.hpp
)

# Source files (relative to "src" directory)
set(SOURCES
    main.cpp
    
    basicOperations.cpp
    checks.cpp
    checksRoadmap.cpp
    fight.cpp
    menusInterface.cpp
    menus.cpp
    roadmap.cpp
    train.cpp
    zaap.cpp
    system/inputs.cpp
    system/file.cpp
    system/actualTime.cpp
    fightStrategy/fightStrategy.cpp
    fightStrategy/professionMobStrategy.cpp
    fightStrategy/fecaAgiBruteStrategy.cpp
)

# Compiler definitions
set(DEFINES

)

# Compiler options
set(OPTIONS

)

# Project setup
project(${LOCAL_PROJECT_NAME}
        VERSION ${LOCAL_PROJECT_VERSION}
        DESCRIPTION ${LOCAL_PROJECT_DESCRIPTION}
        LANGUAGES CXX)

add_executable(${LOCAL_PROJECT_NAME})

list(TRANSFORM HEADERS PREPEND "include/")
list(TRANSFORM SOURCES PREPEND "src/")

target_include_directories(${LOCAL_PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_sources(${LOCAL_PROJECT_NAME} PRIVATE ${SOURCES} ${HEADERS})
target_compile_definitions(${LOCAL_PROJECT_NAME} PRIVATE ${DEFINES})
target_compile_options(${LOCAL_PROJECT_NAME} PRIVATE ${OPTIONS})

set_target_properties(${LOCAL_PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "bin")



####################
#   Dependencies   #
####################
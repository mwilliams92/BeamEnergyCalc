# Specify the minimum version of CMake
cmake_minimum_required(VERSION 3.0)

# Set the project name and version
project(BeamEnergyCalc VERSION 1.0)

# Add an option to enable/disable debugging
option(DEBUG "Enable debugging" OFF)

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)

# Specify the directories for header files
include_directories(include)

# Add the source files in the src directory
add_executable(CalcEnergy
    main.cpp
    src/CreateGraph.cpp
	src/IsotopeData.cpp
	src/EnergyCalculation.cpp
)

# Find ROOT and link against it
find_package(ROOT REQUIRED)
include_directories(${ROOT_INCLUDE_DIRS})
target_link_libraries(CalcEnergy PRIVATE ${ROOT_LIBRARIES})

# Enable debugging if the DEBUG option is set
if(DEBUG)
    target_compile_definitions(CalcEnergy PUBLIC DEBUG)
endif()

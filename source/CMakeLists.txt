cmake_minimum_required(VERSION 3.10)

# Set the project name
project(HotelDescansoGarantido)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(HotelDescansoGarantido main.cpp)

# Include directories (if you have header files, you can add them here)
include_directories(${PROJECT_SOURCE_DIR})

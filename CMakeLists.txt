cmake_minimum_required(VERSION 3.12)

project(app)

# Set the C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create a target for the executable
add_executable(${CMAKE_PROJECT_NAME} main.cpp include/json_wrapper.cpp)

# Include the 'include' directory for header files
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE include)

# Fetch and make the nlohmann/json library available
include(FetchContent)
FetchContent_Declare(
    nlohmann_json
    URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz
)
FetchContent_MakeAvailable(nlohmann_json)

# Find and link the libcurl library
find_package(CURL REQUIRED)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE nlohmann_json ${CURL_LIBRARIES})

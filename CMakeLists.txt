cmake_minimum_required(VERSION 3.11.3)

project(emotion_detector)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++17 -pthread")

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIBRARY_DIRS})
add_definitions(${OpenCV_DEFINITIONS})

# Find all executables
file(GLOB project_SRCS src/*)

# Add project executable
add_executable(emotion_detector ${project_SRCS})
target_link_libraries(emotion_detector ${OpenCV_LIBRARIES})

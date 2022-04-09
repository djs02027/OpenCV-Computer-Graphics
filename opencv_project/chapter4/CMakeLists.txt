cmake_minimum_required(VERSION 3.12)

set(PROJECT_NAME chapter4)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

file(GLOB SOURCES  *.cpp)
 
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
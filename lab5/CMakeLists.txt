cmake_minimum_required(VERSION 3.26)
project(lab5)

set(CMAKE_CXX_STANDARD 11)
set(ENV{OPENCV_DIR} "C:\tools\\opencv\\build")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(lab5 main.cpp)

set(OpenCV_LIBS opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs)

target_link_libraries(lab5 ${OpenCV_LIBS})

cmake_minimum_required(VERSION 3.25)
project(Work_with_Files LANGUAGES CXX)
set(CMAKE_BUILD_TYPE RELEASE)
set(CMAKE_CXX_FLAGS_RELEASE "-flto=auto -O3 -funroll-loops -march=znver3")
include_directories(Include)
file(GLOB SOURCES "src/*.cpp")
add_executable(Work_with_Files ${SOURCES})
file(COPY ${CMAKE_SOURCE_DIR}/src/testas.txt
     DESTINATION ${CMAKE_BINARY_DIR}/src)


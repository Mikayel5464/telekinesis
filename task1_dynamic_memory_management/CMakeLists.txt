cmake_minimum_required(VERSION 3.0.0)
project(DMM VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

include_directories(headers)
add_executable(DMM src/dmm.cpp src/main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

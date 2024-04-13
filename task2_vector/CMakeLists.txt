cmake_minimum_required(VERSION 3.0.0)
project(vector VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

include_directories(headers)
add_executable(vector src/main.cpp src/vector.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

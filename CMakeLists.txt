cmake_minimum_required(VERSION 3.0.0)
project(ThreadTypeSelector VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(ThreadTypeSelector main.cpp)
target_include_directories(ThreadTypeSelector PUBLIC ${CMAKE_SOURCE_DIR})
target_compile_features(ThreadTypeSelector PUBLIC cxx_std_17)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

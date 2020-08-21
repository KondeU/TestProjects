cmake_minimum_required(VERSION 3.16)

project(TestCase)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE TCS_SRC src/*.h src/*.hpp src/*.cpp)
option(USE_SOURCE_GROUP "Use source_group to classify files" ON)
if(USE_SOURCE_GROUP)
  source_group("sources" FILES ${TCS_SRC})
endif()

add_subdirectory(../TestFramework TestFramework)

add_executable(TestCase ${TCS_SRC})
target_link_libraries(TestCase TestFramework)

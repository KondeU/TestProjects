cmake_minimum_required(VERSION 3.16)

project(TestFramework)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(USE_SOURCE_GROUP "Use source_group to classify files" ON)

file(GLOB_RECURSE 3RD_INC 3rd/CConfig/source/CConfig.h)
file(GLOB_RECURSE 3RD_SRC 3rd/CConfig/source/CConfig.cpp)

file(GLOB_RECURSE TFS_INC inc/*.h)
file(GLOB_RECURSE TFS_SRC src/*.h src/*.hpp src/*.cpp)

if(USE_SOURCE_GROUP)
  source_group("include" FILES ${TFS_INC} ${3RD_INC})
  source_group("sources" FILES ${TFS_SRC} ${3RD_SRC})
endif()

add_library(TestFramework STATIC ${TFS_SRC} ${3RD_SRC} ${TFS_INC} ${3RD_INC})

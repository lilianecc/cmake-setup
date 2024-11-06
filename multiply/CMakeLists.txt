#add_library(multiply multiply.cpp)
#target_include_directories(multiply PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
cmake_minimum_required(VERSION 3.18)
project(multiplyProject)

message(STATUS "====MULTIPLY build")

add_library(multiplyLib multiply.cpp multiply.h)
add_library(additionLib addition.cpp addition.h)
add_library(mainFunction main.cpp)
add_library(arhlib arh.cpp arh.h)

target_include_directories(multiplyLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(additionLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
message(STATUS "===== ${CMAKE_CURRENT_SOURCE_DIR} =====")
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
set(SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

add_executable(multiplyProject ${SOURCE})


target_link_libraries(multiplyProject
  #GTest::gtest_main #this works
  multiplyLib
  additionLib
#   ${CMAKE_CURRENT_SOURCE_DIR}/build/Debug/multiply.lib
)

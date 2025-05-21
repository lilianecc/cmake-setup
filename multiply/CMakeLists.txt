#add_library(multiply multiply.cpp)
#target_include_directories(multiply PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
cmake_minimum_required(VERSION 3.18)
project(multiplyProject)
enable_testing()

set(GTEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../googletest-1.14.x/googletest)
message(STATUS "=================== ${CMAKE_CURRENT_SOURCE_DIR}")
set(GTEST_INCLUDE_DIRECTORIES ${GTEST_DIR}/include ${GTEST_DIR}/src ${GTEST_DIR})
add_library(gtest_mainFUN ${GTEST_DIR}/src/gtest-all.cc ${GTEST_DIR}/src/gtest_main.cc)
include_directories(src ${GTEST_INCLUDE_DIRECTORIES})


message(STATUS "====MULTIPLY build")

add_library(multiplyLib multiply.cpp multiply.h ${CMAKE_CURRENT_SOURCE_DIR})
add_library(additionLib addition.cpp addition.h)
add_library(mainFunction main.cpp)
add_library(arhlib arh.cpp arh.h)
add_library(BitTestingLib bitTesting.cpp bitTesting.h ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(multiplyLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(additionLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
message(STATUS "===== ${CMAKE_CURRENT_SOURCE_DIR} =====")
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
set(SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
list(APPEND SOURCE chronoTest.h chronoTest.cpp)
add_executable(multiplyProject ${SOURCE})


target_link_libraries(multiplyProject
  #GTest::gtest_main #this works
  multiplyLib
  additionLib
  BitTestingLib
  #   ${CMAKE_CURRENT_SOURCE_DIR}/build/Debug/multiply.lib
)

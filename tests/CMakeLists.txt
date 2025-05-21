cmake_minimum_required(VERSION 3.16)
project(MultiplyTest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
# find_package(multiply REQUIRED)####
enable_testing()
include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.11.0
  #SOURCE_DIR ${CMAKE_SOURCE_DIR}/../googletest-1.14.x
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(addition_test addition_test.cpp)
target_link_libraries(addition_test
  GTest::GTest
  additionLib
)
add_test(addition_gtests addition_test)
message(STATUS "====MULTIPLY test!!")
##### related to the target folder#####
add_executable(multiply_test multiply_test.cpp)
target_link_libraries(multiply_test
  GTest::GTest
  multiplyLib
)
include(CTest)

add_test(multiply_gtests multiply_test --gtest_color=yes)
# set(gtest_color "yes")
# to execute>> ctest -V
# On Linux I can produce color googletest output with CTest, like this:
# GTEST_COLOR=1 ctest -V


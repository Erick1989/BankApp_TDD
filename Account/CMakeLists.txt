cmake_minimum_required(VERSION 3.0.0)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(runTestsAccount UnitTestsAccount.cpp Account.cpp)
target_link_libraries(runTestsAccount ${GTEST_LIBRARIES} pthread)
set_target_properties(runTestsAccount PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/tests")

add_library(Account Account.cpp)
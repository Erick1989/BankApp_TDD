cmake_minimum_required(VERSION 3.0.0)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(runTestsDb UnitTestsDb.cpp BankDatabase.cpp FileHandler.cpp)
set_target_properties(runTestsDb PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/tests")
target_link_libraries(runTestsDb ${GTEST_LIBRARIES} pthread)
target_link_libraries(runTestsDb Account)


add_library(Database UnitTestsDb.cpp BankDatabase.cpp FileHandler.cpp)
target_link_libraries(Database Account)
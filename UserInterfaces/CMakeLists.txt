cmake_minimum_required(VERSION 3.0.0)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(runTestsUserInterface 
               UnitTestsUserInterfaces.cpp 
               UserInterface.cpp
               Utility.cpp
               "Screens/Deposit.cpp"
               "Screens/BalanceEnquire.cpp"
               "Screens/OpenAccount.cpp"
               "Screens/Withdrawal.cpp"
               "Screens/ShowAllAccounts.cpp"
               "Screens/CloseAccount.cpp"
               )
set_target_properties(runTestsUserInterface PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/tests")
target_link_libraries(runTestsUserInterface ${GTEST_LIBRARIES} pthread)
target_link_libraries(runTestsUserInterface Database Account)

add_library(UserInterface 
                UserInterface.cpp
                Utility.cpp
                "Screens/Deposit.cpp"
                "Screens/BalanceEnquire.cpp"
                "Screens/OpenAccount.cpp"
                "Screens/Withdrawal.cpp"
                "Screens/ShowAllAccounts.cpp"
                "Screens/CloseAccount.cpp"
                "Screens/StartUi.cpp"
                )
target_link_libraries(UserInterface Database Account)
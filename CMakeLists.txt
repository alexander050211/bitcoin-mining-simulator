cmake_minimum_required(VERSION 3.10)
project(ProjectName)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 14)

# Add source files
set(SOURCE_FILES
    Account.cpp
    Block.cpp
    Blockchain.cpp
    Interface.cpp
    SHA256.cpp
    Transaction.cpp)

add_executable(ProjectName ${SOURCE_FILES} main.cpp)

# Add Google Test
add_subdirectory(googletest)

# Add test files
enable_testing()

add_executable(dummyTest tests/test_dummy.cpp)
target_link_libraries(dummyTest gtest gtest_main)
add_test(NAME dummyTest COMMAND dummyTest)

add_executable(addTransactionTest tests/test_addTransaction.cpp ${SOURCE_FILES})
target_link_libraries(addTransactionTest gtest gtest_main)
add_test(NAME addTransactionTest COMMAND addTransactionTest)

add_executable(createAccountTest tests/test_createAccount.cpp ${SOURCE_FILES})
target_link_libraries(createAccountTest gtest gtest_main)
add_test(NAME createAccountTest COMMAND createAccountTest)

add_executable(getBalanceTest tests/test_getBalance.cpp ${SOURCE_FILES})
target_link_libraries(getBalanceTest gtest gtest_main)
add_test(NAME getBalanceTest COMMAND getBalanceTest)

add_executable(addBlockTest tests/test_addBlock.cpp ${SOURCE_FILES})
target_link_libraries(addBlockTest gtest gtest_main)
add_test(NAME addBlockTest COMMAND addBlockTest)
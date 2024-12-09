# CMake generated Testfile for 
# Source directory: /mnt/c/github/computer-programming/bitcoin-mining-simulator
# Build directory: /mnt/c/github/computer-programming/bitcoin-mining-simulator/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(dummyTest "/mnt/c/github/computer-programming/bitcoin-mining-simulator/build/dummyTest")
set_tests_properties(dummyTest PROPERTIES  _BACKTRACE_TRIPLES "/mnt/c/github/computer-programming/bitcoin-mining-simulator/CMakeLists.txt;26;add_test;/mnt/c/github/computer-programming/bitcoin-mining-simulator/CMakeLists.txt;0;")
add_test(addTransactionTest "/mnt/c/github/computer-programming/bitcoin-mining-simulator/build/addTransactionTest")
set_tests_properties(addTransactionTest PROPERTIES  _BACKTRACE_TRIPLES "/mnt/c/github/computer-programming/bitcoin-mining-simulator/CMakeLists.txt;30;add_test;/mnt/c/github/computer-programming/bitcoin-mining-simulator/CMakeLists.txt;0;")
add_test(createAccountTest "/mnt/c/github/computer-programming/bitcoin-mining-simulator/build/createAccountTest")
set_tests_properties(createAccountTest PROPERTIES  _BACKTRACE_TRIPLES "/mnt/c/github/computer-programming/bitcoin-mining-simulator/CMakeLists.txt;34;add_test;/mnt/c/github/computer-programming/bitcoin-mining-simulator/CMakeLists.txt;0;")
add_test(getBalanceTest "/mnt/c/github/computer-programming/bitcoin-mining-simulator/build/getBalanceTest")
set_tests_properties(getBalanceTest PROPERTIES  _BACKTRACE_TRIPLES "/mnt/c/github/computer-programming/bitcoin-mining-simulator/CMakeLists.txt;38;add_test;/mnt/c/github/computer-programming/bitcoin-mining-simulator/CMakeLists.txt;0;")
add_test(addBlockTest "/mnt/c/github/computer-programming/bitcoin-mining-simulator/build/addBlockTest")
set_tests_properties(addBlockTest PROPERTIES  _BACKTRACE_TRIPLES "/mnt/c/github/computer-programming/bitcoin-mining-simulator/CMakeLists.txt;42;add_test;/mnt/c/github/computer-programming/bitcoin-mining-simulator/CMakeLists.txt;0;")
subdirs("googletest")

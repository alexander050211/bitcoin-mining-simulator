# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/github/computer-programming/bitcoin-mining-simulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/github/computer-programming/bitcoin-mining-simulator/build

# Include any dependencies generated for this target.
include CMakeFiles/getBalanceTest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/getBalanceTest.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/getBalanceTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/getBalanceTest.dir/flags.make

CMakeFiles/getBalanceTest.dir/tests/test_getBalance.cpp.o: CMakeFiles/getBalanceTest.dir/flags.make
CMakeFiles/getBalanceTest.dir/tests/test_getBalance.cpp.o: ../tests/test_getBalance.cpp
CMakeFiles/getBalanceTest.dir/tests/test_getBalance.cpp.o: CMakeFiles/getBalanceTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/github/computer-programming/bitcoin-mining-simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/getBalanceTest.dir/tests/test_getBalance.cpp.o"
	/home/alex0211/miniforge3/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/getBalanceTest.dir/tests/test_getBalance.cpp.o -MF CMakeFiles/getBalanceTest.dir/tests/test_getBalance.cpp.o.d -o CMakeFiles/getBalanceTest.dir/tests/test_getBalance.cpp.o -c /mnt/c/github/computer-programming/bitcoin-mining-simulator/tests/test_getBalance.cpp

CMakeFiles/getBalanceTest.dir/tests/test_getBalance.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/getBalanceTest.dir/tests/test_getBalance.cpp.i"
	/home/alex0211/miniforge3/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/github/computer-programming/bitcoin-mining-simulator/tests/test_getBalance.cpp > CMakeFiles/getBalanceTest.dir/tests/test_getBalance.cpp.i

CMakeFiles/getBalanceTest.dir/tests/test_getBalance.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/getBalanceTest.dir/tests/test_getBalance.cpp.s"
	/home/alex0211/miniforge3/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/github/computer-programming/bitcoin-mining-simulator/tests/test_getBalance.cpp -o CMakeFiles/getBalanceTest.dir/tests/test_getBalance.cpp.s

CMakeFiles/getBalanceTest.dir/Account.cpp.o: CMakeFiles/getBalanceTest.dir/flags.make
CMakeFiles/getBalanceTest.dir/Account.cpp.o: ../Account.cpp
CMakeFiles/getBalanceTest.dir/Account.cpp.o: CMakeFiles/getBalanceTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/github/computer-programming/bitcoin-mining-simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/getBalanceTest.dir/Account.cpp.o"
	/home/alex0211/miniforge3/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/getBalanceTest.dir/Account.cpp.o -MF CMakeFiles/getBalanceTest.dir/Account.cpp.o.d -o CMakeFiles/getBalanceTest.dir/Account.cpp.o -c /mnt/c/github/computer-programming/bitcoin-mining-simulator/Account.cpp

CMakeFiles/getBalanceTest.dir/Account.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/getBalanceTest.dir/Account.cpp.i"
	/home/alex0211/miniforge3/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/github/computer-programming/bitcoin-mining-simulator/Account.cpp > CMakeFiles/getBalanceTest.dir/Account.cpp.i

CMakeFiles/getBalanceTest.dir/Account.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/getBalanceTest.dir/Account.cpp.s"
	/home/alex0211/miniforge3/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/github/computer-programming/bitcoin-mining-simulator/Account.cpp -o CMakeFiles/getBalanceTest.dir/Account.cpp.s

CMakeFiles/getBalanceTest.dir/Block.cpp.o: CMakeFiles/getBalanceTest.dir/flags.make
CMakeFiles/getBalanceTest.dir/Block.cpp.o: ../Block.cpp
CMakeFiles/getBalanceTest.dir/Block.cpp.o: CMakeFiles/getBalanceTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/github/computer-programming/bitcoin-mining-simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/getBalanceTest.dir/Block.cpp.o"
	/home/alex0211/miniforge3/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/getBalanceTest.dir/Block.cpp.o -MF CMakeFiles/getBalanceTest.dir/Block.cpp.o.d -o CMakeFiles/getBalanceTest.dir/Block.cpp.o -c /mnt/c/github/computer-programming/bitcoin-mining-simulator/Block.cpp

CMakeFiles/getBalanceTest.dir/Block.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/getBalanceTest.dir/Block.cpp.i"
	/home/alex0211/miniforge3/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/github/computer-programming/bitcoin-mining-simulator/Block.cpp > CMakeFiles/getBalanceTest.dir/Block.cpp.i

CMakeFiles/getBalanceTest.dir/Block.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/getBalanceTest.dir/Block.cpp.s"
	/home/alex0211/miniforge3/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/github/computer-programming/bitcoin-mining-simulator/Block.cpp -o CMakeFiles/getBalanceTest.dir/Block.cpp.s

CMakeFiles/getBalanceTest.dir/Blockchain.cpp.o: CMakeFiles/getBalanceTest.dir/flags.make
CMakeFiles/getBalanceTest.dir/Blockchain.cpp.o: ../Blockchain.cpp
CMakeFiles/getBalanceTest.dir/Blockchain.cpp.o: CMakeFiles/getBalanceTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/github/computer-programming/bitcoin-mining-simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/getBalanceTest.dir/Blockchain.cpp.o"
	/home/alex0211/miniforge3/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/getBalanceTest.dir/Blockchain.cpp.o -MF CMakeFiles/getBalanceTest.dir/Blockchain.cpp.o.d -o CMakeFiles/getBalanceTest.dir/Blockchain.cpp.o -c /mnt/c/github/computer-programming/bitcoin-mining-simulator/Blockchain.cpp

CMakeFiles/getBalanceTest.dir/Blockchain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/getBalanceTest.dir/Blockchain.cpp.i"
	/home/alex0211/miniforge3/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/github/computer-programming/bitcoin-mining-simulator/Blockchain.cpp > CMakeFiles/getBalanceTest.dir/Blockchain.cpp.i

CMakeFiles/getBalanceTest.dir/Blockchain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/getBalanceTest.dir/Blockchain.cpp.s"
	/home/alex0211/miniforge3/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/github/computer-programming/bitcoin-mining-simulator/Blockchain.cpp -o CMakeFiles/getBalanceTest.dir/Blockchain.cpp.s

CMakeFiles/getBalanceTest.dir/Interface.cpp.o: CMakeFiles/getBalanceTest.dir/flags.make
CMakeFiles/getBalanceTest.dir/Interface.cpp.o: ../Interface.cpp
CMakeFiles/getBalanceTest.dir/Interface.cpp.o: CMakeFiles/getBalanceTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/github/computer-programming/bitcoin-mining-simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/getBalanceTest.dir/Interface.cpp.o"
	/home/alex0211/miniforge3/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/getBalanceTest.dir/Interface.cpp.o -MF CMakeFiles/getBalanceTest.dir/Interface.cpp.o.d -o CMakeFiles/getBalanceTest.dir/Interface.cpp.o -c /mnt/c/github/computer-programming/bitcoin-mining-simulator/Interface.cpp

CMakeFiles/getBalanceTest.dir/Interface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/getBalanceTest.dir/Interface.cpp.i"
	/home/alex0211/miniforge3/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/github/computer-programming/bitcoin-mining-simulator/Interface.cpp > CMakeFiles/getBalanceTest.dir/Interface.cpp.i

CMakeFiles/getBalanceTest.dir/Interface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/getBalanceTest.dir/Interface.cpp.s"
	/home/alex0211/miniforge3/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/github/computer-programming/bitcoin-mining-simulator/Interface.cpp -o CMakeFiles/getBalanceTest.dir/Interface.cpp.s

CMakeFiles/getBalanceTest.dir/SHA256.cpp.o: CMakeFiles/getBalanceTest.dir/flags.make
CMakeFiles/getBalanceTest.dir/SHA256.cpp.o: ../SHA256.cpp
CMakeFiles/getBalanceTest.dir/SHA256.cpp.o: CMakeFiles/getBalanceTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/github/computer-programming/bitcoin-mining-simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/getBalanceTest.dir/SHA256.cpp.o"
	/home/alex0211/miniforge3/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/getBalanceTest.dir/SHA256.cpp.o -MF CMakeFiles/getBalanceTest.dir/SHA256.cpp.o.d -o CMakeFiles/getBalanceTest.dir/SHA256.cpp.o -c /mnt/c/github/computer-programming/bitcoin-mining-simulator/SHA256.cpp

CMakeFiles/getBalanceTest.dir/SHA256.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/getBalanceTest.dir/SHA256.cpp.i"
	/home/alex0211/miniforge3/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/github/computer-programming/bitcoin-mining-simulator/SHA256.cpp > CMakeFiles/getBalanceTest.dir/SHA256.cpp.i

CMakeFiles/getBalanceTest.dir/SHA256.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/getBalanceTest.dir/SHA256.cpp.s"
	/home/alex0211/miniforge3/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/github/computer-programming/bitcoin-mining-simulator/SHA256.cpp -o CMakeFiles/getBalanceTest.dir/SHA256.cpp.s

CMakeFiles/getBalanceTest.dir/Transaction.cpp.o: CMakeFiles/getBalanceTest.dir/flags.make
CMakeFiles/getBalanceTest.dir/Transaction.cpp.o: ../Transaction.cpp
CMakeFiles/getBalanceTest.dir/Transaction.cpp.o: CMakeFiles/getBalanceTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/github/computer-programming/bitcoin-mining-simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/getBalanceTest.dir/Transaction.cpp.o"
	/home/alex0211/miniforge3/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/getBalanceTest.dir/Transaction.cpp.o -MF CMakeFiles/getBalanceTest.dir/Transaction.cpp.o.d -o CMakeFiles/getBalanceTest.dir/Transaction.cpp.o -c /mnt/c/github/computer-programming/bitcoin-mining-simulator/Transaction.cpp

CMakeFiles/getBalanceTest.dir/Transaction.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/getBalanceTest.dir/Transaction.cpp.i"
	/home/alex0211/miniforge3/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/github/computer-programming/bitcoin-mining-simulator/Transaction.cpp > CMakeFiles/getBalanceTest.dir/Transaction.cpp.i

CMakeFiles/getBalanceTest.dir/Transaction.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/getBalanceTest.dir/Transaction.cpp.s"
	/home/alex0211/miniforge3/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/github/computer-programming/bitcoin-mining-simulator/Transaction.cpp -o CMakeFiles/getBalanceTest.dir/Transaction.cpp.s

# Object files for target getBalanceTest
getBalanceTest_OBJECTS = \
"CMakeFiles/getBalanceTest.dir/tests/test_getBalance.cpp.o" \
"CMakeFiles/getBalanceTest.dir/Account.cpp.o" \
"CMakeFiles/getBalanceTest.dir/Block.cpp.o" \
"CMakeFiles/getBalanceTest.dir/Blockchain.cpp.o" \
"CMakeFiles/getBalanceTest.dir/Interface.cpp.o" \
"CMakeFiles/getBalanceTest.dir/SHA256.cpp.o" \
"CMakeFiles/getBalanceTest.dir/Transaction.cpp.o"

# External object files for target getBalanceTest
getBalanceTest_EXTERNAL_OBJECTS =

getBalanceTest: CMakeFiles/getBalanceTest.dir/tests/test_getBalance.cpp.o
getBalanceTest: CMakeFiles/getBalanceTest.dir/Account.cpp.o
getBalanceTest: CMakeFiles/getBalanceTest.dir/Block.cpp.o
getBalanceTest: CMakeFiles/getBalanceTest.dir/Blockchain.cpp.o
getBalanceTest: CMakeFiles/getBalanceTest.dir/Interface.cpp.o
getBalanceTest: CMakeFiles/getBalanceTest.dir/SHA256.cpp.o
getBalanceTest: CMakeFiles/getBalanceTest.dir/Transaction.cpp.o
getBalanceTest: CMakeFiles/getBalanceTest.dir/build.make
getBalanceTest: lib/libgtest.a
getBalanceTest: lib/libgtest_main.a
getBalanceTest: lib/libgtest.a
getBalanceTest: CMakeFiles/getBalanceTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/github/computer-programming/bitcoin-mining-simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable getBalanceTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/getBalanceTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/getBalanceTest.dir/build: getBalanceTest
.PHONY : CMakeFiles/getBalanceTest.dir/build

CMakeFiles/getBalanceTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/getBalanceTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/getBalanceTest.dir/clean

CMakeFiles/getBalanceTest.dir/depend:
	cd /mnt/c/github/computer-programming/bitcoin-mining-simulator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/github/computer-programming/bitcoin-mining-simulator /mnt/c/github/computer-programming/bitcoin-mining-simulator /mnt/c/github/computer-programming/bitcoin-mining-simulator/build /mnt/c/github/computer-programming/bitcoin-mining-simulator/build /mnt/c/github/computer-programming/bitcoin-mining-simulator/build/CMakeFiles/getBalanceTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/getBalanceTest.dir/depend


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
include CMakeFiles/addBlockTest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/addBlockTest.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/addBlockTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/addBlockTest.dir/flags.make

CMakeFiles/addBlockTest.dir/tests/test_addBlock.cpp.o: CMakeFiles/addBlockTest.dir/flags.make
CMakeFiles/addBlockTest.dir/tests/test_addBlock.cpp.o: ../tests/test_addBlock.cpp
CMakeFiles/addBlockTest.dir/tests/test_addBlock.cpp.o: CMakeFiles/addBlockTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/github/computer-programming/bitcoin-mining-simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/addBlockTest.dir/tests/test_addBlock.cpp.o"
	/home/alex0211/miniforge3/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/addBlockTest.dir/tests/test_addBlock.cpp.o -MF CMakeFiles/addBlockTest.dir/tests/test_addBlock.cpp.o.d -o CMakeFiles/addBlockTest.dir/tests/test_addBlock.cpp.o -c /mnt/c/github/computer-programming/bitcoin-mining-simulator/tests/test_addBlock.cpp

CMakeFiles/addBlockTest.dir/tests/test_addBlock.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/addBlockTest.dir/tests/test_addBlock.cpp.i"
	/home/alex0211/miniforge3/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/github/computer-programming/bitcoin-mining-simulator/tests/test_addBlock.cpp > CMakeFiles/addBlockTest.dir/tests/test_addBlock.cpp.i

CMakeFiles/addBlockTest.dir/tests/test_addBlock.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/addBlockTest.dir/tests/test_addBlock.cpp.s"
	/home/alex0211/miniforge3/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/github/computer-programming/bitcoin-mining-simulator/tests/test_addBlock.cpp -o CMakeFiles/addBlockTest.dir/tests/test_addBlock.cpp.s

CMakeFiles/addBlockTest.dir/Account.cpp.o: CMakeFiles/addBlockTest.dir/flags.make
CMakeFiles/addBlockTest.dir/Account.cpp.o: ../Account.cpp
CMakeFiles/addBlockTest.dir/Account.cpp.o: CMakeFiles/addBlockTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/github/computer-programming/bitcoin-mining-simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/addBlockTest.dir/Account.cpp.o"
	/home/alex0211/miniforge3/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/addBlockTest.dir/Account.cpp.o -MF CMakeFiles/addBlockTest.dir/Account.cpp.o.d -o CMakeFiles/addBlockTest.dir/Account.cpp.o -c /mnt/c/github/computer-programming/bitcoin-mining-simulator/Account.cpp

CMakeFiles/addBlockTest.dir/Account.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/addBlockTest.dir/Account.cpp.i"
	/home/alex0211/miniforge3/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/github/computer-programming/bitcoin-mining-simulator/Account.cpp > CMakeFiles/addBlockTest.dir/Account.cpp.i

CMakeFiles/addBlockTest.dir/Account.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/addBlockTest.dir/Account.cpp.s"
	/home/alex0211/miniforge3/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/github/computer-programming/bitcoin-mining-simulator/Account.cpp -o CMakeFiles/addBlockTest.dir/Account.cpp.s

CMakeFiles/addBlockTest.dir/Block.cpp.o: CMakeFiles/addBlockTest.dir/flags.make
CMakeFiles/addBlockTest.dir/Block.cpp.o: ../Block.cpp
CMakeFiles/addBlockTest.dir/Block.cpp.o: CMakeFiles/addBlockTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/github/computer-programming/bitcoin-mining-simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/addBlockTest.dir/Block.cpp.o"
	/home/alex0211/miniforge3/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/addBlockTest.dir/Block.cpp.o -MF CMakeFiles/addBlockTest.dir/Block.cpp.o.d -o CMakeFiles/addBlockTest.dir/Block.cpp.o -c /mnt/c/github/computer-programming/bitcoin-mining-simulator/Block.cpp

CMakeFiles/addBlockTest.dir/Block.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/addBlockTest.dir/Block.cpp.i"
	/home/alex0211/miniforge3/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/github/computer-programming/bitcoin-mining-simulator/Block.cpp > CMakeFiles/addBlockTest.dir/Block.cpp.i

CMakeFiles/addBlockTest.dir/Block.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/addBlockTest.dir/Block.cpp.s"
	/home/alex0211/miniforge3/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/github/computer-programming/bitcoin-mining-simulator/Block.cpp -o CMakeFiles/addBlockTest.dir/Block.cpp.s

CMakeFiles/addBlockTest.dir/Blockchain.cpp.o: CMakeFiles/addBlockTest.dir/flags.make
CMakeFiles/addBlockTest.dir/Blockchain.cpp.o: ../Blockchain.cpp
CMakeFiles/addBlockTest.dir/Blockchain.cpp.o: CMakeFiles/addBlockTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/github/computer-programming/bitcoin-mining-simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/addBlockTest.dir/Blockchain.cpp.o"
	/home/alex0211/miniforge3/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/addBlockTest.dir/Blockchain.cpp.o -MF CMakeFiles/addBlockTest.dir/Blockchain.cpp.o.d -o CMakeFiles/addBlockTest.dir/Blockchain.cpp.o -c /mnt/c/github/computer-programming/bitcoin-mining-simulator/Blockchain.cpp

CMakeFiles/addBlockTest.dir/Blockchain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/addBlockTest.dir/Blockchain.cpp.i"
	/home/alex0211/miniforge3/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/github/computer-programming/bitcoin-mining-simulator/Blockchain.cpp > CMakeFiles/addBlockTest.dir/Blockchain.cpp.i

CMakeFiles/addBlockTest.dir/Blockchain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/addBlockTest.dir/Blockchain.cpp.s"
	/home/alex0211/miniforge3/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/github/computer-programming/bitcoin-mining-simulator/Blockchain.cpp -o CMakeFiles/addBlockTest.dir/Blockchain.cpp.s

CMakeFiles/addBlockTest.dir/Interface.cpp.o: CMakeFiles/addBlockTest.dir/flags.make
CMakeFiles/addBlockTest.dir/Interface.cpp.o: ../Interface.cpp
CMakeFiles/addBlockTest.dir/Interface.cpp.o: CMakeFiles/addBlockTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/github/computer-programming/bitcoin-mining-simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/addBlockTest.dir/Interface.cpp.o"
	/home/alex0211/miniforge3/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/addBlockTest.dir/Interface.cpp.o -MF CMakeFiles/addBlockTest.dir/Interface.cpp.o.d -o CMakeFiles/addBlockTest.dir/Interface.cpp.o -c /mnt/c/github/computer-programming/bitcoin-mining-simulator/Interface.cpp

CMakeFiles/addBlockTest.dir/Interface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/addBlockTest.dir/Interface.cpp.i"
	/home/alex0211/miniforge3/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/github/computer-programming/bitcoin-mining-simulator/Interface.cpp > CMakeFiles/addBlockTest.dir/Interface.cpp.i

CMakeFiles/addBlockTest.dir/Interface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/addBlockTest.dir/Interface.cpp.s"
	/home/alex0211/miniforge3/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/github/computer-programming/bitcoin-mining-simulator/Interface.cpp -o CMakeFiles/addBlockTest.dir/Interface.cpp.s

CMakeFiles/addBlockTest.dir/SHA256.cpp.o: CMakeFiles/addBlockTest.dir/flags.make
CMakeFiles/addBlockTest.dir/SHA256.cpp.o: ../SHA256.cpp
CMakeFiles/addBlockTest.dir/SHA256.cpp.o: CMakeFiles/addBlockTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/github/computer-programming/bitcoin-mining-simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/addBlockTest.dir/SHA256.cpp.o"
	/home/alex0211/miniforge3/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/addBlockTest.dir/SHA256.cpp.o -MF CMakeFiles/addBlockTest.dir/SHA256.cpp.o.d -o CMakeFiles/addBlockTest.dir/SHA256.cpp.o -c /mnt/c/github/computer-programming/bitcoin-mining-simulator/SHA256.cpp

CMakeFiles/addBlockTest.dir/SHA256.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/addBlockTest.dir/SHA256.cpp.i"
	/home/alex0211/miniforge3/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/github/computer-programming/bitcoin-mining-simulator/SHA256.cpp > CMakeFiles/addBlockTest.dir/SHA256.cpp.i

CMakeFiles/addBlockTest.dir/SHA256.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/addBlockTest.dir/SHA256.cpp.s"
	/home/alex0211/miniforge3/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/github/computer-programming/bitcoin-mining-simulator/SHA256.cpp -o CMakeFiles/addBlockTest.dir/SHA256.cpp.s

CMakeFiles/addBlockTest.dir/Transaction.cpp.o: CMakeFiles/addBlockTest.dir/flags.make
CMakeFiles/addBlockTest.dir/Transaction.cpp.o: ../Transaction.cpp
CMakeFiles/addBlockTest.dir/Transaction.cpp.o: CMakeFiles/addBlockTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/github/computer-programming/bitcoin-mining-simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/addBlockTest.dir/Transaction.cpp.o"
	/home/alex0211/miniforge3/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/addBlockTest.dir/Transaction.cpp.o -MF CMakeFiles/addBlockTest.dir/Transaction.cpp.o.d -o CMakeFiles/addBlockTest.dir/Transaction.cpp.o -c /mnt/c/github/computer-programming/bitcoin-mining-simulator/Transaction.cpp

CMakeFiles/addBlockTest.dir/Transaction.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/addBlockTest.dir/Transaction.cpp.i"
	/home/alex0211/miniforge3/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/github/computer-programming/bitcoin-mining-simulator/Transaction.cpp > CMakeFiles/addBlockTest.dir/Transaction.cpp.i

CMakeFiles/addBlockTest.dir/Transaction.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/addBlockTest.dir/Transaction.cpp.s"
	/home/alex0211/miniforge3/bin/x86_64-conda-linux-gnu-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/github/computer-programming/bitcoin-mining-simulator/Transaction.cpp -o CMakeFiles/addBlockTest.dir/Transaction.cpp.s

# Object files for target addBlockTest
addBlockTest_OBJECTS = \
"CMakeFiles/addBlockTest.dir/tests/test_addBlock.cpp.o" \
"CMakeFiles/addBlockTest.dir/Account.cpp.o" \
"CMakeFiles/addBlockTest.dir/Block.cpp.o" \
"CMakeFiles/addBlockTest.dir/Blockchain.cpp.o" \
"CMakeFiles/addBlockTest.dir/Interface.cpp.o" \
"CMakeFiles/addBlockTest.dir/SHA256.cpp.o" \
"CMakeFiles/addBlockTest.dir/Transaction.cpp.o"

# External object files for target addBlockTest
addBlockTest_EXTERNAL_OBJECTS =

addBlockTest: CMakeFiles/addBlockTest.dir/tests/test_addBlock.cpp.o
addBlockTest: CMakeFiles/addBlockTest.dir/Account.cpp.o
addBlockTest: CMakeFiles/addBlockTest.dir/Block.cpp.o
addBlockTest: CMakeFiles/addBlockTest.dir/Blockchain.cpp.o
addBlockTest: CMakeFiles/addBlockTest.dir/Interface.cpp.o
addBlockTest: CMakeFiles/addBlockTest.dir/SHA256.cpp.o
addBlockTest: CMakeFiles/addBlockTest.dir/Transaction.cpp.o
addBlockTest: CMakeFiles/addBlockTest.dir/build.make
addBlockTest: lib/libgtest.a
addBlockTest: lib/libgtest_main.a
addBlockTest: lib/libgtest.a
addBlockTest: CMakeFiles/addBlockTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/github/computer-programming/bitcoin-mining-simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable addBlockTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/addBlockTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/addBlockTest.dir/build: addBlockTest
.PHONY : CMakeFiles/addBlockTest.dir/build

CMakeFiles/addBlockTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/addBlockTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/addBlockTest.dir/clean

CMakeFiles/addBlockTest.dir/depend:
	cd /mnt/c/github/computer-programming/bitcoin-mining-simulator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/github/computer-programming/bitcoin-mining-simulator /mnt/c/github/computer-programming/bitcoin-mining-simulator /mnt/c/github/computer-programming/bitcoin-mining-simulator/build /mnt/c/github/computer-programming/bitcoin-mining-simulator/build /mnt/c/github/computer-programming/bitcoin-mining-simulator/build/CMakeFiles/addBlockTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/addBlockTest.dir/depend


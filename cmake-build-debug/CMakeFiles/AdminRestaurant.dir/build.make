# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2024.1.2\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2024.1.2\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\mmoor\CLionProjects\AdminRestaurant

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\mmoor\CLionProjects\AdminRestaurant\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/AdminRestaurant.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/AdminRestaurant.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/AdminRestaurant.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AdminRestaurant.dir/flags.make

CMakeFiles/AdminRestaurant.dir/main.cpp.obj: CMakeFiles/AdminRestaurant.dir/flags.make
CMakeFiles/AdminRestaurant.dir/main.cpp.obj: C:/Users/mmoor/CLionProjects/AdminRestaurant/main.cpp
CMakeFiles/AdminRestaurant.dir/main.cpp.obj: CMakeFiles/AdminRestaurant.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\mmoor\CLionProjects\AdminRestaurant\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AdminRestaurant.dir/main.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AdminRestaurant.dir/main.cpp.obj -MF CMakeFiles\AdminRestaurant.dir\main.cpp.obj.d -o CMakeFiles\AdminRestaurant.dir\main.cpp.obj -c C:\Users\mmoor\CLionProjects\AdminRestaurant\main.cpp

CMakeFiles/AdminRestaurant.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/AdminRestaurant.dir/main.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mmoor\CLionProjects\AdminRestaurant\main.cpp > CMakeFiles\AdminRestaurant.dir\main.cpp.i

CMakeFiles/AdminRestaurant.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/AdminRestaurant.dir/main.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\mmoor\CLionProjects\AdminRestaurant\main.cpp -o CMakeFiles\AdminRestaurant.dir\main.cpp.s

# Object files for target AdminRestaurant
AdminRestaurant_OBJECTS = \
"CMakeFiles/AdminRestaurant.dir/main.cpp.obj"

# External object files for target AdminRestaurant
AdminRestaurant_EXTERNAL_OBJECTS =

AdminRestaurant.exe: CMakeFiles/AdminRestaurant.dir/main.cpp.obj
AdminRestaurant.exe: CMakeFiles/AdminRestaurant.dir/build.make
AdminRestaurant.exe: CMakeFiles/AdminRestaurant.dir/linkLibs.rsp
AdminRestaurant.exe: CMakeFiles/AdminRestaurant.dir/objects1.rsp
AdminRestaurant.exe: CMakeFiles/AdminRestaurant.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\mmoor\CLionProjects\AdminRestaurant\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable AdminRestaurant.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\AdminRestaurant.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AdminRestaurant.dir/build: AdminRestaurant.exe
.PHONY : CMakeFiles/AdminRestaurant.dir/build

CMakeFiles/AdminRestaurant.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\AdminRestaurant.dir\cmake_clean.cmake
.PHONY : CMakeFiles/AdminRestaurant.dir/clean

CMakeFiles/AdminRestaurant.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\mmoor\CLionProjects\AdminRestaurant C:\Users\mmoor\CLionProjects\AdminRestaurant C:\Users\mmoor\CLionProjects\AdminRestaurant\cmake-build-debug C:\Users\mmoor\CLionProjects\AdminRestaurant\cmake-build-debug C:\Users\mmoor\CLionProjects\AdminRestaurant\cmake-build-debug\CMakeFiles\AdminRestaurant.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/AdminRestaurant.dir/depend


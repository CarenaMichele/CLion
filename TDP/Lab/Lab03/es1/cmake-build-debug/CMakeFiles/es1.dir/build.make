# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.3.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\DELL\Desktop\C\Lab03\es1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\DELL\Desktop\C\Lab03\es1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/es1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/es1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/es1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/es1.dir/flags.make

CMakeFiles/es1.dir/main.c.obj: CMakeFiles/es1.dir/flags.make
CMakeFiles/es1.dir/main.c.obj: ../main.c
CMakeFiles/es1.dir/main.c.obj: CMakeFiles/es1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\DELL\Desktop\C\Lab03\es1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/es1.dir/main.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/es1.dir/main.c.obj -MF CMakeFiles\es1.dir\main.c.obj.d -o CMakeFiles\es1.dir\main.c.obj -c C:\Users\DELL\Desktop\C\Lab03\es1\main.c

CMakeFiles/es1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/es1.dir/main.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\DELL\Desktop\C\Lab03\es1\main.c > CMakeFiles\es1.dir\main.c.i

CMakeFiles/es1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/es1.dir/main.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\DELL\Desktop\C\Lab03\es1\main.c -o CMakeFiles\es1.dir\main.c.s

# Object files for target es1
es1_OBJECTS = \
"CMakeFiles/es1.dir/main.c.obj"

# External object files for target es1
es1_EXTERNAL_OBJECTS =

es1.exe: CMakeFiles/es1.dir/main.c.obj
es1.exe: CMakeFiles/es1.dir/build.make
es1.exe: CMakeFiles/es1.dir/linklibs.rsp
es1.exe: CMakeFiles/es1.dir/objects1.rsp
es1.exe: CMakeFiles/es1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\DELL\Desktop\C\Lab03\es1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable es1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\es1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/es1.dir/build: es1.exe
.PHONY : CMakeFiles/es1.dir/build

CMakeFiles/es1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\es1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/es1.dir/clean

CMakeFiles/es1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\DELL\Desktop\C\Lab03\es1 C:\Users\DELL\Desktop\C\Lab03\es1 C:\Users\DELL\Desktop\C\Lab03\es1\cmake-build-debug C:\Users\DELL\Desktop\C\Lab03\es1\cmake-build-debug C:\Users\DELL\Desktop\C\Lab03\es1\cmake-build-debug\CMakeFiles\es1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/es1.dir/depend


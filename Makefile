# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = "/home/shersula/Рабочий стол/msgsep/msgbl"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/shersula/Рабочий стол/msgsep/msgbl"

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start "/home/shersula/Рабочий стол/msgsep/msgbl/CMakeFiles" "/home/shersula/Рабочий стол/msgsep/msgbl//CMakeFiles/progress.marks"
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start "/home/shersula/Рабочий стол/msgsep/msgbl/CMakeFiles" 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named MSGSeparator

# Build rule for target.
MSGSeparator: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 MSGSeparator
.PHONY : MSGSeparator

# fast build rule for target.
MSGSeparator/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MSGSeparator.dir/build.make CMakeFiles/MSGSeparator.dir/build
.PHONY : MSGSeparator/fast

SDK/amxplugin.o: SDK/amxplugin.cpp.o

.PHONY : SDK/amxplugin.o

# target to build an object file
SDK/amxplugin.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MSGSeparator.dir/build.make CMakeFiles/MSGSeparator.dir/SDK/amxplugin.cpp.o
.PHONY : SDK/amxplugin.cpp.o

SDK/amxplugin.i: SDK/amxplugin.cpp.i

.PHONY : SDK/amxplugin.i

# target to preprocess a source file
SDK/amxplugin.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MSGSeparator.dir/build.make CMakeFiles/MSGSeparator.dir/SDK/amxplugin.cpp.i
.PHONY : SDK/amxplugin.cpp.i

SDK/amxplugin.s: SDK/amxplugin.cpp.s

.PHONY : SDK/amxplugin.s

# target to generate assembly for a file
SDK/amxplugin.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MSGSeparator.dir/build.make CMakeFiles/MSGSeparator.dir/SDK/amxplugin.cpp.s
.PHONY : SDK/amxplugin.cpp.s

SDK/sampgdk/sampgdk.o: SDK/sampgdk/sampgdk.c.o

.PHONY : SDK/sampgdk/sampgdk.o

# target to build an object file
SDK/sampgdk/sampgdk.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MSGSeparator.dir/build.make CMakeFiles/MSGSeparator.dir/SDK/sampgdk/sampgdk.c.o
.PHONY : SDK/sampgdk/sampgdk.c.o

SDK/sampgdk/sampgdk.i: SDK/sampgdk/sampgdk.c.i

.PHONY : SDK/sampgdk/sampgdk.i

# target to preprocess a source file
SDK/sampgdk/sampgdk.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MSGSeparator.dir/build.make CMakeFiles/MSGSeparator.dir/SDK/sampgdk/sampgdk.c.i
.PHONY : SDK/sampgdk/sampgdk.c.i

SDK/sampgdk/sampgdk.s: SDK/sampgdk/sampgdk.c.s

.PHONY : SDK/sampgdk/sampgdk.s

# target to generate assembly for a file
SDK/sampgdk/sampgdk.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MSGSeparator.dir/build.make CMakeFiles/MSGSeparator.dir/SDK/sampgdk/sampgdk.c.s
.PHONY : SDK/sampgdk/sampgdk.c.s

Source/Separator.o: Source/Separator.cpp.o

.PHONY : Source/Separator.o

# target to build an object file
Source/Separator.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MSGSeparator.dir/build.make CMakeFiles/MSGSeparator.dir/Source/Separator.cpp.o
.PHONY : Source/Separator.cpp.o

Source/Separator.i: Source/Separator.cpp.i

.PHONY : Source/Separator.i

# target to preprocess a source file
Source/Separator.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MSGSeparator.dir/build.make CMakeFiles/MSGSeparator.dir/Source/Separator.cpp.i
.PHONY : Source/Separator.cpp.i

Source/Separator.s: Source/Separator.cpp.s

.PHONY : Source/Separator.s

# target to generate assembly for a file
Source/Separator.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MSGSeparator.dir/build.make CMakeFiles/MSGSeparator.dir/Source/Separator.cpp.s
.PHONY : Source/Separator.cpp.s

dllmain.o: dllmain.cpp.o

.PHONY : dllmain.o

# target to build an object file
dllmain.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MSGSeparator.dir/build.make CMakeFiles/MSGSeparator.dir/dllmain.cpp.o
.PHONY : dllmain.cpp.o

dllmain.i: dllmain.cpp.i

.PHONY : dllmain.i

# target to preprocess a source file
dllmain.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MSGSeparator.dir/build.make CMakeFiles/MSGSeparator.dir/dllmain.cpp.i
.PHONY : dllmain.cpp.i

dllmain.s: dllmain.cpp.s

.PHONY : dllmain.s

# target to generate assembly for a file
dllmain.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MSGSeparator.dir/build.make CMakeFiles/MSGSeparator.dir/dllmain.cpp.s
.PHONY : dllmain.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... MSGSeparator"
	@echo "... SDK/amxplugin.o"
	@echo "... SDK/amxplugin.i"
	@echo "... SDK/amxplugin.s"
	@echo "... SDK/sampgdk/sampgdk.o"
	@echo "... SDK/sampgdk/sampgdk.i"
	@echo "... SDK/sampgdk/sampgdk.s"
	@echo "... Source/Separator.o"
	@echo "... Source/Separator.i"
	@echo "... Source/Separator.s"
	@echo "... dllmain.o"
	@echo "... dllmain.i"
	@echo "... dllmain.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system


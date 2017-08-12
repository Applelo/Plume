# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.9.0/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.9.0/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Applelo/Documents/Git/Plume

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Applelo/Documents/Git/Plume

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/Cellar/cmake/3.9.0/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/local/Cellar/cmake/3.9.0/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/Applelo/Documents/Git/Plume/CMakeFiles /Users/Applelo/Documents/Git/Plume/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/Applelo/Documents/Git/Plume/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named send_vpk

# Build rule for target.
send_vpk: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 send_vpk
.PHONY : send_vpk

# fast build rule for target.
send_vpk/fast:
	$(MAKE) -f CMakeFiles/send_vpk.dir/build.make CMakeFiles/send_vpk.dir/build
.PHONY : send_vpk/fast

#=============================================================================
# Target rules for targets named copy

# Build rule for target.
copy: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 copy
.PHONY : copy

# fast build rule for target.
copy/fast:
	$(MAKE) -f CMakeFiles/copy.dir/build.make CMakeFiles/copy.dir/build
.PHONY : copy/fast

#=============================================================================
# Target rules for targets named Plume.vpk

# Build rule for target.
Plume.vpk: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Plume.vpk
.PHONY : Plume.vpk

# fast build rule for target.
Plume.vpk/fast:
	$(MAKE) -f CMakeFiles/Plume.vpk.dir/build.make CMakeFiles/Plume.vpk.dir/build
.PHONY : Plume.vpk/fast

#=============================================================================
# Target rules for targets named eboot.bin

# Build rule for target.
eboot.bin: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 eboot.bin
.PHONY : eboot.bin

# fast build rule for target.
eboot.bin/fast:
	$(MAKE) -f CMakeFiles/eboot.bin.dir/build.make CMakeFiles/eboot.bin.dir/build
.PHONY : eboot.bin/fast

#=============================================================================
# Target rules for targets named send

# Build rule for target.
send: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 send
.PHONY : send

# fast build rule for target.
send/fast:
	$(MAKE) -f CMakeFiles/send.dir/build.make CMakeFiles/send.dir/build
.PHONY : send/fast

#=============================================================================
# Target rules for targets named copy_vpk

# Build rule for target.
copy_vpk: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 copy_vpk
.PHONY : copy_vpk

# fast build rule for target.
copy_vpk/fast:
	$(MAKE) -f CMakeFiles/copy_vpk.dir/build.make CMakeFiles/copy_vpk.dir/build
.PHONY : copy_vpk/fast

#=============================================================================
# Target rules for targets named Plume

# Build rule for target.
Plume: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Plume
.PHONY : Plume

# fast build rule for target.
Plume/fast:
	$(MAKE) -f CMakeFiles/Plume.dir/build.make CMakeFiles/Plume.dir/build
.PHONY : Plume/fast

src/Block.obj: src/Block.cpp.obj

.PHONY : src/Block.obj

# target to build an object file
src/Block.cpp.obj:
	$(MAKE) -f CMakeFiles/Plume.dir/build.make CMakeFiles/Plume.dir/src/Block.cpp.obj
.PHONY : src/Block.cpp.obj

src/Block.i: src/Block.cpp.i

.PHONY : src/Block.i

# target to preprocess a source file
src/Block.cpp.i:
	$(MAKE) -f CMakeFiles/Plume.dir/build.make CMakeFiles/Plume.dir/src/Block.cpp.i
.PHONY : src/Block.cpp.i

src/Block.s: src/Block.cpp.s

.PHONY : src/Block.s

# target to generate assembly for a file
src/Block.cpp.s:
	$(MAKE) -f CMakeFiles/Plume.dir/build.make CMakeFiles/Plume.dir/src/Block.cpp.s
.PHONY : src/Block.cpp.s

src/Buttons.obj: src/Buttons.cpp.obj

.PHONY : src/Buttons.obj

# target to build an object file
src/Buttons.cpp.obj:
	$(MAKE) -f CMakeFiles/Plume.dir/build.make CMakeFiles/Plume.dir/src/Buttons.cpp.obj
.PHONY : src/Buttons.cpp.obj

src/Buttons.i: src/Buttons.cpp.i

.PHONY : src/Buttons.i

# target to preprocess a source file
src/Buttons.cpp.i:
	$(MAKE) -f CMakeFiles/Plume.dir/build.make CMakeFiles/Plume.dir/src/Buttons.cpp.i
.PHONY : src/Buttons.cpp.i

src/Buttons.s: src/Buttons.cpp.s

.PHONY : src/Buttons.s

# target to generate assembly for a file
src/Buttons.cpp.s:
	$(MAKE) -f CMakeFiles/Plume.dir/build.make CMakeFiles/Plume.dir/src/Buttons.cpp.s
.PHONY : src/Buttons.cpp.s

src/Cloud.obj: src/Cloud.cpp.obj

.PHONY : src/Cloud.obj

# target to build an object file
src/Cloud.cpp.obj:
	$(MAKE) -f CMakeFiles/Plume.dir/build.make CMakeFiles/Plume.dir/src/Cloud.cpp.obj
.PHONY : src/Cloud.cpp.obj

src/Cloud.i: src/Cloud.cpp.i

.PHONY : src/Cloud.i

# target to preprocess a source file
src/Cloud.cpp.i:
	$(MAKE) -f CMakeFiles/Plume.dir/build.make CMakeFiles/Plume.dir/src/Cloud.cpp.i
.PHONY : src/Cloud.cpp.i

src/Cloud.s: src/Cloud.cpp.s

.PHONY : src/Cloud.s

# target to generate assembly for a file
src/Cloud.cpp.s:
	$(MAKE) -f CMakeFiles/Plume.dir/build.make CMakeFiles/Plume.dir/src/Cloud.cpp.s
.PHONY : src/Cloud.cpp.s

src/Engine.obj: src/Engine.cpp.obj

.PHONY : src/Engine.obj

# target to build an object file
src/Engine.cpp.obj:
	$(MAKE) -f CMakeFiles/Plume.dir/build.make CMakeFiles/Plume.dir/src/Engine.cpp.obj
.PHONY : src/Engine.cpp.obj

src/Engine.i: src/Engine.cpp.i

.PHONY : src/Engine.i

# target to preprocess a source file
src/Engine.cpp.i:
	$(MAKE) -f CMakeFiles/Plume.dir/build.make CMakeFiles/Plume.dir/src/Engine.cpp.i
.PHONY : src/Engine.cpp.i

src/Engine.s: src/Engine.cpp.s

.PHONY : src/Engine.s

# target to generate assembly for a file
src/Engine.cpp.s:
	$(MAKE) -f CMakeFiles/Plume.dir/build.make CMakeFiles/Plume.dir/src/Engine.cpp.s
.PHONY : src/Engine.cpp.s

src/Grass.obj: src/Grass.cpp.obj

.PHONY : src/Grass.obj

# target to build an object file
src/Grass.cpp.obj:
	$(MAKE) -f CMakeFiles/Plume.dir/build.make CMakeFiles/Plume.dir/src/Grass.cpp.obj
.PHONY : src/Grass.cpp.obj

src/Grass.i: src/Grass.cpp.i

.PHONY : src/Grass.i

# target to preprocess a source file
src/Grass.cpp.i:
	$(MAKE) -f CMakeFiles/Plume.dir/build.make CMakeFiles/Plume.dir/src/Grass.cpp.i
.PHONY : src/Grass.cpp.i

src/Grass.s: src/Grass.cpp.s

.PHONY : src/Grass.s

# target to generate assembly for a file
src/Grass.cpp.s:
	$(MAKE) -f CMakeFiles/Plume.dir/build.make CMakeFiles/Plume.dir/src/Grass.cpp.s
.PHONY : src/Grass.cpp.s

src/Grid.obj: src/Grid.cpp.obj

.PHONY : src/Grid.obj

# target to build an object file
src/Grid.cpp.obj:
	$(MAKE) -f CMakeFiles/Plume.dir/build.make CMakeFiles/Plume.dir/src/Grid.cpp.obj
.PHONY : src/Grid.cpp.obj

src/Grid.i: src/Grid.cpp.i

.PHONY : src/Grid.i

# target to preprocess a source file
src/Grid.cpp.i:
	$(MAKE) -f CMakeFiles/Plume.dir/build.make CMakeFiles/Plume.dir/src/Grid.cpp.i
.PHONY : src/Grid.cpp.i

src/Grid.s: src/Grid.cpp.s

.PHONY : src/Grid.s

# target to generate assembly for a file
src/Grid.cpp.s:
	$(MAKE) -f CMakeFiles/Plume.dir/build.make CMakeFiles/Plume.dir/src/Grid.cpp.s
.PHONY : src/Grid.cpp.s

src/Menu.obj: src/Menu.cpp.obj

.PHONY : src/Menu.obj

# target to build an object file
src/Menu.cpp.obj:
	$(MAKE) -f CMakeFiles/Plume.dir/build.make CMakeFiles/Plume.dir/src/Menu.cpp.obj
.PHONY : src/Menu.cpp.obj

src/Menu.i: src/Menu.cpp.i

.PHONY : src/Menu.i

# target to preprocess a source file
src/Menu.cpp.i:
	$(MAKE) -f CMakeFiles/Plume.dir/build.make CMakeFiles/Plume.dir/src/Menu.cpp.i
.PHONY : src/Menu.cpp.i

src/Menu.s: src/Menu.cpp.s

.PHONY : src/Menu.s

# target to generate assembly for a file
src/Menu.cpp.s:
	$(MAKE) -f CMakeFiles/Plume.dir/build.make CMakeFiles/Plume.dir/src/Menu.cpp.s
.PHONY : src/Menu.cpp.s

src/Plume.obj: src/Plume.cpp.obj

.PHONY : src/Plume.obj

# target to build an object file
src/Plume.cpp.obj:
	$(MAKE) -f CMakeFiles/Plume.dir/build.make CMakeFiles/Plume.dir/src/Plume.cpp.obj
.PHONY : src/Plume.cpp.obj

src/Plume.i: src/Plume.cpp.i

.PHONY : src/Plume.i

# target to preprocess a source file
src/Plume.cpp.i:
	$(MAKE) -f CMakeFiles/Plume.dir/build.make CMakeFiles/Plume.dir/src/Plume.cpp.i
.PHONY : src/Plume.cpp.i

src/Plume.s: src/Plume.cpp.s

.PHONY : src/Plume.s

# target to generate assembly for a file
src/Plume.cpp.s:
	$(MAKE) -f CMakeFiles/Plume.dir/build.make CMakeFiles/Plume.dir/src/Plume.cpp.s
.PHONY : src/Plume.cpp.s

src/Splash.obj: src/Splash.cpp.obj

.PHONY : src/Splash.obj

# target to build an object file
src/Splash.cpp.obj:
	$(MAKE) -f CMakeFiles/Plume.dir/build.make CMakeFiles/Plume.dir/src/Splash.cpp.obj
.PHONY : src/Splash.cpp.obj

src/Splash.i: src/Splash.cpp.i

.PHONY : src/Splash.i

# target to preprocess a source file
src/Splash.cpp.i:
	$(MAKE) -f CMakeFiles/Plume.dir/build.make CMakeFiles/Plume.dir/src/Splash.cpp.i
.PHONY : src/Splash.cpp.i

src/Splash.s: src/Splash.cpp.s

.PHONY : src/Splash.s

# target to generate assembly for a file
src/Splash.cpp.s:
	$(MAKE) -f CMakeFiles/Plume.dir/build.make CMakeFiles/Plume.dir/src/Splash.cpp.s
.PHONY : src/Splash.cpp.s

src/Timer.obj: src/Timer.cpp.obj

.PHONY : src/Timer.obj

# target to build an object file
src/Timer.cpp.obj:
	$(MAKE) -f CMakeFiles/Plume.dir/build.make CMakeFiles/Plume.dir/src/Timer.cpp.obj
.PHONY : src/Timer.cpp.obj

src/Timer.i: src/Timer.cpp.i

.PHONY : src/Timer.i

# target to preprocess a source file
src/Timer.cpp.i:
	$(MAKE) -f CMakeFiles/Plume.dir/build.make CMakeFiles/Plume.dir/src/Timer.cpp.i
.PHONY : src/Timer.cpp.i

src/Timer.s: src/Timer.cpp.s

.PHONY : src/Timer.s

# target to generate assembly for a file
src/Timer.cpp.s:
	$(MAKE) -f CMakeFiles/Plume.dir/build.make CMakeFiles/Plume.dir/src/Timer.cpp.s
.PHONY : src/Timer.cpp.s

src/main.obj: src/main.cpp.obj

.PHONY : src/main.obj

# target to build an object file
src/main.cpp.obj:
	$(MAKE) -f CMakeFiles/Plume.dir/build.make CMakeFiles/Plume.dir/src/main.cpp.obj
.PHONY : src/main.cpp.obj

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/Plume.dir/build.make CMakeFiles/Plume.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/Plume.dir/build.make CMakeFiles/Plume.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... send_vpk"
	@echo "... copy"
	@echo "... Plume.vpk"
	@echo "... eboot.bin"
	@echo "... send"
	@echo "... copy_vpk"
	@echo "... Plume"
	@echo "... src/Block.obj"
	@echo "... src/Block.i"
	@echo "... src/Block.s"
	@echo "... src/Buttons.obj"
	@echo "... src/Buttons.i"
	@echo "... src/Buttons.s"
	@echo "... src/Cloud.obj"
	@echo "... src/Cloud.i"
	@echo "... src/Cloud.s"
	@echo "... src/Engine.obj"
	@echo "... src/Engine.i"
	@echo "... src/Engine.s"
	@echo "... src/Grass.obj"
	@echo "... src/Grass.i"
	@echo "... src/Grass.s"
	@echo "... src/Grid.obj"
	@echo "... src/Grid.i"
	@echo "... src/Grid.s"
	@echo "... src/Menu.obj"
	@echo "... src/Menu.i"
	@echo "... src/Menu.s"
	@echo "... src/Plume.obj"
	@echo "... src/Plume.i"
	@echo "... src/Plume.s"
	@echo "... src/Splash.obj"
	@echo "... src/Splash.i"
	@echo "... src/Splash.s"
	@echo "... src/Timer.obj"
	@echo "... src/Timer.i"
	@echo "... src/Timer.s"
	@echo "... src/main.obj"
	@echo "... src/main.i"
	@echo "... src/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system


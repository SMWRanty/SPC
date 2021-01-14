#run the help target if specified with no parameters
default: help

MAKEFILE_DIRECTORY := $(dir $(realpath $(lastword $(MAKEFILE_LIST))))
WORKING_DIRECTORY := $(shell pwd)

#tools to detect the operating system
include make/os.mk
#standard linux command line tools
include make/commands.mk
#environment variable (build directory, library directory, ...)
include make/env.mk
#c++ build tools
include make/c++.mk
#cbunit test utility
include make/cbunit.mk
#cbexpect test utility
include make/cbexpect.mk
#linker build tools
include make/linker.mk
#help targets
include make/help.mk

#library dependencies
include make/libraries.mk
#build targets
include make/targets.mk
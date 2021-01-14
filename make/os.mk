TARGET_OS :=

ifeq ($(OS),Windows_NT)
	TARGET_OS = WIN32
else
	UNIX_NAME = $(shell uname -s)
	ifeq ($(UNIX_NAME),Linux)
		TARGET_OS = LINUX
	endif
	ifeq ($(UNIX_NAME),Darwin)
		TARGET_OS = OSX
	endif
endif


all:
	g++ main.cpp \
		cpu.cpp \
		getters.cpp \
		translate.cpp \
		file-handler.cpp \
		errors.cpp \
		helpers.cpp \
		-o mips-sim -O2 -std=gnu++11 -Wall -Wextra -Wpedantic

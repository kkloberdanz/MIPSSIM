all:
	g++ main.cpp \
		kernel.cpp \
		getters.cpp \
		translate.cpp \
		file-handler.cpp \
		errors.cpp \
		-o mips-sim -O2 -std=gnu++11 -Wall -Wextra -Wpedantic

all:
	g++ getters.cpp \
		translate.cpp \
		file-handler.cpp \
		errors.cpp \
		main.cpp \
		-o mips-sim -O2 -std=gnu++14 -Wall -Wextra -Wpedantic

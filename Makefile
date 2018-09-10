BUILD_FLAGS = -W -Wall -pedantic
CC = g++ -std=c++11
RM = rm
OUT = *.out

all: a.out

a.out: Makefile Main.cpp Sort.cpp UserInput.cpp
	$(CC) $(BUILD_FLAGS) Main.cpp Sort.cpp UserInput.cpp -o a.out

clean:
	$(RM) $(OUT)

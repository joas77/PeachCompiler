OBJECTS= ./build/compiler.o
INCLUDES=-I./include/
CC= g++
FLAGS= -g -std=c++17

all: ${OBJECTS}
	${CC} src/main.cpp ${INCLUDES} ${OBJECTS} ${FLAGS} -o ./peach

./build/compiler.o: src/compiler.cpp
	${CC} src/compiler.cpp ${INCLUDES} ${FLAGS} -o ./build/compiler.o -c

run: all
	./peach

clean: 
	rm ./peach
	rm -rf ${OBJECTS}

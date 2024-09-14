CC = gcc
FLAGS = -std=c11 -Wall

TARGET = src/pi

$(TARGET): src/calc.o src/pi.o src/common.o
	$(CC) $(FLAGS) -o $(TARGET) src/calc.o src/pi.o src/common.o -lm

src/common.o: src/common.h
	$(CC) $(FLAGS) -c src/common.c -o src/common.o

src/calc.o: src/common.h src/utils.h src/calc.h
	$(CC) $(FLAGS) -c src/calc.c -o src/calc.o

src/pi.o: src/calc.h src/common.h src/utils.h
	$(CC) $(FLAGS) -c src/pi.c -o src/pi.o

clean: 
	rm src/*.o 
	rm src/pi


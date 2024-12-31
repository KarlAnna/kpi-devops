CC = g++
CFLAGS = -g -Wall
TARGET = expSeries

all: $(TARGET)

$(TARGET): main.o ExponentialSeries.o
	$(CC) $(CFLAGS) main.o ExponentialSeries.o -o $(TARGET)

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

ExponentialSeries.o: ExponentialSeries.cpp ExponentialSeries.h
	$(CC) $(CFLAGS) -c ExponentialSeries.cpp

clean:
	rm -rf -v *.o $(TARGET)

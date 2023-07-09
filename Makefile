CC = g++
CFLAGS = -std=c++11 -Wall
OBJ = benchmark.o functions.o classes.o
TARGET = benchmark

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

benchmark.o: benchmark.cpp
	$(CC) $(CFLAGS) -c benchmark.cpp -o benchmark.o

functions.o: functions.cpp
	$(CC) $(CFLAGS) -c functions.cpp -o functions.o

classes.o: classes.cpp
	$(CC) $(CFLAGS) -c classes.cpp -o classes.o

clean:
	rm -f $(OBJ) $(TARGET)

clean-results:
	rm ./timeResults/*.csv ./statsResults/*.txt

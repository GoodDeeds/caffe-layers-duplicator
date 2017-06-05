CC = g++
FLAGS = --std=c++11
OBJS = duplicate_prototxt_layers.o

EXECUTABLE = duplicate_prototxt_layers

.PHONY = all clean

all: $(OBJS)
	@echo "Building executable..."
	$(CC) $(FLAGS) -o $(EXECUTABLE) $(OBJS)
	@echo "Done"
	
%.o: %.cpp
	@echo "Building "$*".cpp..."
	$(CC) $(FLAGS) -c $*.cpp
	
clean:
	@echo "Removing object files..."
	-rm -rf *.o
	@echo "Removing executable..."
	-rm -rf $(EXECUTABLE)


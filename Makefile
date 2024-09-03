CC = gcc


CCWARNINGS = -Wall -W
CCOPT = -std=c11 -g

CFLAGS = $(CCWARNINGS) $(CCOPT)

DEMO_SOURCES := io_demo.c io.c
DEMO_OBJECTS := $(DEMO_SOURCES:.c=.o)

MAIN_SOURCES := main.c io.c
MAIN_OBJECTS := $(MAIN_SOURCES:.c=.o)

DEMO_EXECUTABLE = io_demo
MAIN_EXECUTABLE = cmd_int

EXECS = $(DEMO_EXECUTABLE) $(MAIN_EXECUTABLE)

.PHONY: all run-demo run test

all: $(EXECS) 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(DEMO_EXECUTABLE): $(DEMO_OBJECTS)
	$(CC) $(CFLAGS) $(DEMO_OBJECTS) -o $@

$(MAIN_EXECUTABLE): $(MAIN_OBJECTS)
	$(CC) $(CFLAGS) $(MAIN_OBJECTS) -o $@

run-demo: $(DEMO_EXECUTABLE)
	./$(DEMO_EXECUTABLE)

run: $(MAIN_EXECUTABLE)
	./$(MAIN_EXECUTABLE)

test: $(MAIN_EXECUTABLE)
	./test.sh

clean:
	rm -rf *.o *~  

clean-all: clean
	rm -rf $(EXECS) 



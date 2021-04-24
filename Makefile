CC := g++
FLAGS := -lglut -lGLU -lGL

all: 
	$(CC) main.cpp -o fan $(FLAGS)

clean:
	rm -rf fan *.o


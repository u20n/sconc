
# includes
I=-I./lib/core/inc/
# links
L=-L./lib/core/ -lcore

default:
	g++ -std=c++20 main.cpp $(I) -o main.out $(L)

all: obj/main.o obj/Timer.o obj/MultiplyBy2.o
	g++ obj/main.o obj/Timer.o obj/MultiplyBy2.o -o MultiplyBy2

obj/main.o: src/main.cpp inc/Benchmark.hpp inc/Problem.hpp
	g++ -c src/main.cpp -Iinc -o obj/main.o -g -std=c++11
	
obj/Timer.o: src/Timer.cpp inc/Timer.hpp
	g++ -c src/Timer.cpp -Iinc -o obj/Timer.o -g -std=c++11

obj/MultiplyBy2.o: src/MultiplyBy2.cpp inc/MultiplyBy2.hpp
	g++ -c src/MultiplyBy2.cpp -Iinc -o obj/MultiplyBy2.o -std=c++11

clean: 
	rm -rf obj/* MultiplyBy2
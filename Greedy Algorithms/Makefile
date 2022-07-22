CXX = g++
CXXFLAGS = -std=c++17 -g -Wall

main: main.o Mochila.o Objeto.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cc Mochila.h Objeto.h
	$(CXX) -c main.cc

Mochila.o: Mochila.cc Mochila.h
	$(CXX) -c Mochila.cc

Objeto.o: Objeto.cc Objeto.h
	$(CXX) -c Objeto.cc
	
clean:
	rm *.o output.txt
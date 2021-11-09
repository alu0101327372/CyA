CXX = g++
CXXFLAGS = -std=c++11 -g -Wall

p03_string_operations: p03_string_operations.o Alphabet.o String.o Symbol.o
	$(CXX) $(CXXFLAGS) -o $@ $^

p03_string_operations.o: p03_string_operations.cc Alphabet.h String.h Symbol.h
	$(CXX) -c p03_string_operations.cc

Alphabet.o: Alphabet.cc Alphabet.h
	$(CXX) -c Alphabet.cc

String.o: String.cc String.h
	$(CXX) -c String.cc

Symbol.o: Symbol.cc Symbol.h
	$(CXX) -c Symbol.cc
	
clean:
	rm *.o fileout.txt

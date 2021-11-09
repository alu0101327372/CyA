CXX = g++
CXXFLAGS = -std=c++17 -g -Wall

p02_strings: cya-P02-Strings.o Alphabet.o String.o 
	$(CXX) $(CXXFLAGS) -o $@ $^

Alphabet.o: Alphabet.cc Alphabet.h
	$(CXX) -c Alphabet.cc

String.o: String.cc String.h
	$(CXX) -c String.cc

cya-P02-Strings.o: cya-P02-Strings.cc Alphabet.h String.h
	$(CXX) -c cya-P02-Strings.cc

clean:
	rm *.o fileout.txt
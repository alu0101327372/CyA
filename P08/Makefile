CXX = g++
CXXFLAGS = -std=c++11 -g -Wall

p08_grammar: p08_grammar.o Grammar.o Productions.o Alphabet.o
	$(CXX) $(CXXFLAGS) -o $@ $^

p08_grammar.o: p08_grammar.cc Grammar.h Productions.h Alphabet.h
	$(CXX) -c p08_grammar.cc

Grammar.o: Grammar.cc Grammar.h
	$(CXX) -c Grammar.cc

Productions.o: Productions.cc Productions.h
	$(CXX) -c Productions.cc

Alphabet.o: Alphabet.cc Alphabet.h
	$(CXX) -c Alphabet.cc
	
clean:
	rm *.o output.txt
CXX = g++
CXXFLAGS = -std=c++11 -g -Wall

p06_dfa_simulation: p06_dfa_simulation.o Dfa.o State.o Alphabet.o
	$(CXX) $(CXXFLAGS) -o $@ $^

p06_dfa_simulation.o: p06_dfa_simulation.cc Dfa.h State.h Alphabet.h
	$(CXX) -c p06_dfa_simulation.cc

Dfa.o: Dfa.cc Dfa.h
	$(CXX) -c Dfa.cc

State.o: State.cc State.h
	$(CXX) -c State.cc

Alphabet.o: Alphabet.cc Alphabet.h
	$(CXX) -c Alphabet.cc
	
clean:
	rm *.o a.txt
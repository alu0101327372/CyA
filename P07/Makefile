CXX = g++
CXXFLAGS = -std=c++11 -g -Wall

p07_nfa_simulator: p07_nfa_simulator.o Nfa.o State.o Alphabet.o
	$(CXX) $(CXXFLAGS) -o $@ $^

p07_nfa_simulator.o: p07_nfa_simulator.cc Nfa.h State.h Alphabet.h
	$(CXX) -c p07_nfa_simulator.cc

Nfa.o: Nfa.cc Nfa.h
	$(CXX) -c Nfa.cc

State.o: State.cc State.h
	$(CXX) -c State.cc

Alphabet.o: Alphabet.cc Alphabet.h
	$(CXX) -c Alphabet.cc
	
clean:
	rm *.o a.txt
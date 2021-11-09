CXX = g++
CXXFLAGS = -std=c++11 -g -Wall

p05_dna_sequencer: p05_dna_sequencer.o Dfa.o Transicion.o Alfabeto.o
	$(CXX) $(CXXFLAGS) -o $@ $^

p05_dna_sequencer.o: p05_dna_sequencer.cc Dfa.h Transicion.h  Alfabeto.h
	$(CXX) -c p05_dna_sequencer.cc

Dfa.o: Dfa.cc Dfa.h
	$(CXX) -c Dfa.cc

Transicion.o: Transicion.cc Transicion.h
	$(CXX) -c Transicion.cc

Alfabeto.o: Alfabeto.cc Alfabeto.h
	$(CXX) -c Alfabeto.cc
	
clean:
	rm *.o a.txt

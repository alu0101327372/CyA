CXX = g++
CXXFLAGS = -std=c++11 -g -Wall

p04_code_analyzer: p04_code_analyzer.o File.o Variable.o Loop.o Comment.o
	$(CXX) $(CXXFLAGS) -o $@ $^

p04_code_analyzer.o: p04_code_analyzer.cc File.h Variable.h Loop.h Comment.h
	$(CXX) -c p04_code_analyzer.cc

File.o: File.cc File.h
	$(CXX) -c File.cc

Variable.o: Variable.cc Variable.h
	$(CXX) -c Variable.cc

Loop.o: Loop.cc Loop.h
	$(CXX) -c Loop.cc

Comment.o: Comment.cc Comment.h
	$(CXX) -c Comment.cc
	
clean:
	rm *.o fileout.txt
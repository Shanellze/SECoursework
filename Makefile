CXX = g++
CXXFLAGS = -g -Wall -Wextra 

.PHONY: all
all : librarySystem

librarySystem: librarySystem.o 
	$(CXX) $(CXXFLAGS) -o $@ $^

librarySystem.o: librarySystem.cpp librarySystem.h
	$(CXX) $(CXXFLAGS) -c $<

.PHONY : clean
clean:
	$(RM) *~ *.o librarySystem
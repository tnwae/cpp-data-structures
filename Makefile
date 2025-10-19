CXX=g++
CXXFLAGS=-g -Wall -Werror -pedantic -std=c++11

all: blist_tester bstack_tester bqueue_tester

blist_tester: blist_tester.cpp
	$(CXX) $(CXXFLAGS) -o blist_tester blist_tester.cpp

bqueue_tester: bqueue_tester.cpp
	$(CXX) $(CXXFLAGS) -o bqueue_tester bqueue_tester.cpp

bstack_tester: bstack_tester.cpp
	$(CXX) $(CXXFLAGS) -o bstack_tester bstack_tester.cpp

clean:
	-rm -rf a.out blist_tester bstack_tester bqueue_tester

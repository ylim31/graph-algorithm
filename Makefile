EXENAME = main
TEST = test
OBJS = PNG.o HSLAPixel.o lodepng.o main.o graph.o


CXX = clang++
CXXFLAGS = $(CS225) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm

# Custom Clang version enforcement logic:
ccred=$(shell echo -e "\033[0;31m")
ccyellow=$(shell echo -e "\033[0;33m")
ccend=$(shell echo -e "\033[0m")

IS_EWS=$(shell hostname | grep "ews.illinois.edu") 
IS_CORRECT_CLANG=$(shell clang -v 2>&1 | grep "version 6")
ifneq ($(strip $(IS_EWS)),)
ifeq ($(strip $(IS_CORRECT_CLANG)),)
CLANG_VERSION_MSG = $(error $(ccred) On EWS, please run 'module load llvm/6.0.1' first when running CS225 assignments. $(ccend))
endif
else
ifneq ($(strip $(SKIP_EWS_CHECK)),True)
CLANG_VERSION_MSG = $(warning $(ccyellow) Looks like you are not on EWS. Be sure to test on EWS before the deadline. $(ccend))
endif
endif

.PHONY: all test clean output_msg

all : $(EXENAME)

output_msg: ; $(CLANG_VERSION_MSG)

$(EXENAME) : output_msg $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o : main.cpp cs225/PNG.h cs225/HSLAPixel.h cs225/graph.h
	$(CXX) $(CXXFLAGS) main.cpp

PNG.o : cs225/PNG.cpp cs225/PNG.h cs225/HSLAPixel.h cs225/lodepng/lodepng.h
	$(CXX) $(CXXFLAGS) cs225/PNG.cpp

HSLAPixel.o : cs225/HSLAPixel.cpp cs225/HSLAPixel.h
	$(CXX) $(CXXFLAGS) cs225/HSLAPixel.cpp

lodepng.o : cs225/lodepng/lodepng.cpp cs225/lodepng/lodepng.h
	$(CXX) $(CXXFLAGS) cs225/lodepng/lodepng.cpp

graph.o : cs225/graph.cpp cs225/graph.h cs225/edge.h cs225/random.h
	$(CXX) $(CXXFLAGS) cs225/graph.cpp

dijkstra.o : dijkstra.cpp dijkstra.h cs225/graph.h cs225/edge.h include/json.hpp
	$(CXX) $(CXXFLAGS) dijkstra.cpp

landmark.o : landmark.cpp landmark.h cs225/graph.h cs225/edge.h
	$(CXX) $(CXXFLAGS) landmark.cpp
	
bfs.o : bfs.cpp bfs.h cs225/graph.h cs225/edge.h
	$(CXX) $(CXXFLAGS) bfs.cpp


$(TEST): output_msg part1.o bfs_test.o PNG.o HSLAPixel.o lodepng.o cs225/graph.o dijkstra.o bfs.o landmark.o
	$(LD) part1.o PNG.o bfs_test.o HSLAPixel.o lodepng.o cs225/graph.o dijkstra.o bfs.o landmark.o $(LDFLAGS) -o test

part1.o : tests/part1.cpp tests/catch.hpp cs225/PNG.h cs225/HSLAPixel.h cs225/graph.h dijkstra.h
	$(CXX) $(CXXFLAGS) tests/part1.cpp

part2.o : tests/part2.cpp tests/catch.hpp cs225/graph.h landmark.h 
	$(CXX) $(CXXFLAGS) tests/part2.cpp

bfs_test.o : tests/bfs_test.cpp tests/catch.hpp cs225/PNG.h cs225/HSLAPixel.h cs225/graph.h bfs.h
	$(CXX) $(CXXFLAGS) tests/bfs_test.cpp


clean :
	-rm -f *.o $(EXENAME) test
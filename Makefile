EXENAME = main
OBJS = main.o graph.o node.o road.o dijkstra.o welsh.o nodedegreepair.o nodedistpair.o calipng.o PNG.o HSLAPixel.o lodepng.o utils.o

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

main.o : main.cpp graph.cpp node.cpp road.cpp dijkstra.cpp welsh.cpp nodedegreepair.cpp nodedistpair.cpp calipng.cpp cs225/PNG.cpp cs225/HSLAPixel.cpp cs225/lodepng/lodepng.cpp utils.cpp
	$(CXX) $(CXXFLAGS) main.cpp graph.cpp node.cpp road.cpp dijkstra.cpp welsh.cpp nodedegreepair.cpp nodedistpair.cpp calipng.cpp cs225/PNG.cpp cs225/HSLAPixel.cpp cs225/lodepng/lodepng.cpp utils.cpp

test: output_msg catchmain.o tests.o cs225/PNG.cpp cs225/HSLAPixel.cpp cs225/lodepng/lodepng.cpp road.cpp graph.cpp node.cpp dijkstra.cpp welsh.cpp nodedegreepair.cpp nodedistpair.cpp calipng.cpp utils.cpp
	$(LD) catchmain.o tests.o cs225/PNG.cpp cs225/HSLAPixel.cpp cs225/lodepng/lodepng.cpp road.cpp graph.cpp node.cpp dijkstra.cpp welsh.cpp nodedegreepair.cpp nodedistpair.cpp calipng.cpp utils.cpp $(LDFLAGS) -o test

catchmain.o : cs225/catch/catchmain.cpp cs225/catch/catch.hpp
	$(CXX) $(CXXFLAGS) cs225/catch/catchmain.cpp

tests.o : tests/tests.cpp cs225/catch/catch.hpp
	$(CXX) $(CXXFLAGS) tests/tests.cpp

PNG.o : cs225/PNG.cpp cs225/PNG.h cs225/HSLAPixel.h cs225/lodepng/lodepng.h
	$(CXX) $(CXXFLAGS) cs225/PNG.cpp

HSLAPixel.o : cs225/HSLAPixel.cpp cs225/HSLAPixel.h
	$(CXX) $(CXXFLAGS) cs225/HSLAPixel.cpp

lodepng.o : cs225/lodepng/lodepng.cpp cs225/lodepng/lodepng.h
	$(CXX) $(CXXFLAGS) cs225/lodepng/lodepng.cpp

clean :
	-rm -f *.o $(EXENAME) test

# # Executable names:
# EXE = graph
# TEST = test

# # Add all object files needed for compiling:
# EXE_OBJ = main.o
# OBJS = main.o

# # Use the cs225 makefile template:
# include cs225/make/cs225.mk


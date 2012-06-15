################################
## Makefile Template for C++
## Author: mkut
## Date  : 2012-05-17
## Rev   : 0.1.0
################################

## project settings
TARGET = main
SOURCES = main.cpp

## command settings
LD = g++
CXX = g++
CXXFLAGS = -O2
LDFLAGS =

## file name macros
OBJS = $(SOURCES:%.cpp=%.o)

## make rules
.PHONY: default clean

default: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^

clean:
	rm -f *.o $(TARGET) $(OBJS)


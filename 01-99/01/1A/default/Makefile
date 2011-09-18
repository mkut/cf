LD = g++
CXX = g++
PARSER = spparser
CXXFLAGS = 
LDFLAGS =
TARGET = main
OBJS = main.o
ORIGINAL = c++.cpp
SOURCE = main.cpp

cpp: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^

main.o: $(SOURCE)
	$(CXX) $(CXXFLAGS) -o $@ -c $^

$(SOURCE): $(ORIGINAL)
	$(PARSER) $^ $@

clean:
	rm -f *.o $(TARGET) $(SOURCE)

.PHONY: cpp clean


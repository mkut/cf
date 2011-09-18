HC = ghc
CFLAGS = --make -O
TARGET = main
OBJS = haskell.hi haskell.o
SOURCE = haskell.hs

hs: $(TARGET)

$(TARGET): $(SOURCE)
	$(HC) $(CFLAGS) -o $@ $^
	rm $(OBJS)

clean:
	rm -f *.o $(TARGET) $(OBJS)

.PHONY: cpp clean


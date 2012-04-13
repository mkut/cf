HC = ghc
CFLAGS = --make -O
TARGET = main
TARGETS = $(TARGET) gen
OBJS = haskell.hi haskell.o
SOURCE = haskell.hs
GEN_SOURCE = gen.hs
GEN_OBJS = gen.hi gen.o
MILIB_DIR = /home/mkut/milib/haskell
MILIBS = Contest IO Geometry
MILIB_SOURCES = $(MILIBS:%=$(MILIB_DIR)/%.hs)

hs: $(TARGET)

hs2: haskell2.hs $(MILIB_SOURCES)
	$(HC) $(CFLAGS) -o $@ $^

$(TARGET): $(SOURCE)
	$(HC) $(CFLAGS) -o $@ $^
	rm $(OBJS)

gen: $(GEN_SOURCE)
	$(HC) $(CFLAGS) -o $@ $^
	rm $(GEN_OBJS)

clean:
	rm -f *.o $(TARGETS) $(OBJS) $(GEN_OBJS)

.PHONY: cpp clean


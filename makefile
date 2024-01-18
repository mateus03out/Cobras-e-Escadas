TARGERT=CobrasEscadas
CC=g++
DEBUG=-g
CCFLAGS=$(DEBUG)
LD=g++
OBJS=CobrasEscadas.cpp
all: CobrasEscadas.cpp
	$(LD) $(OBJS) -o $(TARGERT)


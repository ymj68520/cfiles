CXX=gcc
FLAG=-fno-asm -O2 -Wall  -std=c11 

SOURCE = $(wildcard *.c)
OBJS:=$(patsubst %c,%o,$(SOURCE))

all:$(OBJS)
$(OBJS):%.o:%.c
	$(CXX) $< -o $@ $(FLAG)
	

.PHONY:clean
clean:
	rm -f *.o 

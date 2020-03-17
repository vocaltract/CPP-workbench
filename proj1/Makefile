CUR_DIR  = $(shell pwd)
VPATH = $(CUR_DIR)/src
OBJS = main.o Block.o tools.o
INCLUDE = -I $(CUR_DIR)/include 
NAME = ./build/snaker.out
CC = g++
CFLAGS = -ggdb $(INCLUDE) -static -o1 -o $(NAME) 

ALL:$(OBJS)
	$(CC) $(CFLAGS) $(OBJS)

tools.o: include/tools.h
Block.o: include/Block.h

.PHONY:clean
clean:
	rm -rf $(OBJS) 
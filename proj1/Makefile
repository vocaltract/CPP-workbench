SRCS := $(wildcard src/*.cpp)
OBJS := $(notdir $(SRCS:.cpp=.o))
INCLUDE := ./include
COMPILE_FLAGS := -I $(INCLUDE) -ggdb -c 
OBJ_DIR = ./build
CXXFLAGS = -static -o0
CXX = g++ 

build/snaker.out:$(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@
Vector2D.o:src/Vector2D.cpp 
	$(CXX) $(COMPILE_FLAGS) $^
Block.o:src/Block.cpp 
	$(CXX) $(COMPILE_FLAGS) $^
Snake.o:src/Snake.cpp 
	$(CXX) $(COMPILE_FLAGS) $^
input.o:src/input.cpp 
	$(CXX) $(COMPILE_FLAGS) $^
Screen.o:src/Screen.cpp 
	$(CXX) $(COMPILE_FLAGS) $^
main.o:src/main.cpp 
	$(CXX) $(COMPILE_FLAGS) $^



.PHONY:clean
clean:
	rm *.o *.out *.aux *.log *.synctex.gz
	rm build/snaker.out
.PHONY:run
run:build/snaker.out
	build/snaker.out



SRCS := $(wildcard src/*.cpp)
OBJS := $(notdir $(SRCS:.cpp=.o))
INCLUDE := ./include
COMPILE_FLAGS := -I $(INCLUDE) -c 
OBJ_DIR = ./build
CXXFLAGS = -ggdb -static
CXX = g++ 
#$(OBJS): $(SRCS)
#	$(CXX) $(COMPILE_FLAGS) $(SRCS) -o $@

build/snaker.out:
	for name in `echo $(SRCS) | sed s/.cpp//g`;\
	do $(CXX) $(COMPILE_FLAGS) "$$name".cpp;done  
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

.PHONY:clean
clean:
	rm *.o
	rm build/snaker.out




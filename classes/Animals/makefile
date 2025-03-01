EXE = tpAnimals
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:%.cpp=%.o)
CC = $(CXX)
all : depend $(EXE)
$(EXE) : $(EXE.o) $(OBJS)
.PHONY : clean
clean :
	rm -f $(OBJS) $(EXE)
depend : $(SRCS) *.h
	$(CC) -MM $(CPPFLAGS) $^ > $@
-include depend
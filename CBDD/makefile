EXE = main
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:%.cpp=%.o)
CC = $(CXX)
LDLIBS = -lmysqlcppconn
all : depend $(EXE)
$(EXE) : $(EXE.o) $(OBJS)
.PHONY : clean
clean :
	rm -f $(OBJS) $(EXE)
depend : $(SRCS) *.h
	$(CC) -MM $(CPPFLAGS) $^ > $@
-include depend
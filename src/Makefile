CPPS = *.cpp 
OBJS = *.o 
DIR = objs 

all:	$(OBJS)
		mv $^ ../$(DIR)

$(OBJS):	$(CPPS)
		g++ -c $^
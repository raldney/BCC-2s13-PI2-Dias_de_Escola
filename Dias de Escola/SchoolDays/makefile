CXX=g++
CFLAGS=
LDFLAGS=-L/usr/lib -lallegro
INCLUDE=-I. -I/usr/include/allegro5

OBJS=SchoolDays.o
OUT=SchoolDays

all: SchoolDays

SchoolDays: $(OBJS)
	$(CXX) $(OBJS) -o $(OUT) $(INCLUDE) $(CFLAGS) $(LDFLAGS)
clean:
	rm -rf *.o SchoolDays

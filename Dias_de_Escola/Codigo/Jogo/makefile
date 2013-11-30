CXX=g++
CFLAGS=
LDFLAGS=-L/usr/lib -lallegro -lallegro_image -lallegro_font -lallegro_ttf
INCLUDE=-I. -I/usr/include/allegro5 -I/usr/include/allegro_image

OBJS=SchoolDays.o
OUT=SchoolDays

all: SchoolDays

SchoolDays: $(OBJS)
	$(CXX) $(OBJS) -o $(OUT) $(INCLUDE) $(CFLAGS) $(LDFLAGS)
clean:
	rm -rf *.o SchoolDays

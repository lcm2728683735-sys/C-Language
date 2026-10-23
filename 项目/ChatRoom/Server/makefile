obj = *.c ../GlobalMessage.c
server: $(obj)
	gcc $(obj) -o server

.PHONY:all clean

all:
	make server

clean:
	rm -f server
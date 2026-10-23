obj = *.c ../GlobalMessage.c
client: $(obj)
	gcc $(obj) -o client

.PHONY:all clean

all:
	make client

clean:
	rm -f client
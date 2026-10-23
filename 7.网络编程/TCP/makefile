obj = StdTcp.c StdThread.c List.c GlobalMessage.c

server:$(obj) server.c
	gcc $(obj) server.c -o server

client:$(obj) client.c
	gcc $(obj) client.c -o client

.PHONY:all clean

all:
	make server
	make client

clean:
	rm -f server client
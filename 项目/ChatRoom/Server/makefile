# 使用 $(wildcard) 函数正确获取当前目录下的所有 .c 文件
src = $(wildcard *.c) ../GlobalMessage.c

server: $(src)
	gcc $(src) -o server -lsqlite3

.PHONY: all clean

all: server

clean:
	rm -f server
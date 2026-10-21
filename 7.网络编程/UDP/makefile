# 定义源码
SRCS = StdThread.c StdUdp.c

all: udp1 udp2

udp1: $(SRCS) test1.c
	gcc $(SRCS) test1.c -o udp1 -lpthread

udp2: $(SRCS) test2.c
	gcc $(SRCS) test2.c -o udp2 -lpthread

.PHONY: all clean

clean:
	rm -f udp1 udp2
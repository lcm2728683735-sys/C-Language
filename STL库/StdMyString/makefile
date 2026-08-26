libMyString.so : StdMyString.cpp
	g++ -shared -fPIC StdMyString.cpp -o libMyString.so




.PhYON: install clean all
install:
	sudo cp libMyString.so /usr/lib
	sudo cp StdMyString.h /usr/include

clean:
	rm -f libMyString.so

all:
	make
	make install
	make clean
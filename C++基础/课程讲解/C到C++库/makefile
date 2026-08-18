libDArray.so : DynamicArray.c
	gcc -shared -fPIC DynamicArray.c -o libDArray.so




.PhYON: install clean
install:
	sudo cp libDArray.so /usr/lib
	sudo cp DynamicArray.h /usr/include

clean:
	rm -f libDArray.so

all:
	make
	make install
	make clean
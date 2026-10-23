.PHONY: all clean

all:
	make all -C Server
	make all -C Client
	mv Server/server ./server
	mv Client/client ./client

clean:
	rm -f client server
	rm -f Client/client Server/server
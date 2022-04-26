.ONESHELL:

all:
	@cd lib
	@gcc -shared -fpic ESNMP.c -o libESNMP.so
	@gcc -shared -fpic ESNMPReceiver.c -o libESNMPReceiver.so

clean:
	@cd lib
	@rm *.so

test:
	@LD_LIBRARY_PATH="$$PWD/lib" perl p.pl

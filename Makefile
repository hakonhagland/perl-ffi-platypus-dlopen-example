.ONESHELL:

all:
	@cd lib
	@gcc -shared -fpic ESNMP.c -o libESNMP.so
	@gcc -shared -fpic ESNMPReceiver.c -o libESNMPReceiver.so

clean:
	@cd lib
	@rm *.so

test:
	@echo "$$PWD"
	@export LD_LIBRARY_PATH="$$PWD/lib"
	@echo "$$LD_LIBRARY_PATH"
	@perl p.pl

all: lscpu_own

lscpu_own: lscpu_own.cpp
	g++ -o lscpu_own lscpu_own.cpp -std=c++17

run: lscpu_own
	./lscpu_own

install: lscpu_own
	cp lscpu_own /usr/local/bin/

uninstall:
	rm -f /usr/local/bin/lscpu_own

clean:
	rm -f lscpu_own

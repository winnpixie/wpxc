all:
	mkdir -p bin
	cc -o bin/wpxc -O2 src/*.c

clean:
	rm -rf bin/

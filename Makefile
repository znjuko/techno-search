format-code:
	./formatter.sh cmd && ./formatter.sh include && ./formatter.sh src && ./formatter.sh tests

build-project:
	rm -rf build && mkdir build && cd build && cmake ..
#&& cmake --build .

run-server:
	./build/cmd/techno_search
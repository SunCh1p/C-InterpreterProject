.PHONY: build run clean

run:
	@./program

build:
	g++ -fdiagnostics-color=always -Wall -g main.cc ./source/tokenizer.cc ./source/token.cc -o program

debug:
	@gdb ./program
clean:
	rm -f ./program
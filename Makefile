#compiler
CXX := g++
CXXFLAGS := -fdiagnostics-color=always -Wall -g
PROGRAM := trivial
#sources
SOURCES:= $(wildcard source/*.cc)
OBJECTS:= $(SOURCES:source/%.cc=obj/%.o)
.PHONY: build run clean

run: build
	@./$(PROGRAM)

#linker logs
build: obj/main.o $(OBJECTS)
	@$(CXX) $(CXXFLAGS) $^ -o $(PROGRAM) > linker.txt

#compile
obj/main.o: main.cc
	@$(CXX) $(CXXFLAGS) -c $< -o $@ > compile.txt

#compile
./obj/%.o: source/%.cc
	@$(CXX) $(CXXFLAGS) -c $< -o $@ > compile_source.txt

debug:
	@gdb ./program

clean:
	@rm -f ./$(PROGRAM) 
	@rm -f ./obj/*.o
	@rm -f ./logs/compile.txt
	@rm -f ./logs/compile_source.txt
	@rm -f ./logs/linker.txt
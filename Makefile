#compiler
CXX := g++
CXXFLAGS := -fdiagnostics-color=always -Wall -g
PROGRAM := trivial
#sources
SOURCES:= $(wildcard source/*.cc)
OBJECTS:= $(SOURCES:source/%.cc=obj/%.o)
.PHONY: build run clean test buildtest

run: build
	@./$(PROGRAM)

#linker logs
build: obj/main.o $(OBJECTS)
	@$(CXX) $(CXXFLAGS) $^ -o $(PROGRAM)

#compile
obj/main.o: main.cc
	@$(CXX) $(CXXFLAGS) -c $< -o $@

#compile
./obj/%.o: source/%.cc
	@$(CXX) $(CXXFLAGS) -c $< -o $@

debug:
	@gdb ./program

test: buildtest
	@./test/testProgram

buildtest: obj/test.o $(OBJECTS)
	@$(CXX) $(CXXFLAGS) $^ -o ./test/testProgram

obj/test.o: test/test.cc
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f ./$(PROGRAM) 
	@rm -f ./obj/*.o
	@rm -f ./test/testProgram
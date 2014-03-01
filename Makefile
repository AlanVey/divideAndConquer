# Makefile for Divide and Conquer
##  LIST - all categories of source
##  TEST - all test related source
##  ANAL - all analyse related source

LDFLAGS = -lm -lstdc++
CXXFLAGS = -Wall -g
CXX=g++

VPATH= c++

# Patterns to collect different categories of target
TEST_PAT := test_\(\w*\)\.cpp
ANAL_PAT := analyse_\(\w*\)\.cpp
PROG_PAT := $(TEST_PAT)\|$(ANAL_PAT)

# Collects all source files
TEST_SRC := $(shell find c++ -name "*.cpp" | grep -e "$(TEST_PAT)")
ANAL_SRC := $(shell find c++ -name "*.cpp" | grep -e "$(ANAL_PAT)")
TASK_SRC := $(shell find c++ -name "*.cpp" | grep -iv "$(PROG_PAT)")

# Splits into task (to be linked against) and prog (src with mains)
TASK_OBJ := $(patsubst c++/%.cpp,obj/%.o,$(TASK_SRC))
PROG := $(patsubst c++/%.cpp,%,$(TEST_SRC) $(ANAL_SRC))

SCRATCH := build obj

.PHONY: all rebuild clean

all: $(PROG)
rebuild: clean all

$(PROG): %: $(SCRATCH) $(TASK_OBJ) obj/%.o
	@echo Linking $@
	@$(CXX) $(LDFLAGS) $(CXXFLAGS) $(TASK_OBJ) obj/$@.o -o build/$@

$(SCRATCH):
	@echo Creating $@ directory
	@for d in `find c++ -type d | sed 's/^c++//g'`; do \
	 	mkdir -p $@/$$d; \
	done
	@for f in `find c++ -name "*.dat" | sed 's/^c++\///g'`; do \
		ln -s ../../c++/$$f $@/$$f; \
	done
	@echo "*\n!.gitignore" > $@/.gitignore

obj/%.o: %.cpp
	@echo "  Compiling $@"
	@$(CXX) -c $(CXXFLAGS) $< -o $@

clean:
	@echo Cleaning files...
	@rm -f $(PROG) $(OBJ)
	@rm -rf build obj

docs:
	@cd latex && latex report.tex && dvipdf report.dvi

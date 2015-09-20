CXX        := g++-4.8
CXXFLAGS   += -pedantic -std=c++11 -Wall
LDFLAGS    := -lgtest -lgtest_main -pthread
GCOV       := gcov-4.8
GCOVFLAGS  := -fprofile-arcs -ftest-coverage
GPROF      := gprof
GPROFFLAGS := -pg
VALGRIND   := valgrind

clean:
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov
	rm -f TwoButtons
	rm -f TwoButtons.tmp
	rm -f TestTwoButtons
	rm -f TestTwoButtons.tmp

config:
	git config -l

scrub:
	make  clean
	rm -f  TwoButtons.log
	rm -rf collatz-tests
	rm -rf html
	rm -rf latex

status:
	make clean
	@echo
	git branch
	git remote -v
	git status

test: TwoButtons.tmp TestTwoButtons.tmp

TwoButtons: TwoButtons.h TwoButtons.c++ RunTwoButtons.c++
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) TwoButtons.c++ RunTwoButtons.c++ -o TwoButtons

TwoButtons.tmp: TwoButtons
	./TwoButtons < TwoButtons.in > TwoButtons.tmp
	diff TwoButtons.tmp TwoButtons.out

TestTwoButtons: TwoButtons.h TwoButtons.c++ TestTwoButtons.c++
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) TwoButtons.c++ TestTwoButtons.c++ -o TestTwoButtons $(LDFLAGS)

TestTwoButtons.tmp: TestTwoButtons
	$(VALGRIND) ./TestTwoButtons                                       >  TestTwoButtons.tmp 2>&1
	$(GCOV) -b TwoButtons.c++     | grep -A 5 "File 'TwoButtons.c++'"     >> TestTwoButtons.tmp
	$(GCOV) -b TestTwoButtons.c++ | grep -A 5 "File 'TestTwoButtons.c++'" >> TestTwoButtons.tmp
	cat TestTwoButtons.tmp

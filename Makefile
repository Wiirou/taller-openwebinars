is_amstrong_number : objects
	gcc main.o stack.o armstrong.o -o is_armstrong_number -lm 
main.o : main.c
	gcc -c main.c
armstrong.o : armstrong.c
	gcc -c armstrong.c
stack.o : stack.c
	gcc -c stack.c	
objects : main.o stack.o armstrong.o

clean-objects: 
	rm -f main.o stack.o armstrong.o
clean-reports:
	rm -f reports/cppcheck/*
	rm -f reports/cmocka/*

clean-tests:
	rm -rf tests/build/*
clean: clean-reports clean-objects clean-tests
	rm -f is_armstrong_number

cppcheck-xml :
	cppcheck *.c --xml --xml-version=2 --enable=all --inconclusive --language=c *.c 2>reports/cppcheck/report.xml
cppcheck : 
	cppcheck *.c --enable=all --inconclusive --language=c *.c
doc:
	doxygen

tests: clean armstrong.o stack.o
	gcc tests/test_is_armstrong_number.c armstrong.o stack.o -lm -lcmocka -o tests/build/test_is_armstrong_number
	CMOCKA_MESSAGE_OUTPUT=stdout CMOCKA_XML_FILE='' ./tests/build/test_is_armstrong_number 

tests-xml: clean armstrong.o stack.o
	gcc tests/test_is_armstrong_number.c armstrong.o stack.o -lm -lcmocka -o tests/build/test_is_armstrong_number
	CMOCKA_XML_FILE=reports/cmocka/%g.xml CMOCKA_MESSAGE_OUTPUT=xml ./tests/build/test_is_armstrong_number 

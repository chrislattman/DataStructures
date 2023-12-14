SHELL=/bin/bash

OS=$(shell echo `uname`)
ifneq ($(findstring Darwin,$(OS)),)
LIBEXT=.dylib
else ifneq ($(findstring Linux,$(OS)),)
LIBEXT=.so
else # MinGW-w64
LIBEXT=.dll
endif

CPP_FLAGS=-Wall -Wextra -pedantic -std=c++14

runjava: libjava
	cp src/java/Main.java .
	javac -cp dsa.jar Main.java
	java -cp dsa.jar:. Main
	# java -cp dsa.jar Main.java

runcpp:
	g++ $(CPP_FLAGS) -o main src/cpp/main.cpp
	./main

runpy:
	python3 src/python/main.py

debugjava:
	javac -g -d out -cp src/java/dsa/*.java src/java/Main.java
	# cd out; jdb Main

debugcpp:
	g++ $(CPP_FLAGS) -Og -ggdb3 -o main src/cpp/dsa/*.cpp src/cpp/main.cpp
	# gdb main

debugpy:
	python3 -m pdb src/python/main.py

docsjava:
	javadoc -d public/java src/java/dsa/*.java

docscpp:
	# TODO: use doxygen

docspy:
	python3 -m pydoc src/python/dsa/*

libjava:
	javac src/java/dsa/*.java
	cd src/java; jar -cf dsa.jar dsa/*.class; mv dsa.jar ../..

clean:
	rm -rf *.jar *$(LIBEXT) Main.class main Main.java src/java/dsa/*.class out public

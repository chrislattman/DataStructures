SHELL=/bin/bash

CPP_FLAGS=-Wall -Wextra -pedantic -std=c++14
# PY_FILES=$(shell echo `cd src/python/dsa; ls *.py`)
# FILES=$(basename $(PY_FILES))

runjava: libjava
	javac -cp dsa.jar src/java/Main.java
	java -cp dsa.jar:src/java Main
	# java -cp dsa.jar src/java/Main.java

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
	# python3 -m pdb src/python/main.py

docsjava:
	javadoc -d public/java src/java/dsa/*.java

docscpp:
	mkdir -p public/cpp
	doxygen Doxyfile

docspy:
	# python3 -m pydoc -w src.python.dsa
	# for file in $(FILES); do \
	# 	python3 -m pydoc -w src.python.dsa.$$file; \
	# done
	# mkdir -p public/python
	# mv *.html public/python
	cd sphinx; make html

libjava:
	javac src/java/dsa/*.java
	cd src/java; jar -cf dsa.jar dsa/*.class; mv dsa.jar ../..

clean:
	rm -rf *.jar main src/java/Main.class src/java/dsa/*.class out public src/python/dsa/__pycache__

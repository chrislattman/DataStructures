SHELL=/bin/bash

CPP_FLAGS=-Wall -Wextra -pedantic -std=c++14
PY_TEST_FILES=$(shell echo `cd test/python/dsa; ls *.py`)
FILES=$(basename $(PY_TEST_FILES))

runjava: libjava
	javac -cp dsa.jar src/java/Main.java
	java -cp dsa.jar:src/java Main
	# java -cp dsa.jar src/java/Main.java

runcpp:
	g++ $(CPP_FLAGS) -o main src/cpp/main.cpp
	./main

runpy:
	python3 src/python/main.py

lintpy:
	autoflake -i --remove-all-unused-imports src/python/main.py
	autoflake -i --remove-all-unused-imports src/python/dsa/*.py
	autoflake -i --remove-all-unused-imports test/python/dsa/*.py
	black src/python/main.py
	black src/python/dsa/*.py
	black test/python/dsa/*.py
	isort src/python/main.py
	isort src/python/dsa/*.py
	isort test/python/dsa/*.py
	pyupgrade src/python/main.py
	pyupgrade src/python/dsa/*.py
	pyupgrade test/python/dsa/*.py
	mypy src/python/dsa/*.py

coveragejava: testjava
	rm bin/dsa/*Test.class # excluding tests from code coverage report
	java -jar lib/org.jacoco.cli-0.8.9-nodeps.jar report jacoco.exec \
		--classfiles bin --sourcefiles src/java --html java-coverage-report
	open java-coverage-report/index.html

coveragepy:
	for file in $(FILES); do \
		cd test/python/dsa; coverage run -a -m unittest $$file; \
	done
	mv test/python/dsa/.coverage .
	coverage html
	mv htmlcov python-coverage-report
	open python-coverage-report/index.html

testjava:
	javac -d bin src/java/dsa/*.java
	javac -d bin -cp bin:lib/junit-platform-console-standalone-1.9.3.jar test/java/dsa/*.java
	java -javaagent:lib/org.jacoco.agent-0.8.9-runtime.jar \
		-jar lib/junit-platform-console-standalone-1.9.3.jar \
		--class-path=bin --scan-classpath --fail-if-no-tests

testpy:
	for file in $(FILES); do \
		cd test/python/dsa; python3 -m unittest $$file; \
	done

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
	open public/java/index.html

docscpp:
	mkdir -p public/cpp
	doxygen Doxyfile
	open public/cpp/annotated.html

docspy:
	sphinx-apidoc -f -o sphinx src/python/dsa
	cd sphinx; make html
	open public/python/html/modules.html

libjava:
	javac src/java/dsa/*.java
	cd src/java; jar -cf dsa.jar dsa/*.class; mv dsa.jar ../..

clean:
	rm -rf *.jar main src/java/Main.class src/java/dsa/*.class out public \
		src/python/dsa/__pycache__ test/python/dsa/__pycache__ \
		.mypy_cache bin jacoco.exec *-coverage-report .coverage

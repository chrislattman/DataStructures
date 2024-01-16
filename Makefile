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

runts:
	npx tsx src/typescript/main.ts

rungo:
	go run ./src/go

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

lintts:
	npx eslint src/typescript/main.ts || true
	npx eslint src/typescript/dsa/*.ts || true
	npx eslint test/typescript/dsa/*.ts

lintgo:
	gofmt -w src/go/main.go
	gofmt -w src/go/dsa/*.go
	go vet src/go/main.go
	go vet src/go/dsa/*.go

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
	coverage html --omit=*test*,*__init__*,*typing_extensions*
	mv htmlcov python-coverage-report
	open python-coverage-report/index.html

coveragets:
	npm run coverage
	mv coverage typescript-coverage-report
	open typescript-coverage-report/lcov-report/index.html

coveragego:
	go test -v -coverprofile=coverage.out ./src/go/dsa
	go tool cover -html=coverage.out

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

testts:
	npm test

testgo:
	go test -v ./src/go/dsa

debugjava:
	javac -g -d out -cp src/java/dsa/*.java src/java/Main.java
	# cd out; jdb Main

debugcpp:
	g++ $(CPP_FLAGS) -Og -ggdb3 -o main src/cpp/dsa/*.cpp src/cpp/main.cpp
	# gdb main

debugpy:
	# python3 -m pdb src/python/main.py

debugts:
	# Doesn't work
	# npm run debug

debuggo:
	# dlv debug ./src/go

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

docsts:
	mkdir -p public
	npx typedoc --readme none --name DataStructures src/typescript/dsa/*.ts
	mv docs public/typescript
	open public/typescript/index.html

docsgo:
	# godoc starts a web server
	# The documentation is located at http://127.0.0.1:8080/example.com/dsa
	pkgsite

libjava:
	javac src/java/dsa/*.java
	cd src/java; jar -cf dsa.jar dsa/*.class; mv dsa.jar ../..

libpy:
	pip wheel --no-deps -w dist .

libts:
	npm pack

clean:
	rm -rf *.jar main src/java/Main.class src/java/dsa/*.class out public \
		src/python/dsa/__pycache__ test/python/dsa/__pycache__ \
		.mypy_cache bin jacoco.exec *-coverage-report .coverage \
		dist dsa.egg-info dsa-1.0.tgz build coverage.out

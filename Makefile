SHELL=/bin/bash

CPP_FLAGS=-Wall -Wextra -pedantic -std=c++23
CPP_TEST_LIBS=-lgtest -lgtest_main -lgmock -pthread
MOCK=lib/mockito-core-5.9.0.jar:lib/byte-buddy-1.14.11.jar:lib/objenesis-3.3.jar

OS=$(shell echo `uname`)
ifeq ($(OS),Darwin)
PREFIX=/usr/local/opt/llvm/bin/
endif

runjava: libjava
	javac -cp dsa.jar src/java/Main.java
	java -cp dsa.jar:src/java Main
	# java -cp dsa.jar src/java/Main.java

runcpp:
	g++ $(CPP_FLAGS) -O2 -o main src/cpp/main.cpp
	./main

runpy:
	python3 src/python/main.py

runts:
	npm start

rungo:
	go build -ldflags="-s -w" ./src/go
	./main
	# go run ./src/go

runrust:
	RUSTFLAGS=-Awarnings cargo build -q --release # don't set RUSTFLAGS env var in practice
	./target/release/dsa-tester
	# cargo run -q

lintjava:
	java -jar lib/checkstyle-10.13.0-all.jar -c lib/checks.xml src/java/dsa

lintcpp:
	cppcheck --std=c++14 --language=c++ src/cpp src/cpp/dsa/*.h*
	flawfinder src/cpp/

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
	pycodestyle src/python/dsa/*.py
	pydocstyle --convention=google src/python/dsa/*.py

lintts:
	npm run lint

lintgo:
	gofmt -w src/go/main.go
	gofmt -w src/go/dsa/*.go
	go vet src/go/main.go
	go vet src/go/dsa/*.go

lintrust:
	cargo fmt
	cargo clippy -- -D clippy::all -D clippy::pedantic

coveragejava: testjava
	rm bin/dsa/*Test.class # excluding tests from code coverage report
	java -jar lib/org.jacoco.cli-0.8.9-nodeps.jar report jacoco.exec \
		--classfiles bin --sourcefiles src/java --html java-coverage-report
	open java-coverage-report/index.html

coveragecpp:
	g++ $(CPP_FLAGS) --coverage -O0 -ggdb -g3 -Isrc/cpp/dsa -o main test/cpp/dsa/*.cpp $(CPP_TEST_LIBS)
	./main
	mv main-* test/cpp/dsa
	@for f in test/cpp/dsa/main-*; do \
		mv "$$f" "test/cpp/dsa/$${f##*/main-}"; \
	done
	gcov test/cpp/dsa/*.cpp
	mv my*.gcov test/cpp/dsa
	rm *.gcov
	# Let's happily ignore all of these errors
	lcov --ignore-errors format,format,unsupported,inconsistent,inconsistent --capture --directory test/cpp/dsa --output-file coverage.info
	lcov --ignore-errors format --remove coverage.info "/usr/local/include/*" "*/v1/*" "test/*" --output-file coverage.filtered.info
	genhtml --ignore-errors unsupported,unsupported,inconsistent,inconsistent,corrupt,category,category coverage.filtered.info --output-directory cpp-coverage-report
	open cpp-coverage-report/index.html

coveragepy:
	coverage run -a -m unittest discover -v -s test/python/dsa -p "*test.py"
	coverage html --omit=*test*,*__init__*,*typing_extensions*
	mv htmlcov python-coverage-report
	open python-coverage-report/index.html

coveragets:
	npm run coverage
	mv coverage typescript-coverage-report
	open typescript-coverage-report/lcov-report/index.html

coveragego:
	go generate src/go/dsa/mylist.go
	go test -v -coverprofile=coverage.out ./src/go/dsa
	grep -v -e "test_helpers" -e "mock_*" coverage.out > coverage.out.bak
	rm coverage.out
	mv coverage.out.bak coverage.out
	go tool cover -html=coverage.out

coveragerust:
	RUSTFLAGS="-C instrument-coverage" cargo test -q
	$(PREFIX)llvm-profdata merge --sparse -o default.profdata src/rust/dsa/default*.profraw
	rm -f target/debug/deps/dsa-*.o target/debug/deps/dsa-*.d
	$(PREFIX)llvm-cov show -format=html -output-dir=rust-coverage-report \
		-instr-profile=default.profdata ./target/debug/deps/dsa-* \
		-ignore-filename-regex="/.cargo/|/.rustup/"
	open rust-coverage-report/index.html

testjava:
	javac -d bin src/java/dsa/*.java
	javac -d bin -cp bin:lib/junit-platform-console-standalone-1.9.3.jar:$(MOCK) \
		test/java/dsa/*.java
	java -javaagent:lib/org.jacoco.agent-0.8.9-runtime.jar \
		-javaagent:lib/byte-buddy-agent-1.14.11.jar \
		-Xshare:off \
		-jar lib/junit-platform-console-standalone-1.9.3.jar \
		-cp bin:$(MOCK) --scan-classpath --fail-if-no-tests

testcpp:
	g++ $(CPP_FLAGS) -O2 -Isrc/cpp/dsa -o main test/cpp/dsa/*.cpp $(CPP_TEST_LIBS)
	./main

testpy:
	python3 -m unittest discover -v -s test/python/dsa -p "*test.py"

testts:
	npm test

testgo:
	go generate src/go/dsa/mylist.go
	go test -v ./src/go/dsa

testrust:
	cargo test -q

debugjava:
	javac -g -d out -cp src/java/dsa/*.java src/java/Main.java
	# cd out; jdb Main

debugcpp:
	g++ $(CPP_FLAGS) -Og -ggdb -g3 -o main src/cpp/dsa/*.cpp src/cpp/main.cpp
	# gdb main

debugpy:
	# python3 -m pdb src/python/main.py

debugts:
	# Doesn't work
	# npm run debug

debuggo:
	go build ./src/go
	# dlv debug ./src/go

debugrust:
	cargo build -q
	# rust-lldb ./target/debug/dsa-tester

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
	npm run docs
	mv docs public/typescript
	open public/typescript/index.html

docsgo:
	# pkgsite starts a local web server
	# The documentation is located at http://127.0.0.1:8080/example.com/dsa
	pkgsite

docsrust:
	cargo doc
	open target/doc/dsa/index.html

libjava:
	javac src/java/dsa/*.java
	cd src/java; jar -cf dsa.jar dsa/*.class; mv dsa.jar ../..

libcpp:
	@echo "Can't produce C++ library due to presence of generics."

libpy:
	pip wheel --no-deps -w dist .
	python3 setup.py sdist
	rm -rf build dsa.egg-info src/python/dsa.egg-info

libts:
	npm pack

updatejava:
	@echo "Must update dependencies manually in installj.sh"

updatecpp:
	@echo "Update C++ dependencies with your package manager."

updatepy:
	pip-compile requirements.in --upgrade
	pip install -r requirements.txt

updatets:
	npm update
	npm install

updatego:
	cd src/go/dsa; go get -u; go mod tidy

updaterust:
	cargo update

clean:
	rm -rf *.jar main main* src/java/Main.class src/java/dsa/*.class out public \
		src/python/dsa/__pycache__ test/python/dsa/__pycache__ \
		.mypy_cache bin jacoco.exec *-coverage-report .coverage coverage.out \
		dist dsa-1.0.0.tgz target *.profdata *.profraw src/rust/dsa/*.profraw \
		src/rust/dsa-tester/*.profraw test/cpp/dsa/*.gc* *.info

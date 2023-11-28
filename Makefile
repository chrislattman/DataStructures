SHELL=/bin/bash

lib:
	jar -cf dsa.jar src/dsa/*.java

debug:
	javac -g -d out -cp src/dsa/*.java src/Main.java

docs:
	javadoc -d public src/dsa/*.java

clean:
	rm -rf dsa.jar out public

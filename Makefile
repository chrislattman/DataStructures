SHELL=/bin/bash

lib:
	cp src/Main.java .
	javac src/dsa/*.java
	cd src; jar -cf dsa.jar dsa/*.class; mv dsa.jar ..
	java -cp dsa.jar Main.java

debug:
	javac -g -d out -cp src/dsa/*.java src/Main.java
	# cd out; jdb Main

docs:
	javadoc -d public src/dsa/*.java

clean:
	rm -rf *.jar Main.java src/dsa/*.class out public

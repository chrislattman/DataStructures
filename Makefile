SHELL=/bin/bash

lib:
	cp src/Main.java .
	cd src; jar -cf dsa.jar dsa/*.java; mv dsa.jar ..
	javac -cp dsa.jar Main.java
	java -cp dsa.jar:. Main

debug:
	javac -g -d out -cp src/dsa/*.java src/Main.java

docs:
	javadoc -d public src/dsa/*.java

clean:
	rm -rf *.jar Main.java *.class out public

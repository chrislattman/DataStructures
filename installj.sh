#!/bin/bash
rm -rf lib
mkdir lib
curl -LO https://repo.maven.apache.org/maven2/org/junit/platform/junit-platform-console-standalone/1.9.3/junit-platform-console-standalone-1.9.3.jar
curl -LO https://repo.maven.apache.org/maven2/org/mockito/mockito-core/5.9.0/mockito-core-5.9.0.jar
curl -LO https://repo.maven.apache.org/maven2/net/bytebuddy/byte-buddy/1.14.11/byte-buddy-1.14.11.jar
curl -LO https://repo.maven.apache.org/maven2/net/bytebuddy/byte-buddy-agent/1.14.11/byte-buddy-agent-1.14.11.jar
curl -LO https://repo.maven.apache.org/maven2/org/objenesis/objenesis/3.3/objenesis-3.3.jar
curl -LO https://repo.maven.apache.org/maven2/org/jacoco/org.jacoco.agent/0.8.9/org.jacoco.agent-0.8.9-runtime.jar
curl -LO https://repo.maven.apache.org/maven2/org/jacoco/org.jacoco.cli/0.8.9/org.jacoco.cli-0.8.9-nodeps.jar
curl -LO https://github.com/checkstyle/checkstyle/releases/download/checkstyle-10.13.0/checkstyle-10.13.0-all.jar

# Using default Sun/Oracle Java standard. Google Java standard is located at https://raw.githubusercontent.com/checkstyle/checkstyle/master/src/main/resources/google_checks.xml
curl -LO https://raw.githubusercontent.com/checkstyle/checkstyle/master/src/main/resources/sun_checks.xml

mv ./*.jar lib
rm lib/dsa.jar

# Removes a few checks from the XML file
grep -v -e FinalParameters -e FinalClass -e DesignForExtension ./*_checks.xml > tmpfile

rm ./*_checks.xml
mv tmpfile checks.xml
mv checks.xml lib

#!/bin/bash
mkdir lib
curl -LO https://repo.maven.apache.org/maven2/org/junit/platform/junit-platform-console-standalone/1.9.3/junit-platform-console-standalone-1.9.3.jar
curl -LO https://repo.maven.apache.org/maven2/org/jacoco/org.jacoco.agent/0.8.9/org.jacoco.agent-0.8.9-runtime.jar
curl -LO https://repo.maven.apache.org/maven2/org/jacoco/org.jacoco.cli/0.8.9/org.jacoco.cli-0.8.9-nodeps.jar
mv ./*.jar lib

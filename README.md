# DataStructures

Collection of implemented data structures and algorithms in Java, some C++, Python, TypeScript, and Go, as well as multithreading examples in Java.

- For the Java examples, these are not exact copies of the Java Collections Framework, since there is no such thing as an ArrayQueue (rather, there is the ArrayDeque) and LinkedList is slightly different (doubly-linked, for one), both of which implement the Deque interface
- There are also no NavigableMap/NavigableSet, SortedMap/SortedSet, or SequencedMap/SequencedSet interfaces

The multithreading examples were taken from [`https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2`](https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2)

Note: before building documentation or generating code coverage for the Python code, run

```
python3 -m venv .venv
source .venv/bin/activate
pip install -r requirements.txt
```

- This creates a Python virtual environment, which indicates that all non-standard Python dependencies specific to this project be stored in the `.venv` folder, uses this folder as the default Python environment, and proceeds to download the dependencies in `requirements.txt` to it
- `requirements.in` contains the primary non-standard dependencies, whereas `requirements.txt`, which is updated with `pip-compile`, contains all non-standard dependencies
- To leave this virtual environment, simply run `deactivate`
- Other Python projects use [build](https://build.pypa.io/en/stable/) which use `pyproject.toml` files

Likewise for Java, run

```
./installj.sh
```

- A real-world Java project would use something like [Maven](https://maven.apache.org/guides/getting-started/maven-in-five-minutes.html) and conform to its requirements

For TypeScript, run

```
npm install
```

- The TypeScript analog to the Python `.venv` folder is called `node_modules`
- TypeScript non-standard primary dependencies are listed in `package.json`, whereas all dependencies are located in `package-lock.json`, which is updated with `npm update`

For Go, run

```
echo "export PATH=$HOME/go/bin:$PATH" >> ~/.bashrc
source ~/.bashrc
go install golang.org/x/pkgsite/cmd/pkgsite@latest
cd src/go
go mod init example.com/main
cd dsa
go mod init example.com/dsa
cd ../../..
go work use
```

- The specific versions of non-standard dependencies for a Go package are listed in the package's `go.mod` file
- By convention, Go test files are located in the same folder as the source files

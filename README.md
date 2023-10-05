<h1>cpp-trees</h1>

The section is written with codes in triple quotes to utilize Clion run-in-markdown capabilities. 

<h2>Dev</h2>

Run
```bash
cmake -S . -B  build 
```
at the root tree to create build files.

Run
```bash
cmake --build build
```
at the root tree to build the build files.

Run
```bash
cd build && ctest --output-on-failure && cd ..
```
to go to build folder and test and return to root.

### For Mac

Run
```bash
leaks -atExit -- build/Your_test      
```

to check for leakage, remember to replace Your_test with the executable
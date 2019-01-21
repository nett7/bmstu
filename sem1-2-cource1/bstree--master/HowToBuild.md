
 
## Building of a project:
 
```
$ cmake -H. -B_build -DCMAKE_INSTALL_PREFIX=install

$ cmake --build _build --target install
```



**Run the test:**

```
$ cmake -H. -B_build -DBUILD_TESTS=ON

$ cmake --build _build --target install

$ cmake --build _build --target test -- ARGS=--verbose
```



**Run the examples:**

```
$ cmake -H. -B_build -DBUILD_EXAMPLES=ON

$cmake --build _build --target install

$ cd _build

$ ./example
```

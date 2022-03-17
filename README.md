# CSC 340 — Assignment 03

## Prerequisites

* CMake 2.21
* C++20

## Building

Build the project using CMake. There are four CMakeLists.txt. One at the root of the project (where this README is), and
one for each part.

At the project root, run:

```shell
cmake .
cmake --build .
```

Three executables will be created for each parts in their respective folder.

## Running

The executables have the same name as the subdirectories containing their source.

### Parts A and B

Run parts A and B from the root folder by using:

```shell
./part_a/part_a
./part_b/part_b
```

### Part C

> #### Important
> Running `./part_c` outside its folder may cause data loading to not work properly. In order to produce identical
> output to the complete sample run’s output, the executable **must be accessed in the same location as the data source
> file.**


Navigate to `part_c` folder first, then run the executable:

```shell
cd part_c
./part_c
```

You may also run part C from the root folder directly, like parts A and B. However, when providing a path to the data
source at the beginning of the program, the path must be relative to the current working directory.

In other words, entering `./Data.CS.SFSU.txt` will not work as expected if the executable is not run at its location.

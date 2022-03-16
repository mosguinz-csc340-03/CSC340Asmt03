# CSC 340 — Assignment 03

## Prerequisites

* CMake 2.21
* C++20

## Building

This project uses CMake. There are three parts to this project, each of them with their own `main` functions, and
therefore, their own executables.

There are four CMakeLists.txt files in total. One for each part, and one at the root folder (where this README.md is
located).

At the root folder, run:

```shell
cmake .
```

Then, build using:

```shell
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



# Brainfuck Interpreter

This is a simple Brainfuck interpreter written in C.

## Building

The source code conforms to the C89 standard and compiles on Linux using the
GCC compiler.

Enter `make` to build the project. It will be built in `bin/`.
Enter `make clean` to remove the build files.

## Usage

To execute a Brainfuck program use the following format:

```
bf <file>
```

## Specification

The interpreter allows a source file size of up to 30,000 bytes. The memory
tape contains 30,000 cells.

Accessing indices outside of the bounds of the tape, as well as having
unbalanced loop brackets, results in undefined behavior. Otherwise, the
program's behavior is predictable and consistent with the formal language
specification.

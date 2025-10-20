## Static/Dynamic Linking with Libraries

### Linking

- a linker takes a collection of object files and combines them into an object file. But this object file will still depend on libraries.
- Nect it cross-references this single object file against libraries, resolbing any references to methods or constants in those lib
- if anything needed has been found, it outputs an executable image

- program can be written as a collection of smaller source files, rather than one monolithic mass. But later we need to combine all of these
- Each C source file (\*.c) can have implementation of some functoins and has its own .h file

### An object file is an intermediate form

An object file contains incomplete machines instruction, with location that may still need to be filled in:

- addresses of methods defined in other obejct files, or lib
- addresse of data and bss segment, in memory (.bss segment (Block Started by Symbol) in a C program's memory layout is a dedicated section for storing uninitialized global and static variables)

After linking, all the resolved addresses will have been inserted at those previously unresolved location in the object file.

### Symbol resolution

programs define and reference symbols (global variables and functions)

```c
void swap() {…} /* define symbol swap */
• swap(); /* reference symbol swap */
• int *xp = &x; /* define symbol xp, reference x */
```

Symbol definitions are stored in object file in the **symbol table**

- symbol table is an array of entries
- each table entry include name, type, size and location of symbol

Three cases:

- a symbol can be defined by the object file
- it can be undefined; in which case the linker is required to find the definition and link the object file to the definition
- it can be mutiply defined. This is normally an error (there are ways to bypass it)

### relocation

relocation is the process of assigning load addresses for position-dependent code and data of a program and adjusting the code and data to reflect the assigned addresses.

**A linker usually performs relocation in conjunction with symbol resolution**, the process of **searching** files and libraries to replace symbolic references or names of libraries with actual usable addresses in memory before running a program.

### Object File Format (ELF)

Executable and Linkable Format (ELF) is a standard file format for executables, object code, shared libraries, and core dumps on Unix-like operating systems, including Linux

- ELF header
  - Word size, byte ordering, file type (.o, exec, .so), machine type, etc.
- Segment header table
  - Page size, virtual address memory segments + sizes.
- .text section (code)
- .rodata section (read-only data, jump offsets, strings)
- .data section (initialized global and static local variables)
- .bss section (name “bss” is lost in history)
  - Global or static local variables that weren’t initialized: zeros.
  - Has section header but occupies no space

### Static linking vs. Dynamic linking

### Linking summary

linking is a technique allowing programs to be constructed from multiple object files

- linking can happen at different times in a program's lifetime:
  - compile time
  - load time (when a program is loaded into memory)
  - run time

# Static Linking vs Dynamic Linking in C

## Comparison Table

| Feature                 | Static Linking                | Dynamic Linking                      |
| ----------------------- | ----------------------------- | ------------------------------------ |
| Library code location   | Copied into executable        | Loaded at runtime                    |
| Executable size         | Larger                        | Smaller                              |
| External dependencies   | None needed                   | Libraries must be present on system  |
| Runtime speed           | Slightly faster               | Slightly slower startup              |
| Memory usage            | Each program has its own copy | Multiple programs share same library |
| Updates/bug fixes       | Must recompile program        | Automatic (just update library)      |
| Library version         | Fixed at compile time         | Can change between runs              |
| Default in most systems | No                            | Yes                                  |
| File extension (Linux)  | `.a` (Archive)                | `.so` (Shared Object)                |

## Static Linking

When you statically link a program, the compiler copies all the library code your program needs directly into your final executable file.

### Pros

- The executable is self-contained and portable (no external dependencies needed)
- Slightly faster at runtime (no need to load libraries)
- You know exactly which version of the library you're using

### Cons

- The executable file is much larger
- If the library has a bug fix or update, you need to recompile your program
- Multiple programs using the same library waste memory (each has its own copy)

### Example

```c
gcc myprogram.c -static -o myprogram
```

## Dynamic Linking

When you dynamically link a program, the executable only contains references to the libraries. The actual library code is loaded into memory at runtime (when you run the program).

### Pros

- Smaller executable files
- Multiple programs can share the same library in memory (saves space)
- You can update libraries without recompiling your program
- Bug fixes in libraries benefit all programs automatically

### Cons

- Requires the library to be present on the system where you run the program
- Slightly slower startup time (need to load libraries)
- Potential compatibility issues if library versions change

### Example

```c
gcc myprogram.c -o myprogram
```

(Dynamic linking is the default in most systems)

## In Linux/x86-64

- Dynamically linked libraries have `.so` extension (Shared Object), like `libc.so`
- Statically linked libraries have `.a` extension (Archive), like `libc.a`

## Simple Analogy

- **Static linking** is like printing out all the pages of a textbook you need and stapling them to your homework
- **Dynamic linking** is like just writing "see textbook page 42" on your homework and looking it up when needed

### gcc

gcc is a "compiler driver": it launches a series of sub-programs

- `-L`: to specify locations (directories) for library files
- `-l`: to specify the libraries to link with
- `-I`: to specify the locations (directories) for header files
- `-c` option stops the compilation process before linking.

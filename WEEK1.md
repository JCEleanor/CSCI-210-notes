# week 1

## Learning Outcomes

### component of Operating System

- a program that sits btw the hardware and the application programs
- manages storage, processes, network and provide interface to programs or users
- it's the first program that is run when you boot your machine

#### The functions of a modern OS

- multitasking: allow multiple programs to run concurrently (much more than the number of processors or cores)
- multiuser: allow multiple users to use simultaneously in the same computer
- file system: manage multiple disks, allow storage of files in a secure way
- networking: provide connection to/from other computers
- GUI/Window management provide GUI

### Linux Kernel

The layer between the applications and the hardware

- "monolithic" refers to the kernal being one program

### relationship of Linux & C

#### why c

- C/C++ programs are compiled and optimized for
  efficiency.
- C was designed to be a high-level assembly language, which means
  - it contains high-level programming strucutures such as if/for/while, typed variables
  - it has memory pointers and arrays

### ssh/scp, VM, WSL, Dual Boot

#### SSH (Secure Socket Shell)

SSH is a network protocol that gives users, particularly system admin a secure way to access a computer over an unsecured network. It provide: 1. strong pwd authentication 2. public key authentication 3. encrypted data communications btw 2 pcs connecting over an open network, such as the internet

- An SSH client is a program that allows establishing secure and authenticated SSH connections to SSH servers.
- SSH client software is available in many desktoip os such as Windows and MacOS.

#### Alternatives to command line ssh

- WSL (Windows Subsystem for Linux)
- Virtual Machines

  - virtual box
  - VMWare
  - Parallels Desktops

- Install a Linux distribution on your own machine
- VScode ssh extension

#### Bash

- installed as the default shell in most Linux distributions (Others such as Zsh, Korn, Tcsh, Fish)

#### The Filesystem

- tools, packages, user documentation, configuration files - almost everything is a file in an operating system
- an absolute path is a path starts with `/`

### Linux commands

#### ls

`-a` Include directory entries whose names begin with a dot (‘.’).

`-l` List files in the <u>long format</u>, as described in the <u>The Long Format</u> subsection below. Will show file permission in the first col as 10-character string.

```
❯ ls -l
total 5968
-rw-r--r--@  1 Eleanor  staff  758818 Sep 29 09:11 CSCI210_week10.pdf
drwxr-xr-x@ 13 Eleanor  staff     416 Sep 27 13:29 ExampleInputsOutputs
```

The first character tells us if it's a directory (`d`), file (`-`) or symbolic link (`l`)

`-h` When used with the -l option, use unit suffixes: Byte, Kilobyte, Megabyte, Gigabyte, Terabyte and Petabyte in order to reduce the number of digits to four or fewer using base 2 for sizes.

`-r` Reverse the order of the sort.

`-S ` Sort by size (largest file first) before sorting the operands in lexicographical order.

`-t` Sort by descending time modified (most recently modified first).

`-1` (The numeric digit “one”.) Force output to be one entry per line. This is the default when output is not to a terminal.

#### Other commands:

- `cd` is a built-in function of the shell, which means the bash process handles the command

#### Other Commands: (individual commands that are executed as separate processes)

- `mkdir -p abc/aa` if `abc` doesn't exist, create parent dir. (By default, parents dir should exist)

- `cp [-i | -R] {source} {target}` if the target destination is an existing file/directory, it is overwritten with no warning by default. **Use `-i` to issue a warning.**

- `scp` the file location on a remote host is specified using the following format: **`user@host:path`**, where path is given **relative to the user’s home directory** (or an absolute path needs to be given).

  - Example:
    `scp local.txt tolgacan@isengard.mines.edu:./remote.txt`

- `less` v `cat`: cat prints the entire contents of a file to the terminal at once, while less displays the content one screen at a time

- `echo`: display the string

  - `-n` does not print and end of line at the end
  - `-e` turns on recognition of escape sequences (useful for scripting)

  ```
  Without -e:

  1 $ echo "Line 1\nLine 2\t(indented)"
  2 Line 1\nLine 2\t(indented)

  With -e:

  1 $ echo -e "Line 1\nLine 2\t(indented)"
  2 Line 1
  3 Line 2     (indented)
  ```

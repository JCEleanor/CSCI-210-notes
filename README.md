[0827]
Intro to linux
what’s a operating system? it’s a program (or a collection of programs) the orchestrated/managed the softwares processes in our pc. what does it manage? cpu, memory, threads, processes (the main thing) etc…
written in C

linux kernel: monolithic program, robust, couple(maybe), flexible to expand

what’s the OS in tesla? it’s a very decouple system. real-time operating system (vx fours??)

a kernel is the layer between the application and the hardware

C process/system call “fork”xyz”” -> does that how github “fork” come from

SSH: the network packets are encrypted. a lot of handshakings going on

pala alto networks-> global protect

[0829]

- `~` is a special alias meaning home
  root (/) is not home(~). Every user has different home dir while root is always the same
  we will focus on the bash shell (dang i’ve been using zsh) (have to type `bash` to use bash or change default to bash `chsh -s /bin/bash`
  cd /u/pa/nb/tolgacan/210
  man {a command} to see the manual
  it’s case sensitive
  absolute path is absolute to root (?

[0903]
in linux, we don’t use space or dash (-, bc it can be seen as flags) in filenames. we use camelCase or underscores to name a directories or filenames
the `tmp` dir is a temporary directory, which will get erased every time a linux machine is reboots
`ls /usr/bin | wc -l` the pipe symbol `|` mean …
`write [username]` the message will directly pops up to users’ screen (?
`mkdir -p` can create nested directory without error. For example,`mkdir a/b/c/d` will throw error: dir a not exist. While `mkdir -p a/b/c/d` will create a, b, c, d folders for you
if you want to be safe: use rm with -i, or make rm an alias of `rm -i`, which will show prompts every time you remove something
`vi` a text editor. sort of like a slim down version of vim
scp, the other machine needs to run ssh demon/server?
inside your local terminal: scp [username][hostname]:[directory]

### 0905

- in linux system, you can categorize uses into different groups.
- `chmod`: change access right

  `chmod [Numeric] [filename/dir]`

- Numeric (Octal) Mode: Uses 3-digit octal numbers to represent permissions for user, group, and others, respectively. Each digit is a sum of the values for read (4), write (2), and execute (1). For example:

  - 7 (4+2+1) = rwx (read, write, execute)
  - 6 (4+2) = rw- (read, write)
  - 4 (4) = r-- (read only)

- wildcard and globbing
  - all linux commands are capable of doing globbing (see slides for examples)

### 0908

`stdout`, `stdin` & `stderr` There are three standard input out streams recognized by operatingsystems and programming languages

- write a bash script to automate testing
- you can redirect standard input, output, and standard error to files using <b> I/O indirection </b>

#### Example

write a c program which print numbers from 1 - 1000000. Instead of printing in the shell, we can redirect the output to a test file.

```
./test.c > output.txt
```

Or redirect input to a program file and then redirect the output to a output file.

- use < or 0 to redirect stdin
- use > or 1 to redirect stdout
- Use 2> to redirect stderr

- /dev/null (a special dir) Usually when we pipe multiple commands, we want the error to log or ignore the error/output, we can redirect I/O to this dir.

### 0908

- use `>>` instead of `>` to append to the end of an existing file
- `ls | wc -l` where the pipe `|` is to connect mmultiple command. This piping mechanism put the output of the previous command to the following command
- another example usage of I/O redirection: `cat *.txt > merge-text.txt`, which merge all the text files into a merged txt file. It's a stupid example, but definitely see some potential of automating some tasks.
- `sed` to replace word (like replace deployment image hash name)

### 0912

- `tee`
- `unique` can be paried with `sort` to get word count or histogram of word count

```linux
sort sometext.txt | unique -c | sort -r -g
```

- `tr` stands for translate or transliterate.

```
[:class:]  Represents all characters belonging to the defined character class.  Class names are:
    alnum        <alphanumeric characters>
    alpha        <alphabetic characters>
    blank        <whitespace characters>
    cntrl        <control characters>
    digit        <numeric characters>
    graph        <graphic characters>
    ideogram     <ideographic characters>
    lower        <lower-case alphabetic characters>
    phonogram    <phonographic characters>
    print        <printable characters>
    punct        <punctuation characters>
    rune         <valid characters>
    space        <space characters>
    special      <special characters>
    upper        <upper-case characters>
    xdigit       <hexadecimal characters>
```

```linux
cat file.txt | tr "[a-z]" "[A-Z]" > uppercase.txt
cat some.txt | tr '\n' > ' ' > single-line.txt
```

- `grep`: Global Regular Expressoin Print (created by Ken Thompson)
  - `awk`: another text manipulating linux command (i think i've used it to search production log before)

```
grep [-i|-c|-l|-n|-v|-o|-R] pattern file
```

```
-i ignore-case
-c return total match count (of lines) instead of line contents
-l return names of matched files, instead of line contents
-n show line numbers
-v return lines which do not match pattern
-o print only the matching parts on separate lines
-R read the files in directories, recursively
```

### 0915

`grep -o -n -E ’(0|[1-9][0-9]*)([eE][+-]?[0-9]+)?’` -> why put a zero in front? for the base number for example: 016 is not 16 but 8 bit base number

### 0917

- aliases are defined in .bash_profile
- you can use `alias` command to see all the defined alias
- bashrc is a ”run-command”, i.e., an rc file, which contains a list of bash
  commands to be executed at every bash launch
- in bash, an undefined variable is always an empty string ""
- double colons and single colons are treated differently in bash script. For example "hello $A". If $A is defined, it will print out the value of $A, while in 'hello $A', will print out `$A`

```
-='cd -'
...=../..
....=../../..
.....=../../../..
......=../../../../..
1='cd -1'
2='cd -2'
3='cd -3'
4='cd -4'
5='cd -5'
6='cd -6'
7='cd -7'
8='cd -8'
9='cd -9'
_='sudo '
egrep='grep -E'
fgrep='grep -F'
g=git
gaa='git add --all'
gl='git pull'
glgg='git log --graph'
```

- l-value and r-value

- env variables are accessible by the current shell session and child processes
- by convention, variables are all caps in linux and bash
- `bash` start a new process (new child process in a linux shell) (`exit` to exist child process)
- sometimes some command we run (i,e., `matlab`) starts a child process, and after the command finishes, it quit the child process and return the result

- `ps` to list all the process (like in Dockerfile)
- shebang: `#!/bin/bash` ensures that your script is run with the Bash shell, regardless of which shell you are currently using in your terminal. This is important because different shells (like sh, zsh, ksh, etc.) can have different syntax and features, and a script written for Bash might not work correctly in another shell.
- shebang is needed for portability and POSIX compliance
- `. ./script.sh` execute script.sh. use the dot to execute the script
- `source` execute a script
- diff btw `.` and `source`

  1. Sourcing a Script (using source or .)
     Execution Environment: When you source a script (e.g., source myscript.sh or . myscript.sh), the commands within that script are executed in the current shell environment.
     Impact: Any changes made by the script, such as setting environment variables, changing the current working directory (cd), defining functions, or modifying shell options, will persist in the current shell after the script finishes.
     Use Case: This is typically used for configuration files (like .bashrc or .profile), loading functions, or modifying the current shell's state.

  2. Directly Running a Script (e.g., ./myscript.sh or bash myscript.sh)
     Execution Environment: When you directly run a script, a new subshell process is created to execute the script.
     Impact: Any changes made by the script are confined to this new subshell. Once the script finishes, the subshell is closed, and any modifications (like variable assignments or cd commands) are lost and do not affect the parent shell from which the script was launched.
     Use Case: This is the standard way to execute standalone scripts that perform specific tasks and whose effects are not intended to persist in the interactive shell.

### 0919

- Three quoting mechanisms in Bash:
  - Escape character
  - Single quotes: 'text'
  - Double quotes: "text"

```bash
  # command substitution
  echo "`ls`"
  echo "$(ls)"
```

```bash
echo "Now running script $0"
echo "First argument: $1"
echo "Second argument: $2"

# $$: The number of the command line args supplied to a script
echo "$#"

# see the current process ID
echo "$$"

# stores the number of command line arguments (count, not the list)
$#

# stores only the first command line argument
$1

# is the built-in variable that stores a list of all the command line arguments passed to the script or function.
$@
```

- `;` is a command seperator in bash script. For example, you can chain command with ;

```bash
if [$test]; then
echo HAHA
fi
```

- `test` command

```bash
[ -e README.md ] && echo "File exists" || echo "File does not exist"

```

### 0922

- `test`: test expression OR [ expression ]

```bash
#!/bin/bash
if [ $1 -le 10 ]; then
echo "Enter a number larger than 10"
fi
# OR
#!/bin/bash
if test $1 -le 10; then
echo "Enter a number larger than 10"
fi
```

- run script with `-x` flag to run debug mode or `set -x`

### 0924

#### inode table in linux

- every directory is a table in the operating system, including the name of the files, and some metadata like permission, owner, creation date, and the links to the pysical adrress of where the file is in the hardware. i-node table

```linux
df -i -h /

Filesystem        Size    Used   Avail Capacity iused ifree %iused  Mounted on
/dev/disk3s1s1   460Gi    13Gi   226Gi     6%    404k  2.4G    0%   /

```

Also show inode number (uuid)

- `ls -lahi`

```
265936 drwxr-xr-x+ 129 Eleanor  staff   4.0K Sep 24 09:35 .
   23256 drwxr-xr-x    6 root     admin   192B May  2  2024 ..
 2124436 -r--------    1 Eleanor  staff     7B Aug 13  2021 .CFUserTextEncoding
13044266 drwx------@   2 Eleanor  staff    64B Apr  7  2024 .DDLocalBackups
13043805 drwx------@   2 Eleanor  staff    64B Apr  7  2024 .DDPreview
  265997 -rw-r--r--@   1 Eleanor  staff    14K Sep 23 13:06 .DS_Store
...
```

- `ls -lahid` list as directory

### 0929

- to kill a process, you have to own the processes. For example, only super user can kill the root process :(
- `^c` (hitting ctrl c) asynchronous operation (can be customized)
- `^z` close program processes (make it sleep). fg means waking the process up`(same as`kill -TSTP`)
- by running `./infinite.c &`, parent processes do not wait for the child process too finish
- `kill -9 {process-id}` can kill the process
- SIGSEGV is a signal sent to a process, indicating a segmentation fault or an illegal memory access. But you can kill a process by sending this error to stop it. i.e., `kill -SEGV <PID>`

- 1001 (C programming (yeah))
- kernal (core part of the os) of isengard is written in C
- `man 2 pipe` an entire page on system calls
- In C programming, the concept of "slot space" typically refers to how memory is allocated and utilized, especially when dealing with data structures like arrays or when considering the memory footprint of variables and function calls

- imperative vs declarative programming
- ex: https://www.shadertoy.com/view/lllSWr
- sidenote: `man man` check how to use man command to fnid certain section of manual

```
     The sections of the manual are:
           1.   General Commands Manual
           2.   System Calls Manual
           3.   Library Functions Manual
           4.   Kernel Interfaces Manual
           5.   File Formats Manual
           6.   Games Manual
           7.   Miscellaneous Information Manual
           8.   System Manager's Manual
           9.   Kernel Developer's Manual
```

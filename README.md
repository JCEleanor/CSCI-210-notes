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

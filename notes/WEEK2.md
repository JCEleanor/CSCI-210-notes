# week 2

## Learning Outcomes

### File types

1. Text files (source code, config files)
2. Binary files (executables, .docx, jpeg)
3. Directories
4. Symbolic links (shortcut to files or dirs)

**By looking at the filename, it's impossible to distinguish files/dirs or text/binary files.** File extensions are for informative purpose only (There can be files with no extensions or directories with extensions)

### access rights

- read, write, execute (r,w,x) for three classes: owner, group, others => 9 permission flags

#### Examples:

- user has rwx, group has r, others have r, => `111 100 100` = `rwxr--r--`

  - `chmod u+x {myfile}`: adding (+) the execute (x) permission for the user (owner) of myfile.

  - `chmod a-w {myfile}`: remove (-) the write (w) permission for all users.
  - `chmod +x {myfile}`: remove (-) the write (w) permission for all users.

- Octal mode: Each number represents the permissions for one user class:
  The numeric mode use octal digits (0-7) to represent the 3-bit permissions for each ugo category.

  - The first digit is for the user (owner).
  - The second digit is for the group.
  - The third digit is for others.

  The permissions are calculated by adding these values:

  - 4 = read (r)
  - 2 = write (w)
  - 1 = execute (x)

  `chmod 754 foo` sets the following permissions:

        ```
        - user:   7 (4+2+1) rwx
        - group:  5 (4+1+0) r-x
        - others: 4 (4+0+0) r--
        ```

  `chmod 600 foo` sets the following permissions:

        ```
        - user:   6 (4+2+0) -> rw-
        - group:  0 (0+0+0) -> ---
        - others: 0 (0+0+0) -> ---
        ```

Assume initial permissions of rwxrw-rw-, what are the permission of each of the following files?

`chmod u=rwx,g=r,o= file2` sets the following permissions:

        ```
        - user:   7 (4+2+1) -> rwx
        - group:  4 (4+0+0) -> r--
        - others: 0 (0+0+0) -> ---
        ```

`chmod 441 file2` sets the following permissions:

        ```
        - user:   4 (4+0+0) -> r--
        - group:  4 (4+0+0) -> r--
        - others: 1 (0+0+1) -> --x
        ```

`chmod u+x file2` sets the following permissions:

        ```
        - user:   7 (4+2+1) -> rwx
        - group:  6 (4+2+0) -> rw-
        - others: 6 (4+2+0) -> rw-
        ```

`chmod u+rwx,g-x world file2` sets the following permissions:

        ```
        - user:   7 (4+2+1) -> rwx
        - group:  6 (4+2+0) -> rw-
        - others: 6 (4+2+0) -> rw-
        ```

`chmod 643 file2` sets the following permissions:

        ```
        - user:   6 (4+2+0) -> rw-
        - group:  4 (4+0+0) -> r--
        - others: 3 (0+2+1) -> -wx
        ```

#### Execute

execute permission on files means the right to execute them like commands if they are programs or shell scripts. (You should not give execute permission to non-program/script files. If you do, the content will be treated as a sequence of commands)

For dir, execute permission allows you to `cd` into that dir.

### Globbing

- `*` matches 0 or more characters
- `?` matches precisely one characters
- `[...]` matches specified characters in a set or in ranges
- `[^...]` negate the set defined in square brackets
- `[?...]` negate the set defined in square brackets
  - The POSIX (Portable Operating System Interface) standard for shell patterns only officially specifies `[!...]` for negation.
  - The `[^...]` syntax, while extremely common and supported by most modern shells, is technically an extension.
  - `[!...]` is the more standards-compliant and safer choice.
- **brace expansion**: `{p1, p2...}` matches/expand each globbing pattern one by one

#### Example

- `ls [^abc]*` & `ls [!abc]*` list files that **DO NOT** starts with `a`, `b` or `c`
- `*.[ch]` matches any string ending with `.c` or `.h`
- `{b*,c*,*est*}` matches string that start with `c`, start with `c` and contain `est`
- `touch chapter_{1,2,3,4}.md` create files named chapter[1-4].md
- `mv report.{docx,pdf,txt} ./archive/` mv report docx, pdf and txt file to archive
- `mkdir {2020..2025}_data`

### Text editors: vim, emacs, nano.

### I/O redirection

#### I/O streams

There are 3 standard output streams recognized by os and programming languages:

1. standard input: `stdin` (`cin`)
2. standard output: `stdout` (`cout`)
3. standard error: `stderr` (`cerr`)

#### I/O Redirection

The default value for standard input/output/error are: the terminal/console, keyboard(only input), display screen

- `myProgram < input` tells the program that the standard input is no longer the keyboard. It is the file input. (the characters in the file will be processed as if the user typed them with a keyboard).
- `myProgram > output` tells the program that the standard output is no longer the screen. It's file output. (the output of the program will be directly written to the file output)
- `myProgram < input > output`

- If the output file does not exist, it is created first
- use `>>` instead of `>` to append to the end of an existing file

#### /dev/null

if we don't care about a command's output, we can send it to /dev/null (and they are deleted forever). Use case: to prevent error messages to clutter output, redirect standard error to /dev/null

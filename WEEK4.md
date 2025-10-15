## aliasing and rc files

- `alias mv='mv -i'`: make prompting for overwrite during move a default option
- `alias ls='ls -al'`: always list file in long format and show hidden files
- `alias ...='cd ../..'`: to rapidly move to levels up
- use `unalias` to remove NAMEs from the list of defined aliases
- Aliases are only active for the current bash session. We can write the aliases inside .bashrc to make them permanent

## variables, environment variables

- accessible by the current shell session and child processes
- `export NAME=[VALUE]` to create them
- Common environment variables: `PATH`, `USER`, `SHELL`, `PWD`
- lvalues versus rvalues
  - `DATE=TUESDAY`: using the name as an lvalue
  - `echo $DATE`: using rvalue

## writing shell script

- shebang: `#!/bin/bash`, which is needed for portability and POSIX compliance
- to execute a shell script: `source script.sh` or `script.sh`
- to execute a script as a new process: make the script executable: `chmod +x script.sh`, and then run it as an executable program: `./script.sh`

```shell
#!/bin/sh
newdir=out
file=test.txt
mkdir -p $newdir
cd $newdir
# Redirect and Overwrite: This operator redirects the command's output to a file. If the file doesn't exist, it's created. If the file already exists, its contents are deleted and replaced with the new output.
echo "We generated this file" > $file
# Redirect and Append
echo "and wrote to it" >> $file
cd ..
```

## different types of quotes

In Bash, quoting is used to control how the shell interprets strings of characters. The three quoting mechanisms each work differently:

1.  **Escape Character (`\`)**

    - The backslash (`\`) is a non-enclosing quote that removes the special meaning of the single character immediately following it.
    - It's used to quote individual characters.
    - **Example:**
      ```bash
      echo "This is a dollar sign: \$"
      # Output: This is a dollar sign: $
      ```

2.  **Single Quotes (`' '`)**

    - Single quotes preserve the literal value of every character within them. No interpretation or expansion occurs.
    - This is the strictest form of quoting.
    - **Example:**
      ```bash
      USER="Eleanor"
      echo 'Hello, $USER'
      # Output: Hello, $USER
      ```

3.  **Double Quotes (`" "`)**
    - Double quotes preserve the literal value of most characters, but they allow the shell to perform certain expansions.
    - Specifically, they allow for:
      - **Variable expansion:** `$` (e.g., `$USER`)
      - **Command substitution:** `$(...)` or `` `...` ``
      - **Arithmetic expansion:** `$((...))`
    - **Example:**
      ```bash
      USER="Eleanor"
      echo "Hello, $USER"
      # Output: Hello, Eleanor
      ```

### Key Differences:

| Mechanism | Interpretation                                          | Use Case                                                                    |
| :-------- | :------------------------------------------------------ | :-------------------------------------------------------------------------- |
| **`\`**   | Removes special meaning from the next single character. | To escape a specific character.                                             |
| **`' '`** | None. All characters are treated as literals.           | When you want to prevent any kind of expansion or interpretation.           |
| **`" "`** | Allows variable, command, and arithmetic expansion.     | When you need to include variable values or command output within a string. |

## command substitution

use parenthesis for command substitution

```bash
echo "`ls`"
#1.txt 2.txt 3.txt

echo "$(ls)"
#1.txt 2.txt 3.txt
```

## string manipulation in Bash

`SUBSTR=${STR:5:3}`: `SUBSTR` will contain 3 characters of STR starting at index 5

## command line arguments

Each argument is stored as a special shell variable for use in a
command or script.

```
CMD arg1 arg2 arg3 arg4 ... arg10 ...
↑    ↑    ↑    ↑ ↑   ↑
$0   $1   $2   $3   $4 ... ${10} ...
```

### other built-in variables

- `$#`: The number of command line arguments supplied to the script
- `$*`: All the arguments treated as one double quoted string
- `$@`: All the arguments treated as individual double quoted strings. Can be used to loop through variables in for loops.
- `$$`: The process id of the current shell

```bash
#!/bin/bash
echo "Script name: $0"
echo "Process: $$"
echo "First arg: $1"
echo "Second arg: $2"
echo "All args: $*"
```

## Test command

- a successful test, i.e., true, has exit
  status 0.

```bash
#!/bin/bash
if [ $1 -le 10 ]; then
  echo "Enter a number larger than 10"
fi
```

```bash
#!/bin/bash
if  $1 -le 10; then
  echo "Enter a number larger than 10"
fi
```

### test on files

- `[-e file]`: true if file exists
- `[-d file]`: true if file exists, and it's a dir
- `[-r file]`: true if file exists, and it's readable
- `[-s file]`: true if file exists, and its size is greater than 0
- `[file1 -nt file2]`: true if file1 exists, and it's newer than file2

### test on strings

- `[ s1 = s2 ]`: true if strings are the same
- `[ s1 != s2 ]`: true if strings are not the same
- `[ -n string ]`: true if strings **is not** empty
- `[ -z string ]`: true if strings **is** empty
- `[ s1 < s2 ]`: true if s1 comes before s2 based on the binary value of their characters

### test on integers

- `[ n1 -eq n2 ]`: true if integers are equal
- `[ n1 -ne n2 ]`: true if integers are not equal
- `[ n1 -gt n2 ]`: true if n1 is greater than n2
- `[ n1 -ge n2 ]`: true if n1 is greater than or equal to n2
- `[ n1 -lt n2 ]`: true if n1 is less than n2
- `[ n1 -ln n2 ]`: true if n1 is less than or equal to n2

### logical operators

- `[ ! expression ]`: true if the expession is false
- `[ e1 -a e2 ]`: logical **AND** operator.
- `[ e1 -o e2 ]`: logical **OR** operator.
- `( expression )`: true if expression is true.

  - `( expression )`: (Subshell)

  ```bash
   Example:
   1 # The 'cd' command only affects the subshell
   2 echo "Current directory: $(pwd)"
   3 (cd /tmp && echo "Inside subshell: $(pwd)")
   4 echo "Back in original directory: $(pwd)"
  Output:

   1 Current directory: /Users/Eleanor/Desktop/CSM/CSCI210-system-programming-c
   2 Inside subshell: /tmp
   3 Back in original directory: /Users/Eleanor/Desktop/CSM/CSCI210-system-programming-c
  ```

## bash programming constructs: conditionals loops

```bash
#!/bin/bash
echo -n "Please enter a while number: "
read VAR
echo Your number is $VAR
if [ $VAR -gt 100 ]; then
  echo "It's greater than 100"
elif [ $VAR -lt 100 ]; then
  echo "It's less than 100"
else
  echo "It's exactly 100"
fi
```

### for loop

```bash
for VAR in {1..10..2}
do
  echo $VAR
done
```

```bash
for FILE in $(ls *.txt)
do
  echo $FILE
done
```

```bash
# c-style for loop
for (( i=1; i<10; i+=2))
do
  echo $i
done
```

## piping

channel standard input/output between programs.

data flows left to right

There are a suite of commands made especially for piping.

## `wc`, `head`, `tail`, `tr`, `sort`, and `uniq`

### `head` & `tail`

- `head -n [number] file`: print the first number lines of a file (by default 10 lines)
- `tail -n [number] file`: print the last number of a file (by default 10 lines)

EX: how to display line #5?

```
head -n 5 WEEK3.md | tail -1
```

EX: how to display line 4 - 5?

```
head -n 5 WEEK3.md | tail -2
```

### `sort`

- if no file is provided, it reads from standard input (stdin)
- sort order: Special characters, numbers, letters (lowercase before uppercase of same
  letter)

### `tee`

- copy standard input to standard output, making a copy in file
- `-a` **append** the output to the file rather than overwriting it (if without this flag, `tee` will overwrite existing content)

EX:

```
echo "hello" | tee -a WEEK3.md
```

### `uniq`

check for unique lines in file

IMPORTANT: Input must be sorted! Duplicates are only found if
adjacent

- `-c` count occurrences of each line
- `-d` output just the duplicate lines
- `-u` output just unique lines

### `tr`

either substitutes the characters in string1 to characters in string2 or deletes the character in string1 in standard input and output the result in standard output

- NOTE: does not take file input
- use `-c` to complement the characters in string1

`cat WEEK1.md | tr "[a-z]" "[A-Z]" > upper.txt` this command turns all the lowercase letters in WEEK1.md to uppercase letters and output to upper.txt

### `wc`

count the number of lines, words, bytes or character in file

- `-l` to count lines
- `-w` to count words
- `-c` to count bytes
- `-m` to count characters

## `grep`

- `-i` ignore case
- `-c` return toal match count (**of lines**) instead of line contents
- `-l` return the **names of matches files**, instead of line content
- `-n` show line numbers
- `-v` return lines which do not match pattern
- `-o` print only the matching parts on separate lines
- `-R` read the files in directories, recursively

#### REGEX

`.?*+{|()[\^$` are special characters

- `?*+{` are repetition operators

  - `.` matches any single character
  - `?` matches preceding item 0 or once
  - `*` matches preceding item 0 or more times
  - `+` matches preceding item 1 or more times

- `{` the one beginning with `{` are called interval expressions

  - `{n}` matches preceding item exactly n times
  - `{n,}` matches preceding item n times or more times
  - `{,m}` matches preceding item at most m times
  - `{n,m}` matches preceding item at least n times, but not more than m times

- the empty regex matches the empty string
- 2 regex patterns can be concatenated

  ```
      * Regex 1: [A-Z]+ (Matches one or more uppercase letters)
      * Regex 2: [0-9]{3} (Matches exactly three digits)
      * Concatenated Regex: [A-Z]+[0-9]{3}
      * Matches: "ABC123", "USER404", "X999"
      * Does NOT Match: "abc123" (fails [A-Z]+), "ABC-123" (the hyphen is not matched), "USER99" (fails [0-9]{3}).
  ```

  ```
   * Regex 1: \b[a-zA-Z0-9._%+-]+@ (Matches a typical email username part, ending with "@", on a word boundary)
   * Regex 2: [a-zA-Z0-9.-]+\.[a-zA-Z]{2,}\b (Matches a typical domain name part)
   * Concatenated Regex: \b[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}\b
   * Matches: A full email address like "user.name@example.com" or "test@sub.domain.co.uk". The first regex matches "user.name@", and the
     second immediately matches "example.com".
  ```

- Two regular expressions may be joined by ‘|’. Either of the two
  expressions, which are called alternatives, are matched
- **Repetition > Concatenation > Alternation**: Repetition takes precedence over concatenation, which in turn takes precedence over alternation. (see [notes](./regex-notes.md))

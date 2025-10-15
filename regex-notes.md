# Regular Expression Notes

## Concatenation

Two regular expressions may be concatenated; the resulting regular expression matches any string formed by concatenating two substrings that respectively match the concatenated expressions.

### Example 1: Literal Strings

*   **Regex 1:** `hello`
*   **Regex 2:** `world`
*   **Concatenated Regex:** `helloworld`
*   **Matches:** The literal string "helloworld".
*   **Does NOT Match:** "hello world" (because of the space), "worldhello".

### Example 2: Character Classes and Quantifiers

*   **Regex 1:** `[A-Z]+` (Matches one or more uppercase letters)
*   **Regex 2:** `[0-9]{3}` (Matches exactly three digits)
*   **Concatenated Regex:** `[A-Z]+[0-9]{3} `
*   **Matches:** "ABC123", "USER404", "X999"
*   **Does NOT Match:** "abc123" (fails `[A-Z]+`), "ABC-123" (the hyphen is not matched), "USER99" (fails `[0-9]{3}`).

---

## Operator Precedence

Repetition takes precedence over concatenation, which in turn takes precedence over alternation.

### 1. Repetition > Concatenation

The repetition operators (`*`, `+`, `?`, `{n}`) apply *only* to the single item immediately to their left.

**Example:** `cat+`

*   **How it's read:** This means "c", followed by "a", followed by one or more "t"s.
*   The `+` operator applies only to the `t`.
*   **Matches:** "cat", "catt", "cattt"
*   **Does NOT Match:** "catcatcat" (this would be `(cat)+`)

### 2. Concatenation > Alternation

Concatenation (joining items) is evaluated before alternation (`|`). The `|` operator acts as a separator for complete expressions on its left and right.

**Example:** `^cat|dog$`

*   **How it's read:** This means ("match 'cat' at the beginning of the string") OR ("match 'dog' at the end of the string").
*   **Matches:** "`cat`astrophe", "big `dog`"
*   **Does NOT Match:** "a `cat` in the middle", "the `dog` house"

To make the anchors apply to both "cat" and "dog", you must use parentheses to group the alternation first: `^(cat|dog)$`.

### All Together: Repetition > Concatenation > Alternation

**Example:** `gr(a|e)y+`

Here is how the engine evaluates it:

1.  **Repetition (`+`):** The `y+` is evaluated first. It means "one or more 'y's".
2.  **Concatenation:** The engine then concatenates `gr`, then the group `(a|e)`, then `y+`.
3.  **Alternation (`|`):** The `|` was handled inside the parentheses, which forces its precedence.

The final expression means: "g" followed by "r", followed by ("a" or "e"), followed by ("one or more 'y's").

*   **Matches:** "gray", "grey", "grayyy", "greyyy"
*   **Does NOT Match:** "graay", "gry", "g-ray"

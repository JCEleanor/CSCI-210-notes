#!/bin/bash
# echo "Now running script $0"
# echo "First argument: $1"
# echo "Second argument: $2"

# A=Hello World
# echo "$A

# command substitution
# echo "`ls`"
# echo "$(ls)"

# $$: The number of the command line args supplied to a script
echo "$#"

# see the current process ID
echo "$$"

[ -e README.md ] && echo "File exists" || echo "File does not exist"

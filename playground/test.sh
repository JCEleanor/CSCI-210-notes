#!/bin/bash

# Assign command output to a variable
# current_date=$(date)

# Use command output directly in another command
# echo "Today is $(date)"

# With backticks (older style)
# echo "Current directory is `pwd`"

x=4
while [ $x -le 9  ]
do
    echo -n $x
    x=$((x+2))
done

echo ""


for FILE in $(ls *.md)
do
   echo $FILE
done

# different results when using source or run directly
for VAR in {3..10..3}
do
    echo -n $VAR
done

echo ""

A=txt
B="a.$A"
if [ $B = a.txt ]; then
   echo "Equal"
else
   echo "Not Equal"
fi

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

# [ -e README.md ] && echo "File exists" || echo "File does not exist"

# bash can not deal with floating point arithmetic
C=$(python3 -c "print(2.2+3.6)") // 5.800000000000001
echo $C

#!/bin/bash

if [ "$#" -ne 3 ]; then
  echo "Invalid Argument: logFileQuery.sh <target dir> <person> <month>"
  exit 1
fi

case "$3" in
  Jan|Feb|Mar|Apr|May|Jun|Jul|Aug|Sep|Oct|Nov|Dec) ;;
  *)
    echo "Invalid Month Argument (allowed: Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec)"
    exit 1
    ;;
esac

# example command: ./logFileQuery.sh ExampleInputsOutputs/test01_in Jeremy Jan
TARGET_DIR=${1}
PERSON=${2}
MONTH=${3}
OUTPUT_DIR="queryResults"

echo "=====$PERSON: PERSORM SEARCH FOR $TARGET_DIR, $MONTH====="

if ([[ -d $OUTPUT_DIR ]]); then
    rm -rf $OUTPUT_DIR
    echo "=====reset old "$OUTPUT_DIR" directory====="
fi

mkdir -p $OUTPUT_DIR

# In other words, any file that contains the "dd/yyyy" pattern in any line 
# will be marked as a non-corrupt log file and processed as specified below.
# You can assume the years of the log files will be between 2010-2024.
YEAR_PATTERN="20(1[0-9]|2[0-4])"
VALID_DATE_PATTERN="[0-3][0-9]/$YEAR_PATTERN"

grep -r -h -E $VALID_DATE_PATTERN "$TARGET_DIR" \
  | grep "$PERSON" \
  | grep "$MONTH" \
  | while read -r LINE; do
    if [[ "$LINE" == *"$PERSON"* ]]; then
        # grep year, only the first match. To precent catching 2016 in "192.168.3.237 -- Phil [Mar/08/2022:23:54:47 -0700] 'Command' 269 20168042"
        YEAR=$(echo "$LINE" | grep -o -E -m 1 "$YEAR_PATTERN" | head -1)
        
        echo "$LINE" | grep -o -E -m 1 "$YEAR_PATTERN"
        echo "----"
        # create output file if not exists
        OUTPUT_FILE="${OUTPUT_DIR}/${PERSON}_${MONTH}_${YEAR}.log"

        # append line to output file
        echo "$LINE" >> "$OUTPUT_FILE"
    fi
done

# remove the last new line in each output file
for file in ${OUTPUT_DIR}/*; do
    if [[ -f "$file" && -s "$file" ]]; then
        # TODO: check if we're actually removing a new line not an output :目
        if tail -c1 "$file" | grep '^$'; then
            truncate -s -1 "$file"
            echo "Removed trailing newline from: $file"
        fi
    fi
done

# diff -s myQueryResults/Jeremy_Jan_2022.log ExampleInputsOutputs/test01_out/queryResults/Jeremy_Jan_2022.log

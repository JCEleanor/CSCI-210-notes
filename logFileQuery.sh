# There is a single log file for every month and you will identify them by looking for the "dd/yyyy" pattern in the files. 
# In other words, any file that contains the "dd/yyyy" pattern in any line will be marked as a non-corrupt log file and processed as specified below.

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

echo "$PERSON: PERSORM SEARCH FOR $TARGET_DIR, $MONTH"

# rm -rf queryResults
mkdir -p myQueryResults

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
        # grep year
        YEAR=$(echo "$LINE" | grep -o -E "$YEAR_PATTERN")
        
        # create output file if not exists
        OUTPUT_FILE="myQueryResults/${PERSON}_${MONTH}_${YEAR}.log"
        # append line to output file
        # FIXME: a new line in the last output when running 
        # diff myQueryResults/Jeremy_Jan_2022.log ExampleInputsOutputs/test01_out/queryResults/Jeremy_Jan_2022.log
        echo "$LINE" >> "$OUTPUT_FILE"
        
    fi
done

# TODO: error handling: invalid month or operation not permitted error

# The script should:
# Locate and identify the valid log files within the given target directory structure.
        # if the file contains the "dd/yyyy" pattern in any line



# Create a new directory named queryResults in the same directory where the script is run
# Create a separate log result file for each year in the queryResults directory with the following format:
# <personName>_<Mon>_<yyyy>.log

# should print the following error messages when:

# the number of provided parameters is not exactly three.
# Usage: ./logFileQuery.sh <target dir> <person> <month>
# The third parameter, i.e., the month, is not one of Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec.
# Invalid month

# Output
# Your script should create a directory named queryResults and create a separate file for each year that has a log file 
# that matches the given name and the month. 
# NOTE: If the input corrupted log directory does not contain any valid log files 
# or no valid log file matches the given name or the month, you should just create an empty queryResults directory. 
# Below is an example output directory with the log files created:
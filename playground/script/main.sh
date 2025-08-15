#!/bin/bash

# Here doc
cat << EOF
This is a
multi-line
string
EOF

# Command substitution
echo "Today is $(date)"

# Arithmetic expansion
echo "$((2 + 2))"

# Conditional expressions
if [ 1 -eq 1 ]; then
    echo "1 is equal to 1"
elif [ 1 -eq 2 ]; then
    echo "1 is not equal to 2"
else
    echo "1 is not equal to 2"
fi

# Arrays
array=(1 2 3 4 5)
for i in "${array[@]}"; do
    echo "${i}"
done

# Associative arrays
declare -A hash=([key1]=value1 [key2]=value2)
echo "${hash[key1]}"

# Functions
function add() {
    sum=$(( $1 + $2 ))
    echo "${sum}"
}

result=$(add 2 3)
echo "${result}"

# Heredoc
cat << EOF > file.txt
This is a
multi-line
string
EOF

# Here string
cat <<< "$(echo "This is a here string")"

# Subshell
(
    echo "This is a subshell"
)

# Piping
echo "This is a line" | while read line; do
    echo "${line}"
done

# Command chaining
echo "This is a line" | grep -i "is" | wc -l

# Command grouping
{
    echo "This is a line"
    echo "This is another line"
} | wc -l

# Command substitution
echo -n "This is a line"
echo -n "This is another line"
echo "$(echo -n "This is a line"; echo -n "This is another line")"

# Redirection
echo "This is a line" > file.txt
echo "This is another line" >> file.txt
cat file.txt

# Here redirection
cat > file.txt << EOF
This is a
multi-line
string
EOF

# Quoting
echo "This is a "quoted" string"
echo 'This is another "quoted" string'

# Escaping
echo "This is a \nnewline"
echo "This is a \t tab"
echo "This is a \\ backslash"
echo "This is a \' single quote"
echo "This is a \" double quote"

# Command line arguments
echo "${1}"
echo "${2}"
echo "${#}"

# Command line options
if [ "${1}" = "-h" ]; then
    echo "Help message"
fi

# Error handling
command || {
    echo "Error occurred"
    exit 1
}

# Variable expansion
var="This is a variable"
echo "${var}"
echo "${var:1:4}"

# Environment variables
export MY_VAR="This is an environment variable"
echo "${MY_VAR}"

# Special variables
echo "${PWD}"
echo "${UID}"
echo "${RANDOM}"

# Command aliasing
alias mycommand="echo 'This is a command alias'"
mycommand

# Sourcing a script
source script.sh

# Getting help
man echo
echo --help

# Getting version
echo --version

# Getting history
history

# Getting shell options
echo $-

# Getting shell variables
echo $SHELL
echo $HOME

# Getting shell functions
declare -f

# Getting shell aliases
alias

# Getting shell environment variables
env

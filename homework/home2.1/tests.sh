#!/bin/bash

# Define colors using ANSI escape codes
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

BINARY_NAME="./main" # or "java Main"

# Function to check output
check_output() {
    local expected_output=$1
    local actual_output=$2

    if [ "$actual_output" = "$expected_output" ]; then
        echo -e "${GREEN}Test Passed:${NC} Output is $actual_output"
    else
        echo -e "${RED}Test Failed:${NC} Output is $actual_output"
    fi
}

# Function to run a test case
run_test() {
    local test_description=$1
    local command=$2
    local expected_output=$3

    echo "$test_description"
    output=$($command)
    check_output "$expected_output" "$output"
}

# Function to check if file is empty
check_file_empty() {
    local file_name=$1

    if [ ! -s $file_name ]; then
        echo -e "${GREEN}Test Passed:${NC} $file_name is empty."
    else
        echo -e "${RED}Test Failed:${NC} $file_name is not empty."
    fi
}

# Test Case 1: First Time Run with a New Name
run_test "Test Case 1: First Time Run with a New Name" "$BINARY_NAME Alice" "Welcome, Alice!"

# Test Case 2: Multiple Runs with the Same Name
run_test "Test Case 2: Multiple Runs with the Same Name (First Run)" "$BINARY_NAME Bob" "Welcome, Bob!"
run_test "Test Case 2: Multiple Runs with the Same Name (Second Run)" "$BINARY_NAME Bob" "Hello again(2), Bob!"
run_test "Test Case 2: Multiple Runs with the Same Name (Third Run)" "$BINARY_NAME Bob" "Hello again(3), Bob!"

# Test Case 3: Reset Statistics for a Given Name
echo "Test Case 3: Reset Statistics for a Given Name"
$BINARY_NAME Bob delete
run_test "Test Case 3: After Reset" "$BINARY_NAME Bob" "Welcome, Bob!"

# Test Case 4: Use of Secret Word "bread" to Clear All History
echo "Test Case 4: Use of Secret Word 'bread' to Clear All History"
$BINARY_NAME bread
check_file_empty "user_stats.txt"

# Test Case 5: Invalid Input Handling
run_test "Test Case 5: Invalid Input Handling (No Arguments)" "$BINARY_NAME" "Error: Please provide a name as an argument."
run_test "Test Case 5: Invalid Input Handling (Extra Argument)" "$BINARY_NAME Frank extra_arg" "Error: Invalid arguments."
output=$($BINARY_NAME Frank)
if [[ "$output" == *"Welcome, Frank!"* || "$output" == *"Hello again("* ]]; then
    echo -e "${GREEN}Test Passed:${NC} Output is as expected for valid input."
else
    echo -e "${RED}Test Failed:${NC} Output is not as expected for valid input."
fi

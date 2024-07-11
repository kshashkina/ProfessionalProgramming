#!/bin/bash

# Define colors using ANSI escape codes
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

# Set the executable variable
EXECUTABLE="./main"  # Change to "java Main" for Java program

are_files_identical() {
    local file1="$1"
    local file2="$2"

    if diff "$file1" "$file2" > /dev/null; then
        return 0
    else
        return 1
    fi
}

check_test_case() {
    local test_case_desc="$1"
    local cmd="$2"
    local expected_file="$3"
    local actual_file="$4"

    echo "$test_case_desc"
    eval "$cmd"

    if [ -n "$expected_file" ] && [ -n "$actual_file" ]; then
        if are_files_identical "$expected_file" "$actual_file"; then
            echo -e "${GREEN}Test Passed: Files are identical.${NC}"
        else
            echo -e "${RED}Test Failed: Files are different.${NC}"
        fi
        rm -f "$actual_file"
    else
        if [ $? -eq 1 ] && [ ! -f "$actual_file" ]; then
            echo -e "${GREEN}Test Passed: Program handled the case correctly.${NC}"
        else
            echo -e "${RED}Test Failed: Program did not handle the case correctly.${NC}"
        fi
    fi
}

# Test Case 1: Basic Functionality
check_test_case "Test Case 1: Basic Functionality" "$EXECUTABLE input.txt 0 0 0 output.txt" "expected_output_test1.txt" "output.txt"

# Test Case 2: Input File with Invalid Number of strings
check_test_case "Test Case 2: Input File with Invalid Number of strings" "$EXECUTABLE input2.txt 0 0 0 output.txt" "" "output.txt"

# Test Case 3: Input File with Invalid Pixel Format
check_test_case "Test Case 3: Input File with Invalid Pixel Format" "$EXECUTABLE input3.txt 0 0 0 output.txt" "" "output.txt"

# Test Case 4: Non-existent Input File
check_test_case "Test Case 4: Non-existent Input File" "$EXECUTABLE no_input.txt 0 0 0 output.txt" "" "output.txt"

# Test Case 5: No Favorite Color in Image
check_test_case "Test Case 5: No Favorite Color in Image" "$EXECUTABLE input.txt 1 1 1 output.txt" "input.txt" "output.txt"

# Test Case 6: Invalid RGB Value for Favorite Color
check_test_case "Test Case 6: Invalid RGB Value for Favorite Color" "$EXECUTABLE input.txt 256 1 1 output.txt" "" "output.txt"

# Test Case 7: Basic Functionality with Unfavorite Color
check_test_case "Test Case 7: Basic Functionality with Unfavorite Color" "$EXECUTABLE input.txt 0 0 0 output.txt 255 255 255" "expected_output_test7.txt" "output.txt"

# Test Case 8: Invalid RGB Value for Unfavorite Color
check_test_case "Test Case 8: Invalid RGB Value for Unfavorite Color" "$EXECUTABLE input.txt 0 0 0 output.txt 256 256 256" "" "output.txt"

#!/bin/bash

# Define colors using ANSI escape codes
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

are_files_identical() {
    local file1="$1"
    local file2="$2"

    if diff "$file1" "$file2" > /dev/null; then
        return 0
    else
        return 1
    fi
}

# Test Case 1: Basic Functionality
echo "Test Case 1: Basic Functionality"
./main input.txt 0 0 0 output.txt
# Check if expected output is the same as the actual output
if are_files_identical "output.txt" "expected_output.txt"; then
    echo -e "${GREEN}Test Passed: Files are identical.${NC}"
else
    echo -e "${RED}Test Failed: Files are different.${NC}"
fi
rm output.txt


# Test Case 2: Input File with Invalid Number of strings
echo "Test Case 2: Input File with Invalid Number of strings"
./main input2.txt 0 0 0 output.txt
# Check if the program exited with an error and output file does not exist
if [ $? -eq 1 ] && [ ! -f "output.txt" ]; then
    echo -e "${GREEN}Test Passed: Program threw an exception for invalid input format.${NC}"
else
    echo -e "${RED}Test Failed: Either program did not handle invalid input format or output file exists.${NC}"
fi

# Test Case 3: Input File with Invalid Pixel Format
echo "Test Case 3: Input File with Invalid Pixel Format"
./main input3.txt 0 0 0 output.txt
# Check if the program exited with an error and output file does not exist
if [ $? -eq 1 ] && [ ! -f "output.txt" ]; then
    echo -e "${GREEN}Test Passed: Program threw an exception for invalid input format.${NC}"
else
    echo -e "${RED}Test Failed: Either program did not handle invalid input format or output file exists.${NC}"
fi

# Test Case 4: Non-existent Input File
echo "Test Case 4: Non-existent Input File"
./main no_input.txt 0 0 0 output.txt
if [ $? -eq 1 ] && [ ! -f "output.txt" ]; then
    echo -e "${GREEN}Test Passed: Program threw an exception for invalid input format.${NC}"
else
    echo -e "${RED}Test Failed: Either program did not handle invalid input format or output file exists.${NC}"
fi

# Test Case 5: No Favorite Color in Image
echo "Test Case 5: No Favorite Color in Image"
./main input.txt 1 1 1 output.txt
if are_files_identical "output.txt" "input.txt"; then
    echo -e "${GREEN}Test Passed: Files are identical.${NC}"
else
    echo -e "${RED}Test Failed: Files are different.${NC}"
fi
rm output.txt

# Test Case 6: Invalid RGB Value for Favorite Color
echo "Test Case 6: Invalid RGB Value for Favorite Color"
./main input.txt 256 1 1 output.txt
if [ $? -eq 1 ] && [ ! -f "output.txt" ]; then
    echo -e "${GREEN}Test Passed: Program threw an exception for invalid RGB value.${NC}"
else
    echo -e "${RED}Test Failed: Program did not handle invalid RGB value.${NC}"
fi


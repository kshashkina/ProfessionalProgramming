#!/bin/bash

# Define colors using ANSI escape codes
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

# Set the executable variable
EXECUTABLE="./main"

check_test_case() {
    local test_case_desc="$1"
    local input="$2"
    local expected_output="$3"

    echo "$test_case_desc"
    actual_output=$(echo -e "$input" | $EXECUTABLE ingredients.txt)

    # Extract the part of actual output after "Your pizza ingredients:"
    actual_output_part=$(echo "$actual_output" | awk '/Your pizza ingredients:/ {p=1; next} p')

    if [ "$actual_output_part" == "$expected_output" ]; then
        echo -e "${GREEN}Test Passed: Output is as expected.${NC}"
    else
        echo -e "${RED}Test Failed: Output is not as expected.${NC}"
        echo -e "${RED}Expected:${NC}"
        echo "$expected_output"
        echo -e "${RED}Got:${NC}"
        echo "$actual_output_part"
    fi
}

# Test Case 1: Basic Functionality
expected_output1="- Cheese (\$2.5)
- Pepperoni (\$3)
Total cost: \$5.5"
check_test_case "Test Case 1: Basic Functionality" "Cheese\nPepperoni\ndone" "$expected_output1"

# Test Case 2: Ingredient Not Found
expected_output2="Total cost: \$0"
check_test_case "Test Case 2: Ingredient Not Found" "Pear\ndone" "$expected_output2"

# Test Case 3: Mixed Valid and Invalid Ingredients
expected_output3="- Cheese (\$2.5)
- Pepperoni (\$3)
Total cost: \$5.5"
check_test_case "Test Case 3: Mixed Valid and Invalid Ingredients" "Cheese\nPear\nPepperoni\ndone" "$expected_output3"

# Test Case 4: No Ingredients Added
expected_output4="Total cost: \$0"
check_test_case "Test Case 4: No Ingredients Added" "done" "$expected_output4"

#!/bin/bash

# Define colors using ANSI escape codes
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

# Test Case 1: First Time Run with a New Name
echo "Test Case 1: First Time Run with a New Name"
output=$(java Main Alice)
if [ "$output" = "Welcome, Alice!" ]; then
    echo -e "${GREEN}Test Passed:${NC} Output is $output"
else
    echo -e "${RED}Test Failed:${NC} Output is $output"
fi

# Test Case 2: Multiple Runs with the Same Name
echo "Test Case 2: Multiple Runs with the Same Name"
output=$(java Main Bob)
if [ "$output" = "Welcome, Bob!" ]; then
    echo -e "${GREEN}Test Passed:${NC} Output is $output"
else
    echo -e "${RED}Test Failed:${NC} Output is $output"
fi

output=$(java Main Bob)
if [ "$output" = "Hello again(2), Bob!" ]; then
    echo -e "${GREEN}Test Passed:${NC} Output is $output"
else
    echo -e "${RED}Test Failed:${NC} Output is $output"
fi

output=$(java Main Bob)
if [ "$output" = "Hello again(3), Bob!" ]; then
    echo -e "${GREEN}Test Passed:${NC} Output is $output"
else
    echo -e "${RED}Test Failed:${NC} Output is $output"
fi

# Test Case 3: Reset Statistics for a Given Name
echo "Test Case 3: Reset Statistics for a Given Name"
java Main Bob delete
output=$(java Main Bob)
if [ "$output" = "Welcome, Bob!" ]; then
    echo -e "${GREEN}Test Passed:${NC} Output is $output"
else
    echo -e "${RED}Test Failed:${NC} Output is $output"
fi

# Test Case 4: Use of Secret Word "bread" to Clear All History
echo "Test Case 4: Use of Secret Word 'bread' to Clear All History"
java Main bread

# Check if user_stats.txt is empty
if [ ! -s user_stats.txt ]; then
    echo -e "${GREEN}Test Passed:${NC} History has been cleared successfully."
else
    echo -e "${RED}Test Failed:${NC} History has not been cleared."
fi

# Test Case 5: Invalid Input Handling
echo "Test Case 5: Invalid Input Handling"
output=$(java Main)
if [ "$output" = "Error: Please provide a name as an argument." ]; then
    echo -e "${GREEN}Test Passed:${NC} Output is $output"
else
    echo -e "${RED}Test Failed:${NC} Output is $output"
fi

output=$(java Main Frank extra_arg)
if [ "$output" = "Error: Invalid arguments." ]; then
    echo -e "${GREEN}Test Passed:${NC} Output is $output"
else
    echo -e "${RED}Test Failed:${NC} Output is not $output"
fi

output=$(java Main Frank)
if [[ "$output" == *"Welcome, Frank!"* || "$output" == *"Hello again("* ]]; then
    echo -e "${GREEN}Test Passed:${NC} Output is as expected for valid input."
else
    echo -e "${RED}Test Failed:${NC} Output is not as expected for valid input."
fi

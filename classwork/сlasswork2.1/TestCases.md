### Test Case 1: First Time Run with a New Name

**Steps:**
1. Ensure there is no pre-existing history for the name "Alice".
2. Run the program with the argument "Alice".
3. Verify that the output is "Welcome, Alice!".
4. Check the history to confirm that "Alice" is recorded with one run.

**Expected Result:**
- First run should display "Welcome, Alice!".

### Test Case 2: Multiple Runs with the Same Name

**Steps:**
1. Ensure there is no pre-existing history for the name "Bob".
2. Run the program with the argument "Bob".
3. Verify that the output is "Welcome, Bob!".
4. Run the program again with the argument "Bob".
5. Verify that the output is "Hello again(2), Bob".
6. Run the program a third time with the argument "Bob".
7. Verify that the output is "Hello again(3), Bob".

**Expected Result:**
- First run should display "Welcome, Bob!".
- Second run should display "Hello again(2), Bob".
- Third run should display "Hello again(3), Bob".

### Test Case 3: Reset Statistics for a Given Name

**Steps:**
1. Ensure there is a pre-existing history for the name "Charlie" with at least two runs.
2. Run the program with the arguments "Charlie" and "delete".
3. Verify that the output confirms the reset.
4. Run the program again with the argument "Charlie".
5. Verify that the output is "Welcome, Charlie!".
6. Check the history to confirm that "Charlie" is recorded with one run after the reset.

**Expected Result:**
- Reset operation should be acknowledged.
- First run after reset should display "Welcome, Charlie!".

### Test Case 4: Use of Secret Word "bread" to Clear All History

**Steps:**
1. Ensure there is a pre-existing history for the names "Dave" and "Eve" with at least one run each.
2. Run the program with the argument "bread".
3. Verify that the output confirms the extermination of the history (exact message depends on implementation).
4. Run the program again with the argument "Dave".
5. Verify that the output is "Welcome, Dave!".
6. Run the program again with the argument "Eve".
7. Verify that the output is "Welcome, Eve!".

**Expected Result:**
- History should be cleared for all names after running with "bread".
- First runs after extermination should display "Welcome, *name* !".

### Test Case 5: Invalid Input Handling

**Steps:**
1. Run the program without any arguments.
2. Verify that the output is an error message indicating the need for a name argument.
3. Run the program with more than two arguments (e.g., "Frank extra_arg").
4. Verify that the output is an error message indicating invalid input.
5. Run the program with valid arguments to ensure normal functionality is not affected (e.g., "Frank").
6. Verify that the output is "Welcome, Frank!" if it's the first run, or "Hello again(*N*), Frank" otherwise.

**Expected Result:**
- Program should display an error message for missing or too many arguments.
- Program should function normally with valid input.

### Test Case 1: First Time Run with a New Name

**Precondition:**
- Ensure there is no pre-existing history for the name "Alice".

**Steps and Expected Results:**
1. **Step:** Run the program with the argument "Alice" using `./hello Alice`.
    - **Expected Result:** Program output "Welcome, Alice!".
2. **Step:** Check the history for the name "Alice".
    - **Expected Result:** "Alice" is recorded with one run.

### Test Case 2: Multiple Runs with the Same Name

**Precondition:**
- Ensure there is no pre-existing history for the name "Bob".

**Steps and Expected Results:**
1. **Step:** Run the program with the argument "Bob" using `./hello Bob`.
    - **Expected Result:** Program output "Welcome, Bob!".
2. **Step:** Run the program again with the argument "Bob" using `./hello Bob`.
    - **Expected Result:** Program output "Hello again(2), Bob".
3. **Step:** Run the program a third time with the argument "Bob" using `./hello Bob`.
    - **Expected Result:** Program output "Hello again(3), Bob".

### Test Case 3: Reset Statistics for a Given Name

**Precondition:**
- Ensure there is a pre-existing history for the name "Charlie" with at least two runs.

**Steps and Expected Results:**
1. **Step:** Run the program with the arguments "Charlie" and "delete" using `./hello Charlie delete`.
    - **Expected Result:** Program output confirms the reset.
2. **Step:** Run the program again with the argument "Charlie" using `./hello Charlie`.
    - **Expected Result:** Program output "Welcome, Charlie!".
3. **Step:** Check the history for the name "Charlie".
    - **Expected Result:** "Charlie" is recorded with one run after the reset.

### Test Case 4: Use of Secret Word "bread" to Clear All History

**Precondition:**
- Ensure there is a pre-existing history for the names "Dave" and "Eve" with at least one run each.

**Steps and Expected Results:**
1. **Step:** Run the program with the argument "bread" using `./hello bread`.
    - **Expected Result:** Program output confirms the extermination of the history (exact message depends on implementation).
2. **Step:** Run the program again with the argument "Dave" using `./hello Dave`.
    - **Expected Result:** Program output "Welcome, Dave!".
3. **Step:** Run the program again with the argument "Eve" using `./hello Eve`.
    - **Expected Result:** Program output "Welcome, Eve!".

### Test Case 5: Invalid Input Handling

**Steps and Expected Results:**
1. **Step:** Run the program without any arguments using `./hello`.
    - **Expected Result:** Program output an error message indicating the need for a name argument.
2. **Step:** Run the program with more than two arguments (e.g., `./hello Frank extra_arg`).
    - **Expected Result:** Program output an error message indicating invalid input.
3. **Step:** Run the program with valid arguments to ensure normal functionality is not affected (e.g., `./hello Frank`).
    - **Expected Result:** Program output "Welcome, Frank!" if it's the first run, or "Hello again(*N*), Frank" otherwise.

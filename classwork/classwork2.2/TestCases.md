### Test Case 1: Basic Functionality

#### Precondition:
Choose an input file `input.txt` with a 16x16 grid of pixels. Each pixel is represented as `R,G,B`.

#### Steps:
1. **Step 1:** Set favorite color to `(0, 0, 0)`.
    - **Expected Result:** Favorite color is set correctly in the program.
2. **Step 2:** Set the output file name to `output.txt`.
    - **Expected Result:** Output file name is set correctly in the program.
3. **Step 3:** Execute the program with the specified input and output file names and favorite color.
    - **Expected Result:** Program runs successfully without errors.
4. **Step 4:** Check `output.txt` to ensure pixels adjacent to favorite color pixels are updated correctly.
    - **Expected Result:** The output file has the correct pixels updated based on the favorite color logic.

### Test Case 2: Input File with Invalid Number of Strings

#### Precondition:
Choose an input file `input2.txt` with an invalid number of strings.

#### Steps:
1. **Step 1:** Set favorite color to `(0, 0, 0)`.
    - **Expected Result:** Favorite color is set correctly in the program.
2. **Step 2:** Set the output file name to `output.txt`.
    - **Expected Result:** Output file name is set correctly in the program.
3. **Step 3:** Execute the program with the specified input and output file names and favorite color.
    - **Expected Result:** Program throws an exception and prints an error message.
4. **Step 4:** Check if the output file `output.txt` exists.
    - **Expected Result:** Output file does not exist.

### Test Case 3: Input File with Invalid Pixel Format

#### Precondition:
Choose an input file `input3.txt` with an invalid pixel format.

#### Steps:
1. **Step 1:** Set favorite color to `(0, 0, 0)`.
    - **Expected Result:** Favorite color is set correctly in the program.
2. **Step 2:** Set the output file name to `output.txt`.
    - **Expected Result:** Output file name is set correctly in the program.
3. **Step 3:** Execute the program with the specified input and output file names and favorite color.
    - **Expected Result:** Program throws an exception and prints an error message.
4. **Step 4:** Check if the output file `output.txt` exists.
    - **Expected Result:** Output file does not exist.

### Test Case 4: Non-existent Input File

#### Precondition:
Choose a non-existing input file `no_input.txt`.

#### Steps:
1. **Step 1:** Set favorite color to `(0, 0, 0)`.
    - **Expected Result:** Favorite color is set correctly in the program.
2. **Step 2:** Set the output file name to `output.txt`.
    - **Expected Result:** Output file name is set correctly in the program.
3. **Step 3:** Execute the program with the specified input and output file names and favorite color.
    - **Expected Result:** Program throws an exception and prints an error message indicating that the input file could not be opened.
4. **Step 4:** Check if the output file `output.txt` exists.
    - **Expected Result:** Output file does not exist.

### Test Case 5: No Favorite Color in Image

#### Precondition:
Choose an input file `input.txt` with a 16x16 grid of pixels where the favorite color `(1, 1, 1)` does not appear at all.

#### Steps:
1. **Step 1:** Set favorite color to `(1, 1, 1)`.
    - **Expected Result:** Favorite color is set correctly in the program.
2. **Step 2:** Set the output file name to `output.txt`.
    - **Expected Result:** Output file name is set correctly in the program.
3. **Step 3:** Execute the program with the specified input and output file names and favorite color.
    - **Expected Result:** Program runs successfully without errors.
4. **Step 4:** Check `output.txt` to ensure no pixels are updated since the favorite color is not present.
    - **Expected Result:** The output file is identical to the input file, with no changes made.

### Test Case 6: Invalid RGB Value for Favorite Color

#### Precondition:
Choose an input file `input.txt` with a 16x16 grid of pixels.

#### Steps:
1. **Step 1:** Set an invalid favorite color `(256, 100, 100)`.
    - **Expected Result:** Program validates the favorite color and prints an error message.
2. **Step 2:** Set the output file name to `output.txt`.
    - **Expected Result:** Output file name is set correctly in the program.
3. **Step 3:** Execute the program with the specified input and output file names and favorite color.
    - **Expected Result:** Program does not process the image and prints an error message.
4. **Step 4:** Check if the output file `output.txt` exists.
    - **Expected Result:** Output file does not exist.

Here are additional test cases to test the functionality correlated with the unfavorite color:

### Test Case 7: Basic Functionality with Unfavorite Color

#### Precondition:
Choose an input file `input.txt` with a 16x16 grid of pixels. Each pixel is represented as `R,G,B`.

#### Steps:
1. **Step 1:** Set favorite color to `(0, 0, 0)` and unfavorite color to `(255, 255, 255)`.
   - **Expected Result:** Favorite and unfavorite colors are set correctly in the program.
2. **Step 2:** Set the output file name to `output.txt`.
   - **Expected Result:** Output file name is set correctly in the program.
3. **Step 3:** Execute the program with the specified input and output file names, favorite color, and unfavorite color.
   - **Expected Result:** Program runs successfully without errors.
4. **Step 4:** Check `output.txt` to ensure pixels that were the unfavorite color are updated to the favorite color.
   - **Expected Result:** The output file has the correct pixels updated based on the favorite and unfavorite color logic.

### Test Case 8: Invalid RGB Value for Unfavorite Color

#### Precondition:
Choose an input file `input.txt` with a 16x16 grid of pixels.

#### Steps:
1. **Step 1:** Set favorite color to `(0, 0, 0)` and an invalid unfavorite color `(256, 255, 255)`.
   - **Expected Result:** Program validates the unfavorite color and prints an error message.
2. **Step 2:** Set the output file name to `output.txt`.
   - **Expected Result:** Output file name is set correctly in the program.
3. **Step 3:** Execute the program with the specified input and output file names, favorite color, and unfavorite color.
   - **Expected Result:** Program does not process the image and prints an error message.
4. **Step 4:** Check if the output file `output.txt` exists.
   - **Expected Result:** Output file does not exist.
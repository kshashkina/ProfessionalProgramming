### Test Case 1: Basic Functionality

#### Steps:
1. **Input Preparation:** Choose an input file `input1.txt` with a 16x16 grid of pixels. Each pixel is represented as `R,G,B`.
2. **Favorite Color:** Choose a favorite color `(100, 150, 200)`.
3. **Output File:** Set the output file name to `output1.txt`.
4. **Run the Program:** Execute the program with the specified input and output file names and favorite color.
5. **Verify Output:** Check `output1.txt` to ensure pixels adjacent to favorite color pixels are updated correctly.

**Expected Outcome:** The output file should have the correct pixels updated based on the favorite color logic.

### Test Case 2: Input File with Invalid Number of strings

#### Steps:
1. **Input Preparation:** Choose an input file `input2.txt` with invalid number of strings.
2. **Favorite Color:** Choose a favorite color `(50, 50, 50)`.
3. **Output File:** Set the output file name to `output2.txt`.
4. **Run the Program:** Execute the program with the specified input and output file names and favorite color.
5. **Verify Output:** Check the program's error handling for invalid input format.

**Expected Outcome:** The program should throw an exception and print an error message. Output file does not exist.

### Test Case 3: Input File with Invalid Pixel Format

#### Steps:
1. **Input Preparation:** Choose an input file `input2.txt` with invalid pixel format.
2. **Favorite Color:** Choose a favorite color `(50, 50, 50)`.
3. **Output File:** Set the output file name to `output3.txt`.
4. **Run the Program:** Execute the program with the specified input and output file names and favorite color.
5. **Verify Output:** Check the program's error handling for invalid input format.

**Expected Outcome:** The program should throw an exception and print an error message. Output file does not exist.

### Test Case 4: Non-existent Input File

#### Steps:
1. **Input Preparation:** Choose non-existing input file `input4.txt`.
2. **Favorite Color:** Choose a favorite color `(0, 0, 0)`.
3. **Output File:** Set the output file name to `output4.txt`.
4. **Run the Program:** Execute the program with the specified input and output file names and favorite color.
5. **Verify Output:** Check the program's error handling for a non-existent input file.

**Expected Outcome:** The program should throw an exception and print an error message indicating that the input file could not be opened. Output file does not exist.


### Test Case 5: No Favorite Color in Image

#### Steps:
1. **Input Preparation:** Choose an input file `input5.txt` with a 16x16 grid of pixels where the favorite color `(1, 1, 1)` does not appear at all.
2. **Favorite Color:** Choose a favorite color `(1, 1, 1)`.
3. **Output File:** Set the output file name to `output5.txt`.
4. **Run the Program:** Execute the program with the specified input and output file names and favorite color.
5. **Verify Output:** Check `output5.txt` to ensure no pixels are updated since the favorite color is not present.

**Expected Outcome:** The output file should be identical to the input file, with no changes made.

### Test Case 6: Invalid RGB Value for Favorite Color

#### Steps:
1. **Input Preparation:** Choose an input file `input6.txt` with a 16x16 grid of pixels.
2. **Favorite Color:** Choose an invalid favorite color `(256, 100, 100)`.
3. **Output File:** Set the output file name to `output6.txt`.
4. **Run the Program:** Execute the program with the specified input and output file names and favorite color.
5. **Verify Output:** Check the program's error handling for an invalid favorite color value.

**Expected Outcome:** The program should validate the favorite color and print an error message without processing the image. Output file does not exist.


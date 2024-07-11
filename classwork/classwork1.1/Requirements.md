### User Story A:
As a cool programmer guy I want to have an ability to find the biggest negative value from the provided list of numbers. It will allow me to make my manual calculation faster.
#### Requirements:
1. **User Input:**
    - User shall be able to input a list of numbers.

2. **Functionality:**
    - Program should be able to parse the input list and identify all negative numbers.
    - Program should be able to compare the negative numbers and determine the largest one.

3. **Output:**
    - Program should be able to display the largest negative number from the list.
    - If there are no negative numbers, the program should notify the user accordingly.

4. **Error Handling:**
    - Program should be able to handle cases where the input list is empty and notify the user appropriately.
    - Program should be able to handle non-numeric inputs gracefully, providing an error message.

### User Story B:
As a cool mathematician I want to be able to get roots of the quadratic equation ax^2 + bx + c. It will allow me to avoid hard calculations related to determinant.
#### Requirements:
1. **User Input:**
   - User shall be able to input the coefficients a, b, and c of the quadratic equation.

2. **Functionality:**
   - Program should be able to calculate the determinant (b^2 - 4ac).
   - Program should be able to determine the nature of the roots based on the determinant:
      - If the determinant is greater than or equal to zero, the program should calculate the roots.
      - If the determinant is smaller than zero, the program should indicate that the equation does not have real roots.
   - Program should be able to calculate the roots of the quadratic equation using the quadratic formula

3. **Output:**
   - Program should be able to display the roots of the quadratic equation if the determinant is greater than or equal to zero.
   - If the determinant is smaller than zero, the program should display a message indicating that the equation with the provided coefficients does not have real roots.

4. **Error Handling:**
   - Program should validate that the coefficient 'a' is not zero (as it would not be a quadratic equation in that case) and notify the user appropriately.
   - Program should be able to handle invalid inputs (non-numeric coefficients) and provide an error message.

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class CalculationTest {

    @org.junit.Test
    @Test
    public void testInverseOfProduct() {
        // Test case where product is non-zero
        double x = 2.0;
        double y = 3.0;
        double z = 4.0;
        double expected = 1.0 / (x * y * z);
        assertEquals(expected, Calculation.calculate(x, y, z), 1e-9);
    }

    @Test
    public void testInverseOfSum() {
        // Test case where product is zero but sum is non-zero
        double x = 0.0;
        double y = 2.0;
        double z = 3.0;
        double expected = 1.0 / (x + y + z);
        assertEquals(expected, Calculation.calculate(x, y, z), 1e-9);
    }

    @Test
    public void testSpecialCalculation() {
        // Test case where both product and sum are zero
        double x = 0.0;
        double y = -1.0;
        double z = 1.0;
        double expected = x + (y + 1) * (z - 1);
        assertEquals(expected, Calculation.calculate(x, y, z), 1e-9);
    }

    @Test
    public void testNegativeValues() {
        // Test case with negative values
        double x = -1.0;
        double y = 2.0;
        double z = -3.0;
        double expected = 1.0 / (x * y * z); // should be inverse of the product
        assertEquals(expected, Calculation.calculate(x, y, z), 1e-9);
    }
}

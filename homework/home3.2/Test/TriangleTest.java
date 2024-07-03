import org.example.Triangle;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class TriangleTest {

    @Test
    public void testArea_3_4_5() {
        Triangle triangle = new Triangle(3, 4, 5);
        double s = (3 + 4 + 5) / 2.0;
        double expected = Math.sqrt(s * (s - 3) * (s - 4) * (s - 5));
        assertEquals(expected, triangle.area(), 1e-9);
    }

    @Test
    public void testArea_1_1_1() {
        Triangle triangle = new Triangle(1, 1, 1);
        double s = (1 + 1 + 1) / 2.0;
        double expected = Math.sqrt(s * (s - 1) * (s - 1) * (s - 1));
        assertEquals(expected, triangle.area(), 1e-9);
    }

    @Test
    public void testArea_5_12_13() {
        Triangle triangle = new Triangle(5, 12, 13);
        double s = (5 + 12 + 13) / 2.0;
        double expected = Math.sqrt(s * (s - 5) * (s - 12) * (s - 13));
        assertEquals(expected, triangle.area(), 1e-9);
    }

    @Test
    public void testNegativeSide() {
        Triangle triangle = new Triangle(-3, 4, 5);
        assertEquals(-1, triangle.area());
    }

    @Test
    public void testZeroSide() {
        Triangle triangle = new Triangle(0, 4, 5);
        assertEquals(-1, triangle.area());
    }

    @Test
    public void testInvalidTriangle() {
        Triangle triangle = new Triangle(1, 2, 3);
        assertEquals(-1, triangle.area());
    }

    @Test
    public void testHeightForSideA() {
        Triangle triangle = new Triangle(3, 4, 5);
        double expectedHeight = (2 * triangle.area()) / 3;
        assertEquals(expectedHeight, triangle.getHeight('a'), 1e-9);
    }

    @Test
    public void testHeightForSideB() {
        Triangle triangle = new Triangle(3, 4, 5);
        double expectedHeight = (2 * triangle.area()) / 4;
        assertEquals(expectedHeight, triangle.getHeight('b'), 1e-9);
    }

    @Test
    public void testHeightForSideC() {
        Triangle triangle = new Triangle(3, 4, 5);
        double expectedHeight = (2 * triangle.area()) / 5;
        assertEquals(expectedHeight, triangle.getHeight('c'), 1e-9);
    }

    @Test
    public void testInvalidSide() {
        Triangle triangle = new Triangle(3, 4, 5);
        assertThrows(IllegalArgumentException.class, () -> {
            triangle.getHeight('d');
        });
    }

    @Test
    public void testHeightForNegativeSide() {
        Triangle triangle = new Triangle(-3, 4, 5);
        assertEquals(-1, triangle.getHeight('a'), 1e-9);
        assertEquals(-1, triangle.getHeight('b'), 1e-9);
        assertEquals(-1, triangle.getHeight('c'), 1e-9);
    }

    @Test
    public void testHeightForZeroSide() {
        Triangle triangle = new Triangle(0, 4, 5);
        assertEquals(-1, triangle.getHeight('a'), 1e-9);
        assertEquals(-1, triangle.getHeight('b'), 1e-9);
        assertEquals(-1, triangle.getHeight('c'), 1e-9);
    }

    @Test
    public void testHeightForInvalidTriangle() {
        Triangle triangle = new Triangle(1, 2, 3);
        assertEquals(-1, triangle.getHeight('a'), 1e-9);
        assertEquals(-1, triangle.getHeight('b'), 1e-9);
        assertEquals(-1, triangle.getHeight('c'), 1e-9);
    }
}

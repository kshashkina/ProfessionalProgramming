import org.example.MegaData;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

class MegaDataTest {

    private MegaData data;

    @BeforeEach
    void setUp() {
        data = new MegaData();
    }

    @Test
    void testInitialization() {
        for (int i = 0; i < MegaData.SMALL_ARRAY_SIZE; i++) {
            assertEquals(42.0f, data.smallArray[i]);
        }
        for (int i = 0; i < MegaData.BIG_ARRAY_SIZE; i++) {
            assertEquals(42.0, data.bigArray[i]);
        }
    }

    @Test
    void testReset() {
        data.smallArray[0] = 0.0f;
        data.bigArray[0] = 0.0;
        data.reset();
        assertEquals(42.0f, data.smallArray[0]);
        assertEquals(42.0, data.bigArray[0]);
    }
}
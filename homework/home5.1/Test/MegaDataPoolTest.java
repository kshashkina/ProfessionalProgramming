import org.example.MegaData;
import org.example.MegaDataPool;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import java.util.NoSuchElementException;

import static org.junit.jupiter.api.Assertions.*;

class MegaDataPoolTest {

    private MegaDataPool pool;

    @BeforeEach
    void setUp() {
        pool = new MegaDataPool(2);
    }

    @Test
    void testAcquireRelease() {
        assertEquals(2, pool.size());
        assertEquals(0, pool.usedSize());

        MegaData data1 = pool.acquire();
        assertEquals(1, pool.usedSize());

        MegaData data2 = pool.acquire();
        assertEquals(2, pool.usedSize());

        pool.release(data1);
        assertEquals(1, pool.usedSize());

        pool.release(data2);
        assertEquals(0, pool.usedSize());
    }

    @Test
    void testPoolExhaustion() {
        MegaDataPool pool = new MegaDataPool(1);
        MegaData data1 = pool.acquire();
        assertNotNull(data1);
        assertThrows(NoSuchElementException.class, () -> {
            pool.acquire();
        });

        pool.release(data1);
    }
}
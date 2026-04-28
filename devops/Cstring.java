import org.junit.Test;
import static org.junit.Assert.*;

public class MessageTest {

    @Test
    public void testMessage() {
        String expected = "Hello";
        String actual = "Hello";

        assertEquals(expected, actual);
    }
}
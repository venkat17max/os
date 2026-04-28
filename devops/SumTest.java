
//this in Sum.java file
class Sum {
    int add(int a, int b) {
        return a + b;
    }
}

//this in SumTest.java file
import org.junit.Test;
import static org.junit.Assert.*;
public class SumTest {

    @Test
    public void testAddition() {
        Sum obj = new Sum();

        int result = obj.add(2, 3);

        assertEquals(5, result);
    }
}
//create this in Calculator.java
class Calculator {

    int add(int a, int b) {
        return a + b;
    }

    int sub(int a, int b) {
        return a - b;
    }

    int mul(int a, int b) {
        return a * b;
    }

    int div(int a, int b) {
        return a / b;
    }
}
//this program in CalculatorTest
import org.junit.Test;
import static org.junit.Assert.*;

public class CalculatorTest {

    Calculator calc = new Calculator();

    @Test
    public void testAdd() {
        assertEquals(5, calc.add(2, 3));
    }

    @Test
    public void testSub() {
        assertEquals(1, calc.sub(3, 2));
    }

    @Test
    public void testMul() {
        assertEquals(6, calc.mul(2, 3));
    }

    @Test
    public void testDiv() {
        assertEquals(2, calc.div(4, 2));
    }
}
package one;
public class App {
    public static int factorial(int input) {
        if (input > 1)
            return input * factorial(input-1);
        else
            return 1;
    }

    public static int isOdd(int input) {
        if (input % 2 == 0)
            return 1;
        else
            return -1;
    }
}

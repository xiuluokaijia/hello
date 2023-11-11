package one;

public class Text {
    public static void main(String[] args) {
        double answer = 1;
        for (int i = 2; i <= 10; i++)
            answer += (double) 1 / App.factorial(i) * App.isOdd(i);
        System.out.println(answer);
    }
}
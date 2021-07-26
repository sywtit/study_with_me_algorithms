package Basics.baekjoon;

import java.util.*;

public class baekjoon_1065 {

    public static void main(String[] args) {

        int N = 0;
        int count = 0;

        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        for (int i = 1; i <= N; i++) {
            if (check(i))
                count++;
        }

        System.out.println(count);

    }

    static boolean check(int n) {

        if (n < 100)
            return true;

        int first_value = n % 10;
        n /= 10;
        int next_value = n % 10;
        int abs = first_value - next_value;

        while (n >= 10) {
            first_value = next_value;
            n /= 10;
            next_value = n % 10;

            int new_abs = first_value - next_value;
            if (abs != new_abs) {
                return false;
            }
        }

        return true;
    }
}

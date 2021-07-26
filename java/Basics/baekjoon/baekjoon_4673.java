package Basics.baekjoon;

import java.util.*;

public class baekjoon_4673 {

    static boolean[] count = new boolean[10001];

    public static void main(String[] args) {

        for (int i = 1; i <= 10000; i++) {
            if (!count[i]) {
                System.out.println(i);
                make_d(i);
            }
        }
    }

    // 재귀 함수 선언
    static void make_d(int n) {

        // 값 구하기
        int next_value = n;
        while (n >= 1) {
            next_value += n % 10;
            n /= 10;
        }

        if (next_value > 10000)
            return;
        if (count[next_value])
            return;

        count[next_value] = true;
        make_d(next_value);
    }

}

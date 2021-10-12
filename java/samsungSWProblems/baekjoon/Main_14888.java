package samsungSWProblems.baekjoon;

import java.util.*;
import java.io.*;

public class Main_14888 {

    static int N;
    static int[] numbers;
    static int[] opCounts;
    static int[] visits;
    static int maxValue = -1000000000;
    static int minValue = 1000000000;

    static void permutation(int now, int depth) {

        // 기저사례
        if (depth == N) {
            maxValue = Math.max(maxValue, now);
            minValue = Math.min(minValue, now);
            return;
        }

        for (int i = 0; i < 4; i++) {

            // 백트래킹
            if (visits[i] == 0)
                continue;

            visits[i]--;

            if (i == 0) {
                permutation(now + numbers[depth], depth + 1);
            } else if (i == 1) {
                permutation(now - numbers[depth], depth + 1);
            } else if (i == 2) {
                permutation(now * numbers[depth], depth + 1);
            } else if (i == 3) {
                // 예외 조건 체크
                if (numbers[depth] == 0)
                    break;

                int tmp = Math.abs(now) / numbers[depth];
                if (now < 0)
                    tmp = -tmp;

                permutation(tmp, depth + 1);
            }

            visits[i]++;
        }

    }

    public static void main(String[] args) throws Exception {

        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(in.readLine());

        StringTokenizer st = new StringTokenizer(in.readLine());
        numbers = new int[N];
        for (int i = 0; i < N; i++) {
            numbers[i] = Integer.parseInt(st.nextToken());
        }

        opCounts = new int[4];
        visits = new int[4];
        st = new StringTokenizer(in.readLine());
        for (int i = 0; i < 4; i++) {
            opCounts[i] = Integer.parseInt(st.nextToken());
            visits[i] = opCounts[i];
        }

        permutation(numbers[0], 1);

        System.out.println(maxValue);
        System.out.println(minValue);

        in.close();
    }
}

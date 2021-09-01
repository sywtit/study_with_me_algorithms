package Combination.baekjoon;

import java.io.*;
import java.util.*;

public class baekjoon_1256 {

    static int N, M, K;
    static int[][] dp;
    static int skip;

    static void solution(int x, int y, String answer) {

        // 기저 사례
        // 해당 경우는 a를 빼고 z를 선택해야하는 경우
        if (skip < 0)
            return;
        if (x == 0 && y == 0) {
            if (skip == 0)
                System.out.println(answer);
            skip--;
            return;
        }
        if (dp[x + y][x] <= skip) {
            skip -= dp[x + y][x];
            return;
        }
        // a부터 순차적으로 체크
        if (x > 0) {
            solution(x - 1, y, answer + "a");
        }
        if (y > 0) {
            solution(x, y - 1, answer + "z");
        }
    }

    static void makeDp() {
        // 0개를 뽑을 때나 mCm의 경우 값이 0인 것을 이용
        for (int i = 0; i <= N + M; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0 || i == j) {
                    dp[i][j] = 1;
                    continue;
                } else {
                    dp[i][j] = Math.min(1000000000, dp[i - 1][j - 1] + dp[i - 1][j]);
                    // mCn = m-1Cn + m-1Cn-1
                }
            }
        }
        return;

    }

    public static void main(String[] args) throws Exception {

        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        String input = in.readLine();
        StringTokenizer st = new StringTokenizer(input, " ");

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        // 모든 순차 조합을 구하는 방법
        // prev_permutation : k가 10억이 넘음 //약 10초

        // 따라서 dp 방법을 이용한다.
        // 조합이 많이 나올 경우 : 그림을 먼저 그리고
        // mCn = m-1Cn + m-1Cn-1 특징을 이용한다!
        dp = new int[N + M + 1][N + M + 1];

        dp[0][0] = 1;
        makeDp();

        skip = K - 1;

        // 규완이의 사전에 수록되어 있는 문자열의 개수가 K보다 작음
        if (dp[N + M][N] <= skip) {
            System.out.println("-1");
        } else { // 존재할 경우
            solution(N, M, "");
        }
    }
}

// 참고 사이트
// https://chosh95.tistory.com/177
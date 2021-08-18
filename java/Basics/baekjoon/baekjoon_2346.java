package Basics.baekjoon;

import java.io.*;
import java.util.*;

public class baekjoon_2346 {

    public static void main(String[] args) throws Exception {

        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(in.readLine());

        String input = in.readLine();
        StringTokenizer st = new StringTokenizer(input, " ");
        // 숫자가 1번부터 시작 //터트린 풍선을 검사할 변수 선언
        boolean[] visited = new boolean[N + 1];
        int[] arr = new int[N + 1];

        int index = 1;
        while (st.hasMoreTokens()) {
            arr[index++] = Integer.parseInt(st.nextToken());
        }

        StringBuilder sb = new StringBuilder();
        visited[0] = true;

        // 1번 풍선 먼저 터트림
        int pos = 1;
        int answerCnt = 0;

        while (answerCnt < N) {

            visited[pos] = true; // 풍선 터짐
            sb.append(pos).append(" ");
            int next = arr[pos]; // 다음으로 넘어갈 step 값
            answerCnt++; // 풍선 터지는 개수와 전체 기존 풍선 비교 필요

            // 풍선 1개 남음 arr[pos]검사 필요 없음
            if (answerCnt == N)
                break;

            if (next > 0) {
                while (next > 0) {
                    pos++;
                    if (pos == N + 1) // 범위 밖
                        pos = 1;
                    if (!visited[pos]) {
                        next--;
                    }
                }

            } else {
                while (next < 0) {
                    pos--;
                    if (pos == 0) // 범위 밖
                        pos = N;
                    if (!visited[pos]) {
                        next++;
                    }
                }

            }
        }

        System.out.println(sb.toString());

    }

}

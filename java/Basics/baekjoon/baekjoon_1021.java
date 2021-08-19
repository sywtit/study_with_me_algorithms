package Basics.baekjoon;

import java.util.*;
import java.io.*;

public class baekjoon_1021 {

    public static void main(String[] args) throws Exception {

        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        String input = in.readLine();
        StringTokenizer st = new StringTokenizer(input, " ");

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int[] arr = new int[N + 1];
        boolean[] visited = new boolean[N + 1];
        for (int i = 1; i < N + 1; i++) {
            arr[i] = i;
        }

        input = in.readLine();
        st = new StringTokenizer(input, " ");
        int start_pos = 1;
        int answer = 0;
        for (int i = 0; i < M; i++) {
            int index = Integer.parseInt(st.nextToken());

            while (true) {

                if (start_pos == N + 1)
                    start_pos = 1;

                if (arr[start_pos] == index) {
                    visited[start_pos] = true;
                    break;
                }

                if (!visited[start_pos]) {
                    start_pos++;
                    answer++;
                }
            }
        }

        System.out.println(answer);
        in.close();
    }
}

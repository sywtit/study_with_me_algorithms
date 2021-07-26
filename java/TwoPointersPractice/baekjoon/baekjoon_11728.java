package TwoPointersPractice.baekjoon;

import java.util.*;

public class baekjoon_11728 {
    public static void main(String[] args) {
        int N, M;
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        M = sc.nextInt();

        // 개행 문자
        sc.nextLine();

        Integer[] A = new Integer[N];
        Integer[] B = new Integer[M];

        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }

        // 개행 문자
        sc.nextLine();
        for (int i = 0; i < M; i++) {
            B[i] = sc.nextInt();
        }

        // 개행 문자
        sc.nextLine();

        int A_point = 0, B_point = 0;

        while (A_point != N && B_point != M) {

            if (A[A_point] < B[B_point]) {
                System.out.print(A[A_point] + " ");
                A_point++;
            } else if (A[A_point] > B[B_point]) {
                System.out.print(B[B_point] + " ");
                B_point++;
            } else {
                System.out.print(A[A_point] + " " + B[B_point] + " ");
                A_point++;
                B_point++;
            }

        }

        if (A_point == N && B_point == M) {
            // do nothing
        } else {
            if (A_point == N) {
                while (B_point != M) {
                    System.out.print(B[B_point] + " ");
                    B_point++;
                }
            } else {
                while (A_point != N) {
                    System.out.print(A[A_point] + " ");
                    A_point++;
                }
            }
        }

    }
}

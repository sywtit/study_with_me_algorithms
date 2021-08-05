package Basics.baekjoon;

import java.io.*;
import java.util.*;

public class baekjoon_2869 {

    public static void main(String[] args) throws IOException {
        int A, B, V;

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();

        String[] words = input.split(" ");
        A = Integer.parseInt(words[0]);
        B = Integer.parseInt(words[1]);
        V = Integer.parseInt(words[2]);

        if (V == A) {
            System.out.println(1);
            return;
        }

        int answer = 1;
        V -= (2 * A - B);

        answer += V / (A - B);
        System.out.println(answer + 1);

    }
}

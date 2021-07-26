package StringPractice.baekjoon;

import java.util.*;

public class baekjoon_11720 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int N;
        N = Integer.parseInt(sc.nextLine());
        String input;

        int answer = 0;
        input = sc.nextLine();

        //split 도 하나의 방법일 수 도 있지만
        /*
            string.charAt(i) - '0';
            or
            Integer.parseInt(inputs.substring(i,i+1));
        */
        String[] input_integer = input.split("");

        for (int i = 0; i < N; i++) {
            answer += Integer.parseInt(input_integer[i]);
        }


        System.out.println(answer);
        sc.close();

    }
}
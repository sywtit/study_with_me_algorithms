package StringPractice.baekjoon;

import java.util.*;

public class baekjoon_11365 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        String input, answer;

        while (true) {
            input = sc.nextLine();
            // 기저 사례
            if (input.compareTo("END") == 0) {
                break;
            }

            answer = "";
            for (int i = input.length() - 1; i >= 0; i--) {
                answer = answer + input.charAt(i);
            }

            System.out.println(answer);

        }
        sc.close();

    }
}

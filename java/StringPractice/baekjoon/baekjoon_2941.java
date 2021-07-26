package StringPractice.baekjoon;

import java.util.*;

public class baekjoon_2941 {

    static String[] key = new String[] { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

    public static void main(String[] args) {

        String input = "";
        Scanner sc = new Scanner(System.in);
        input = sc.nextLine();
        int answer = 0;

        for (int i = 0; i < key.length; i++) {
            while (input.contains(key[i])) {
                answer++;
                input = input.replaceFirst(key[i], "0");
            }
        }

        for(int i = 0; i<input.length(); i++){
            if(input.charAt(i)!= '0') answer ++;
        }

        System.out.println(answer);
    }
}

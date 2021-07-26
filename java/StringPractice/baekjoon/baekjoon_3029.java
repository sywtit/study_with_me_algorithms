package StringPractice.baekjoon;

import java.util.*;

public class baekjoon_3029 {
    public static void main(String[] args) {

        // 입력 받기
        Scanner sc = new Scanner(System.in);
        String time_now = sc.nextLine();
        String time_to_throw = sc.nextLine();

        String[] time_now_array = time_now.split(":");
        String[] time_to_throw_array = time_to_throw.split(":");

        int time_now_int = 0, time_to_throw_int = 0;
        time_now_int = 3600 * Integer.parseInt(time_now_array[0]) + 60 * Integer.parseInt(time_now_array[1])
                + Integer.parseInt(time_now_array[2]);

        time_to_throw_int = 3600 * Integer.parseInt(time_to_throw_array[0])
                + 60 * Integer.parseInt(time_to_throw_array[1]) + Integer.parseInt(time_to_throw_array[2]);

        int answer = 0;
        if (time_now_int >= time_to_throw_int) {
            time_to_throw_int += 3600 * 24;
        }
        answer = time_to_throw_int - time_now_int;

        String answer_value = "";

        answer_value += String.format("%02d", answer / 3600);
        answer_value += ":";
        answer %= 3600;
        answer_value += String.format("%02d", answer / 60);
        answer_value += ":";
        answer %= 60;
        answer_value += String.format("%02d", answer);

        System.out.println(answer_value);
        sc.close();

    }
}
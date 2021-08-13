package Stack.baekjoon;

import java.util.*;
import java.io.*;

public class baekjoon_1918 {
    public static void main(String[] args) throws Exception {

        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String input = in.readLine();

        Deque<Character> s = new ArrayDeque<>();
        StringBuilder sb = new StringBuilder();

        s.push('(');
        boolean check = false;
        Deque<Character> answer = new ArrayDeque<>();
        for (int i = 0; i < input.length(); i++) {
            char c = input.charAt(i);

            if (c != ')') {
                // peek해서 *가 나오면 처리하기
                if (c != '(' && !s.isEmpty() && s.peek() == '*') {
                    add_to_value(s, answer);
                }
                s.push(c);
                if (check == true) {
                    while (!answer.isEmpty()) {
                        sb.append(answer.pollFirst());
                    }
                    check = false;
                }
            } else {
                // 현재 stack에 push된것들 중에서
                // ( 가 나올때까지 answer에 push
                check = true;
                add_to_value(s, answer);
                s.pop();
            }
        }

        add_to_value(s, answer);

        while (!answer.isEmpty()) {
            sb.append(answer.pollFirst());
        }

        System.out.println(sb.toString());
        in.close();
    }

    static void add_to_value(Deque<Character> s, Deque<Character> answer) {
        while (!s.isEmpty() && s.peek() != '(') {
            char c_now = s.pop();
            if (c_now >= 65 && c_now <= 90)
                answer.addFirst(c_now);
            else
                answer.addLast(c_now);
        }
    }
}

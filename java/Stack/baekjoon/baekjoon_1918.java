package Stack.baekjoon;

import java.util.*;
import java.io.*;

public class baekjoon_1918 {

    static int precedence(char ch) {
        if (ch == '(')
            return 0;
        else if (ch == '+' || ch == '-')
            return 1;
        else
            return 2;
    }

    public static void main(String[] args) throws Exception {

        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String input = in.readLine();

        Deque<Character> s = new ArrayDeque<>();
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < input.length(); i++) {
            char c = input.charAt(i);

            if (c >= 'A' && c <= 'Z')
                sb.append(c);
            else {
                // 괄호가 시작되면 무조건 push
                if (c == '(') {
                    s.push(c);
                } else if (c == ')') {
                    while (s.peek() != '(')
                        sb.append(s.pop());
                    s.pop();
                } else {
                    while (!s.isEmpty() && precedence(c) <= precedence(s.peek())) {
                        sb.append(s.pop());
                    }
                    s.push(c);
                }
            }
        }

        while (!s.isEmpty()) {
            sb.append(s.pop());
        }

        System.out.println(sb.toString());
        in.close();
    }
}

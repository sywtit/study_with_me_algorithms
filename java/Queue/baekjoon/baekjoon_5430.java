package Queue.baekjoon;

import java.util.*;
import java.io.*;

public class baekjoon_5430 {

    static int T, n;
    static Deque<Integer> queue = new ArrayDeque<>();
    static String command, arr;
    static boolean direction;

    public static void main(String[] args) throws Exception {

        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        T = Integer.parseInt(in.readLine());

        for (int i = 0; i < T; i++) {

            command = in.readLine();
            n = Integer.parseInt(in.readLine());
            arr = in.readLine();

            arr = arr.replaceAll("[\\[\\]]", "");
            StringTokenizer st = new StringTokenizer(arr, ",");
            for (int j = 0; j < n; j++) {
                queue.add(Integer.parseInt(st.nextToken()));
            }
            direction = true;

            // command 실행
            boolean check = true;
            for (int j = 0; j < command.length(); j++) {
                char c = command.charAt(j);
                if (c == 'R') {
                    direction = (direction == true) ? false : true;
                } else {
                    if (!direction) {
                        if (queue.pollLast() == null) {
                            check = false;
                            break;
                        }
                    } else {
                        if (queue.pollFirst() == null) {
                            check = false;
                            break;
                        }
                    }
                }
            }

            // command실행 후 print
            if (check == false)
                System.out.println("error");
            else {
                sb = new StringBuilder();
                sb.append("[");
                if (!direction) {
                    while (!queue.isEmpty()) {
                        int value = queue.pollLast();
                        sb.append(value).append(",");
                    }
                } else {
                    while (!queue.isEmpty()) {
                        int value = queue.pollFirst();
                        sb.append(value).append(",");
                    }
                }
                if (sb.length() > 1)
                    sb.deleteCharAt(sb.length() - 1);
                sb.append("]");
                System.out.println(sb.toString());
            }
        }

    }
}

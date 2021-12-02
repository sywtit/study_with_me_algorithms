import java.io.*;
import java.util.*;

public class baekjoon_14916 {

    public static void main(String[] args) throws Exception {

        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(in.readLine());
        int answer = 0;

        answer += n / 5;
        n %= 5;

        answer += n / 2;
        if (n % 2 == 0)
            System.out.println(answer);
        else
            System.out.println(-1);

    }
}

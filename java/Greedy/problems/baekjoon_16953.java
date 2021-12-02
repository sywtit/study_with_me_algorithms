import java.util.*;
import java.io.*;

public class baekjoon_16953 {

    public static void main(String[] args) throws Exception {

        // BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);

        int A = sc.nextInt();
        int B = sc.nextInt();

        int count = 0;
        boolean flag = true;

        while (true) {

            if (B == A)
                break;
            else if (B < A) {
                flag = false;
                break;
            } else {

                int right_pos = B % 10;
                if (right_pos == 1) {
                    B = B / 10;
                    count++;
                } else {
                    if (right_pos % 2 == 0) {
                        B = B / 2;
                        count++;
                    } else {
                        flag = false;
                        break;
                    }
                }
            }
        }

        if (flag)
            System.out.println(count + 1);
        else
            System.out.println("-1");

    }
}

package Tree.baekjoon;

import java.util.*;
import java.io.*;

public class baekjoon_3584 {

    static ArrayDeque<Integer> qA = new ArrayDeque<>();
    static ArrayDeque<Integer> qB = new ArrayDeque<>();
    static int[] parent;

    public static void main(String[] args) throws Exception {

        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(in.readLine());

        for (int i = 0; i < T; i++) {
            int N = Integer.parseInt(in.readLine());
            parent = new int[N + 1];
            for (int j = 1; j <= N; j++) {
                parent[j] = j;
            }

            int parent_node, child_node;
            String nodes;
            for (int j = 0; j < N - 1; j++) {
                nodes = in.readLine();
                StringTokenizer st = new StringTokenizer(nodes, " ");
                parent_node = Integer.parseInt(st.nextToken());
                child_node = Integer.parseInt(st.nextToken());

                parent[child_node] = parent_node;
            }

            qA.clear();
            qB.clear();
            nodes = in.readLine();
            StringTokenizer st = new StringTokenizer(nodes, " ");
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());

            findAParent(A);
            findBParent(B);

            // level이 높을 수록 좀 더 하위 노드로 존재한다.
            // 더 깊은 트리노드가 level이 같아 질 때까지
            // queue를 poll 하고, 이후부터 비교
            while (qA.size() != qB.size()) {
                if (qA.size() > qB.size()) {
                    qA.poll();
                } else
                    qB.poll();
            }

            while (!qA.isEmpty()) {
                int answer = qA.poll();
                if (answer == qB.poll()) {
                    System.out.println(answer);
                    break;
                }
            }
        }
    }

    static void findAParent(int x) {
        qA.offer(x);
        if (x == parent[x])
            return;
        findAParent(parent[x]);
    }

    static void findBParent(int x) {
        qB.offer(x);
        if (x == parent[x])
            return;
        findBParent(parent[x]);
    }
}

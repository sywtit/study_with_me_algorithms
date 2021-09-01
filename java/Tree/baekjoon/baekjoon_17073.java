package Tree.baekjoon;

import java.util.*;
import java.io.*;

public class baekjoon_17073 {

    static List<Integer>[] tree;
    static double answer;
    static int answer_count;
    static boolean[] visited;

    public static void main(String[] args) throws Exception {
        int N, W;
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());

        N = Integer.parseInt(st.nextToken()); // 트리의 노드 수
        W = Integer.parseInt(st.nextToken()); // 1번 노드에 고인 물의 양

        // 방문한 트리 노드
        visited = new boolean[N + 1];
        tree = new ArrayList[N + 1];
        for (int i = 1; i <= N; i++) {
            tree[i] = new ArrayList<Integer>();
        }

        for (int i = 0; i < N - 1; i++) {
            st = new StringTokenizer(in.readLine());
            int U = Integer.parseInt(st.nextToken());
            int V = Integer.parseInt(st.nextToken());

            // U와 V중 어떤게 부모 노드인지 모름
            // 따라서 둘다 넣어준다.
            tree[U].add(V);
            tree[V].add(U);
        }

        // 더 이상 물이 움직이지 않을 경우 : 정점의 최대 크기가 정해져 있지 않기 때문에
        // 자식 노드들에만 물이 존재하는 경우 -> 물이 움직이지 않을 경우
        bfs(1);

        // 결과값
        System.out.println((double) W / (double) answer_count);

    }

    static void bfs(int index) {

        Deque<Integer> q = new ArrayDeque<>();
        visited[index] = true;
        q.offer(index);

        while (!q.isEmpty()) {
            int cur_index = q.poll();

            boolean checkChild = false;
            for (int i = 0; i < tree[cur_index].size(); i++) {
                if (!visited[tree[cur_index].get(i)]) {
                    visited[tree[cur_index].get(i)] = true;
                    q.offer(tree[cur_index].get(i));
                    checkChild = true;
                }
            }

            // 자식 노드
            if (!checkChild) {
                answer_count++;
            }

        }

    }
}
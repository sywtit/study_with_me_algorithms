package samsungSWProblems.baekjoon;

import java.util.*;
import java.io.*;

public class Main_15685 {

    static int[] dx = { 0, 0, -1, -1 };
    static int[] dy = { 0, -1, 0, -1 };
    static int[] mx = { 1, 0, -1, 0 };
    static int[] my = { 0, -1, 0, 1 };
    static int[][] value = new int[101][101]; // 정사각형의 방문한 각 끝점들의 합
    static boolean[][] visited = new boolean[101][101];

    public static void main(String[] args) throws Exception {

        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(in.readLine());
        Deque<Integer> s = new ArrayDeque<>();
        Deque<Integer> sbefore = new ArrayDeque<>();
        Deque<Integer> q = new ArrayDeque<>();
        // 시뮬레이션 시작
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());
            int g = Integer.parseInt(st.nextToken());

            // 0 세데
            checkBox(y, x);
            checkBox(y + my[d], x + mx[d]);

            if (g == 0)
                continue;

            int nowX = x + mx[d];
            int nowY = y + my[d];
            s.clear();
            q.clear();
            sbefore.clear();
            s.push(d);

            for (int next = 1; next <= g; next++) {

                while (!s.isEmpty()) {
                    int dir = s.pop();
                    sbefore.push(dir);
                    // 방향을 반대 방향으로 바꾸기
                    int rev_dir = dir - 2;
                    if (rev_dir < 0)
                        rev_dir += 4;

                    // 방향을 시계방향으로 90도 회전
                    rev_dir -= 1;
                    if (rev_dir == -1)
                        rev_dir = 3;

                    // 끝점에서 이동
                    int nextX = nowX + mx[rev_dir];
                    int nextY = nowY + my[rev_dir];

                    // 격자 밖으로 나간것들 제외
                    if (nextX < 0 || nextY < 0 || nextX >= 101 || nextY >= 101)
                        break;

                    // q에 방향키 저장
                    q.offer(rev_dir);

                    checkBox(nextY, nextX);

                    nowX = nextX;
                    nowY = nextY;
                }

                s.clear();
                while (!sbefore.isEmpty()) {
                    s.push(sbefore.pop());
                }
                while (!q.isEmpty()) {
                    s.push(q.poll());
                }
            }

        }

        int answer = 0;
        for (int i = 0; i < 101; i++) {
            for (int j = 0; j < 101; j++) {
                if (value[i][j] == 4)
                    answer++;
            }
        }

        System.out.println(answer);

        in.close();
    }

    static void checkBox(int y, int x) {
        if (!visited[y][x]) {
            for (int j = 0; j < 4; j++) {
                int newX = x + dx[j];
                int newY = y + dy[j];

                if (newX < 0 || newY < 0 || newX >= 101 || newY >= 101)
                    continue;

                value[newY][newX]++;
            }
            visited[y][x] = true;
        }
    }
}

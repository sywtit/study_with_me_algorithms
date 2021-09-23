package samsungSWProblems.baekjoon;

import java.util.*;
import java.io.*;

public class Baekjoon_13460 {

    static class Pos {
        int x;
        int y;
        boolean gone;

        Pos(int _x, int _y, boolean _gone) {
            this.x = _x;
            this.y = _y;
            this.gone = _gone;
        }
    }

    public static void main(String[] args) throws Exception {

        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine(), " ");

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        char[][] board = new char[N][M];
        // bfs
        Deque<Pos[]> q = new ArrayDeque<>();
        Deque<Integer> qResult = new ArrayDeque<>();

        Pos[] elements = new Pos[2];

        for (int i = 0; i < N; i++) {

            String input = in.readLine();
            board[i] = input.toCharArray();

            for (int j = 0; j < M; j++) {

                if (board[i][j] == 'B') {
                    elements[0] = new Pos(j, i, false);
                } else if (board[i][j] == 'R') {
                    elements[1] = new Pos(j, i, false);
                }

            }
        }
        q.offer(elements); // 첫번째 B, 두번째 R
        qResult.offer(0);
        // bfs // blue + red 같이 취급
        Boolean[][][] visited = new Boolean[N][M][2];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                for (int k = 0; k < 2; k++) {
                    visited[i][j][k] = false;
                }
            }
        }

        int answer = -1;

        while (!q.isEmpty()) {
            Pos[] element = q.poll();
            Pos blue = element[0];
            Pos red = element[1];
            int result = qResult.poll();
            answer = result;
            // 기저 사례
            // 파란 구슬이 구멍으로 빠질 경우
            // continue
            if (blue.gone)
                continue;

            // 빨간 구슬이 구멍으로 빠질 경우
            if (red.gone)
                break;

            // answer 값이 10 이상
            if (answer >= 10) {
                answer = -1;
                break;
            }

            for (int i = 0; i < 4; i++) {
                // 동 서 남 북으로 이동
                int newRX = red.x;
                int newRY = red.y;

                int newBX = blue.x;
                int newBY = blue.y;

                boolean checkR = false;
                boolean checkB = false;
                boolean checkHoleR = false;
                boolean checkHoleB = false;

                boolean hideR = false; // R 구슬이 가는 방향에 다른 구슬이 있을 경우
                boolean hideB = false; // B 구슬이 가는 방향에 다른 구슬이 있을 경우
                if (i == 0) { // 동
                    // 빨간색 파란색 모두 끝까지 이동
                    // 빨간색
                    while (true) {
                        newRX++;

                        if (board[red.y][newRX] == 'O') {
                            checkHoleR = true;
                            checkR = true;
                            break;
                        }
                        // board의 범위에 넘어 갈일 없음
                        if (board[red.y][newRX] != '.') {
                            if (board[red.y][newRX] == 'B') {
                                hideR = true;
                                continue;
                            }
                            // 방문한 적 있는지 검사
                            if (visited[red.y][newRX][1]) {
                                break;
                            }

                            checkR = true;
                            break;
                        }
                    }

                    // 파란색
                    while (true) {
                        newBX++;

                        if (board[blue.y][newBX] == 'O') {
                            checkHoleB = true;
                            checkB = true;
                            break;
                        }

                        if (board[blue.y][newBX] != '.') {

                            if (board[red.y][newBX] == 'R') {
                                hideB = true;
                                continue;
                            }

                            if (visited[blue.y][newBX][0]) {
                                break;
                            }

                            checkB = true;
                            break;
                        }
                    }
                    // check 가 false일 경우 방문한 경우이기 때문에 queue에 들어가지 않는다.
                    if (checkR && checkB) {

                        Pos[] elementBR = new Pos[2];
                        if (!checkHoleB && hideB) {
                            newBX--;
                        }
                        if (!checkHoleR && hideR) {
                            newRX--;
                        }
                        elementBR[0] = new Pos(newBX - 1, blue.y, checkHoleB);
                        elementBR[1] = new Pos(newRX - 1, red.y, checkHoleR);

                        q.offer(elementBR);
                        qResult.offer(result + 1);
                    }
                } else if (i == 1) { // 서
                    // 빨간색 파란색 모두 끝까지 이동
                    // 빨간색

                    while (true) {
                        newRX--;

                        if (board[red.y][newRX] == 'O') {
                            checkHoleR = true;
                            checkR = true;
                            break;
                        }
                        // board의 범위에 넘어 갈일 없음
                        if (board[red.y][newRX] != '.') {
                            if (board[red.y][newRX] == 'B') {
                                hideR = true;
                                continue;
                            }
                            // 방문한 적 있는지 검사
                            if (visited[red.y][newRX][1]) {
                                break;
                            }

                            checkR = true;
                            break;
                        }
                    }

                    // 파란색
                    while (true) {
                        newBX--;

                        if (board[blue.y][newBX] == 'O') {
                            checkHoleB = true;
                            checkB = true;
                            break;
                        }

                        if (board[blue.y][newBX] != '.') {

                            if (board[blue.y][newBX] == 'R') {
                                hideB = true;
                                continue;
                            }

                            if (visited[blue.y][newBX][0]) {
                                break;
                            }

                            checkB = true;
                            break;
                        }
                    }
                    // check 가 false일 경우 방문한 경우이기 때문에 queue에 들어가지 않는다.
                    if (checkR && checkB) {

                        Pos[] elementBR = new Pos[2];
                        if (!checkHoleB && hideB) {
                            newBX++;
                        }
                        if (!checkHoleR && hideR) {
                            newRX++;
                        }
                        elementBR[0] = new Pos(newBX + 1, blue.y, checkHoleB);
                        elementBR[1] = new Pos(newRX + 1, red.y, checkHoleR);

                        q.offer(elementBR);
                        qResult.offer(result + 1);

                    }

                } else if (i == 2) { // 남
                    // 빨간색 파란색 모두 끝까지 이동
                    // 빨간색

                    while (true) {
                        newRY++;

                        if (board[newRY][red.x] == 'O') {
                            checkHoleR = true;
                            checkR = true;
                            break;
                        }
                        // board의 범위에 넘어 갈일 없음
                        if (board[newRY][red.x] != '.') {
                            if (board[newRY][red.x] == 'B') {
                                hideR = true;
                                continue;
                            }
                            // 방문한 적 있는지 검사
                            if (visited[newRY][red.x][1]) {
                                break;
                            }

                            checkR = true;
                            break;
                        }
                    }

                    // 파란색
                    while (true) {
                        newBY++;

                        if (board[newBY][blue.x] == 'O') {
                            checkHoleB = true;
                            checkB = true;
                            break;
                        }

                        if (board[newBY][blue.x] != '.') {

                            if (board[newBY][blue.x] == 'R') {
                                hideB = true;
                                continue;
                            }

                            if (visited[newBY][blue.x][0]) {
                                break;
                            }

                            checkB = true;
                            break;
                        }
                    }
                    // check 가 false일 경우 방문한 경우이기 때문에 queue에 들어가지 않는다.
                    if (checkR && checkB) {

                        Pos[] elementBR = new Pos[2];
                        if (!checkHoleB && hideB) {
                            newBY--;
                        }
                        if (!checkHoleR && hideR) {
                            newRY--;
                        }
                        elementBR[0] = new Pos(blue.x, newBY - 1, checkHoleB);
                        elementBR[1] = new Pos(red.x, newRY - 1, checkHoleR);

                        q.offer(elementBR);
                        qResult.offer(result + 1);

                    }
                } else {
                    // 빨간색 파란색 모두 끝까지 이동
                    // 빨간색
                    while (true) {
                        newRY--;

                        if (board[newRY][red.x] == 'O') {
                            checkHoleR = true;
                            checkR = true;
                            break;
                        }
                        // board의 범위에 넘어 갈일 없음
                        if (board[newRY][red.x] != '.') {
                            if (board[newRY][red.x] == 'B') {
                                hideR = true;
                                continue;
                            }
                            // 방문한 적 있는지 검사
                            if (visited[newRY][red.x][1]) {
                                break;
                            }

                            checkR = true;
                            break;
                        }
                    }

                    // 파란색
                    while (true) {
                        newBY--;

                        if (board[newBY][blue.x] == 'O') {
                            checkHoleB = true;
                            checkB = true;
                            break;
                        }

                        if (board[newBY][blue.x] != '.') {
                            if (board[newBY][blue.x] == 'R') {
                                hideB = true;
                                continue;
                            }
                            if (visited[newBY][blue.x][0]) {
                                break;
                            }

                            checkB = true;
                            break;
                        }
                    }
                    // check 가 false일 경우 방문한 경우이기 때문에 queue에 들어가지 않는다.
                    if (checkR && checkB) {

                        Pos[] elementBR = new Pos[2];
                        if (!checkHoleB && hideB) {
                            newBY++;
                        }
                        if (!checkHoleR && hideR) {
                            newRY++;
                        }
                        elementBR[0] = new Pos(blue.x, newBY + 1, checkHoleB);
                        elementBR[1] = new Pos(red.x, newRY + 1, checkHoleR);

                        q.offer(elementBR);
                        qResult.offer(result + 1);

                    }
                }
            }
        }

        System.out.println(answer);
        in.close();

    }
}

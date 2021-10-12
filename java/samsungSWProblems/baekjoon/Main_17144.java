package samsungSWProblems.baekjoon;

import java.io.*;
import java.util.*;

public class Main_17144 {

	static class Info {
		int x;
		int y;
		int dirt;

		Info(int _x, int _y, int _dirt) {
			this.x = _x;
			this.y = _y;
			this.dirt = _dirt;
		}
	}

	static int[] dx = { -1, 1, 0, 0 };
	static int[] dy = { 0, 0, -1, 1 };

	public static void main(String[] args) throws Exception {

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(in.readLine());

		int R = Integer.parseInt(st.nextToken());
		int C = Integer.parseInt(st.nextToken());
		int T = Integer.parseInt(st.nextToken());

		Deque<Info> q = new ArrayDeque<>();
		int upY = 0, downY = 0;
		boolean check = false;
		int[][] map = new int[R][C];
		int[][] tmpMap = new int[R][C];

		for (int i = 0; i < R; i++) {
			st = new StringTokenizer(in.readLine());
			for (int j = 0; j < C; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				if (map[i][j] == -1) {
					if (!check) {
						upY = i;
						check = true;
					} else {
						downY = i;
					}
				} else if (map[i][j] != 0) {
					q.offer(new Info(j, i, map[i][j]));
				}
			}
		}

		int dayCount = 0;
		tmpMap[upY][0] = -1;
		tmpMap[downY][0] = -1;
		while (!q.isEmpty()) {
			Info now = q.poll();

			int value = map[now.y][now.x];
			value = value / 5;
			int divCount = 0;

			for (int i = 0; i < 4; i++) {
				int newY = now.y + dy[i];
				int newX = now.x + dx[i];

				if (newX < 0 || newY < 0 || newX >= C || newY >= R)
					continue;

				if (map[newY][newX] == -1)
					continue;

				divCount++;
				tmpMap[newY][newX] += value;

			}

			tmpMap[now.y][now.x] += map[now.y][now.x] - value * divCount;

			if (q.isEmpty()) {
				// 확산 한꺼번에 연산
				for (int i = 0; i < R; i++) {
					for (int j = 0; j < C; j++) {
						map[i][j] = tmpMap[i][j];
					}
				}

				// 공기청정기 실행
				if (upY != 0) {
					// upY랑 같은 줄에 있는 미세먼지들 오른쪽으로 이동
					int moveX = 1;
					int tmpV = map[upY][moveX];
					int tmpVV = 0;
					while (moveX < C - 1) {
						tmpVV = map[upY][moveX + 1];
						map[upY][moveX + 1] = tmpV;
						tmpV = tmpVV;
						moveX++;
					}
					map[upY][1] = 0;

					// 제일 오른쪽 열들 위로 이동
					int moveY = upY;
					while (moveY >= 1) {
						tmpVV = map[moveY - 1][C - 1];
						map[moveY - 1][C - 1] = tmpV;
						tmpV = tmpVV;
						moveY--;
					}

					// 제일 위쪽 row 왼쪽으로 이동
					moveX = C - 1;
					while (moveX > 0) {
						tmpVV = map[0][moveX - 1];
						map[0][moveX - 1] = tmpV;
						tmpV = tmpVV;
						moveX--;
					}

					// 제일 왼쪽 열 아래로 이동(마지막은 없어짐)
					moveY = 0;
					while (moveY < upY - 1) {
						tmpVV = map[moveY + 1][0];
						map[moveY + 1][0] = tmpV;
						tmpV = tmpVV;

						moveY++;
					}

					// tmpV에 담긴 미세먼지 사라짐

				}

				if (downY != R - 1) {

					// downY랑 같은 줄에 있는 미세먼지들 오른쪽으로 이동
					int moveX = 1;
					int tmpV = map[downY][moveX];
					int tmpVV = 0;
					while (moveX < C - 1) {
						tmpVV = map[downY][moveX + 1];
						map[downY][moveX + 1] = tmpV;
						tmpV = tmpVV;
						moveX++;
					}

					map[downY][1] = 0;

					// 제일 오른쪽 열들 아래로 이동
					int moveY = downY;
					while (moveY < R - 1) {
						tmpVV = map[moveY + 1][C - 1];
						map[moveY + 1][C - 1] = tmpV;
						tmpV = tmpVV;

						moveY++;
					}

					// 제일 아래쪽 row 왼쪽으로 이동
					moveX = C - 1;
					while (moveX > 0) {
						tmpVV = map[R - 1][moveX - 1];
						map[R - 1][moveX - 1] = tmpV;
						tmpV = tmpVV;
						moveX--;
					}

					// 제일 왼쪽 열 위로 이동(마지막은 없어짐)
					moveY = R - 1;
					while (moveY > downY + 1) {
						tmpVV = map[moveY - 1][0];
						map[moveY - 1][0] = tmpV;
						tmpV = tmpVV;

						moveY--;
					}

					// tmpV에 담긴 미세먼지 사라짐
				}

				for (int i = 0; i < R; i++) {
					for (int j = 0; j < C; j++) {
						if (map[i][j] != 0 && map[i][j] != -1) {
							q.offer(new Info(j, i, map[i][j]));
						}
					}
				}

				dayCount++;
				if (dayCount == T)
					break;
				tmpMap = new int[R][C];
				tmpMap[upY][0] = -1;
				tmpMap[downY][0] = -1;
			}

		}

		int answer = 0;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (map[i][j] != -1)
					answer += map[i][j];
			}
		}

		System.out.println(answer);
		in.close();

	}

}

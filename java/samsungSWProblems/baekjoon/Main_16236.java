package samsungSWProblems.baekjoon;

import java.util.*;
import java.io.*;

public class Main_16236 {

	static int[] dx = { 0, -1, 0, 1 };
	static int[] dy = { -1, 0, 1, 0 };

	static class Info {
		int x;
		int y;
		int size;
		int dist;

		Info(int _x, int _y, int _size, int _dist) {
			this.x = _x;
			this.y = _y;
			this.size = _size;
			this.dist = _dist;
		}
	}

	public static void main(String[] args) throws Exception {

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(in.readLine());
		int[][] map = new int[N][N];
		Deque<Info> q = new ArrayDeque<>();
		PriorityQueue<Info> tmpQ = new PriorityQueue<>((q1, q2) -> {
			if (q1.dist > q2.dist)
				return 1;
			else if (q1.dist == q2.dist) {
				if (q1.y > q2.y)
					return 1;
				else {
					if (q1.y == q2.y) {
						if (q1.x > q2.x)
							return 1;
						else
							return -1;
					} else {
						return -1;
					}
				}
			} else
				return -1;
		});

		for (int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			for (int j = 0; j < N; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				if (map[i][j] == 9)
					q.offer(new Info(j, i, 2, 0));
			}
		}

		int answer = 0;
		int fish = 0;
		while (true) {

			boolean[][] visited = new boolean[N][N];
			boolean checking = false;
			Info shark = q.peek();
			visited[shark.y][shark.x] = true;
			tmpQ.clear();

			while (!q.isEmpty()) {
				Info now = q.poll();

				for (int i = 0; i < 4; i++) {

					int newX = now.x + dx[i];
					int newY = now.y + dy[i];

					if (newX < 0 || newY < 0 || newX >= N || newY >= N)
						continue;

					if (!visited[newY][newX]) {
						if (map[newY][newX] > shark.size)
							continue;

						if (map[newY][newX] < shark.size && map[newY][newX] != 0) {
							tmpQ.offer(new Info(newX, newY, now.size, now.dist + 1));
							visited[newY][newX] = true;
							checking = true;
						} else {
							q.offer(new Info(newX, newY, now.size, now.dist + 1));
							visited[newY][newX] = true;
						}
					}
				}
			}

			if (!checking)
				break;

			Info now = tmpQ.poll();

			fish++;
			int newSize = now.size;
			if (fish == now.size) {
				newSize++;
				fish = 0;
			}
			q.offer(new Info(now.x, now.y, newSize, 0));

			map[shark.y][shark.x] = 0;
			map[now.y][now.x] = newSize;

			answer += now.dist;

		}

		System.out.println(answer);

	}

}

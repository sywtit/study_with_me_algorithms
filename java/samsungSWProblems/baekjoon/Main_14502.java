package samsungSWProblems.baekjoon;

import java.util.*;
import java.io.*;

public class Main_14502 {

	static int[] wallArr;
	static int answer;
	static int N, M;
	static int wallCount = 0;
	static LinkedList<int[]> zeros;
	static LinkedList<int[]> virus;
	static int[][] map;
	static boolean[][] mapVisited;

	static int[] dx = new int[] { 1, -1, 0, 0 };
	static int[] dy = new int[] { 0, 0, 1, -1 };

	static int bfs(int[] virusPos) {

		int vy = virusPos[0];
		int vx = virusPos[1];

		mapVisited[vy][vx] = true;

		Deque<int[]> q = new ArrayDeque<>();
		q.offer(virusPos);

		int zeroCount = 0;
		while (!q.isEmpty()) {
			int[] nowPos = q.poll();
			int nowPosX = nowPos[1];
			int nowPosY = nowPos[0];

			zeroCount++;

			for (int i = 0; i < 4; i++) {
				int newPosX = nowPosX + dx[i];
				int newPosY = nowPosY + dy[i];

				if (newPosX < 0 || newPosY < 0 || newPosX >= M || newPosY >= N)
					continue;

				if (!mapVisited[newPosY][newPosX]) {
					boolean check = false;
					for (int j = 0; j < 3; j++) {
						int[] catched = zeros.get(wallArr[j]);
						if (catched[0] == newPosY && catched[1] == newPosX) {
							check = true;
							break;
						}
					}
					if (check)
						continue;

					if (map[newPosY][newPosX] == 0) {
						mapVisited[newPosY][newPosX] = true;
						q.offer(new int[] { newPosY, newPosX });
					}
				}
			}
		}

		return zeroCount;
	}

	static void combination(int depth, int index, int size) {
		if (depth == 3) {
			int value = 0;
			mapVisited = new boolean[N][M];
			for (int i = 0; i < virus.size(); i++) {
				value += bfs(virus.get(i));
			}
			answer = Math.max(answer, N * M - value - wallCount);
			return;
		}

		for (int i = index; i < size; i++) {
			wallArr[depth] = i;
			combination(depth + 1, i + 1, size);
		}
	}

	public static void main(String[] args) throws Exception {

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(in.readLine(), " ");

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		zeros = new LinkedList<>();
		virus = new LinkedList<>();
		map = new int[N][M];

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(in.readLine(), " ");
			for (int j = 0; j < M; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				if (map[i][j] == 0)
					zeros.add(new int[] { i, j });
				else if (map[i][j] == 2)
					virus.add(new int[] { i, j });
				else
					wallCount++;
			}
		}

		// zeros들 중에서 벽 선택하기
		int zerosSize = zeros.size();
		// zerosSize중에서 3개 선택하는 방법
		wallCount += 3;
		wallArr = new int[3];
		answer = 0;
		combination(0, 0, zerosSize);

		System.out.println(answer);

		in.close();

	}

}

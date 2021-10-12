package samsungSWProblems.baekjoon;

import java.util.*;
import java.io.*;

public class Main_15686 {

	static ArrayList<int[]> home = new ArrayList<>();
	static ArrayList<int[]> chicken = new ArrayList<>();
	static int[] selected;
	static int answer = 1301; // 13 * (50+50) + 1
	static int M = 0;

	static int distance(int[] h, int[] c) {
		return Math.abs(h[0] - c[0]) + Math.abs(h[1] - c[1]);
	}

	static int getTotalMinDistance(int total) {
		for (int i = 0; i < home.size(); i++) {
			int min_len = 100;
			for (int j = 0; j < M; j++) {
				min_len = Math.min(min_len, distance(home.get(i), chicken.get(selected[j])));
			}
			total += min_len;
		}
		return total;
	}

	static void combi(int cnt, int start) {

		// 기저사례
		// 가장 수익을 많이 낼 수 있을 경우 : M개 프랜차이즈 다 고르기
		if (cnt == M) {
			int total = getTotalMinDistance(0);
			answer = Math.min(answer, total);
			return;

		}

		for (int i = start; i < chicken.size(); i++) {
			selected[cnt] = i;
			combi(cnt + 1, i + 1);
		}

	}

	public static void main(String[] args) throws Exception {

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String input = in.readLine();

		StringTokenizer st = new StringTokenizer(input, " ");
		int N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		// 장소 위치 입력 받기
		for (int i = 0; i < N; i++) {
			input = in.readLine();
			st = new StringTokenizer(input, " ");
			for (int j = 0; j < N; j++) {
				int value = Integer.parseInt(st.nextToken());
				if (value == 1)
					home.add(new int[] { i, j });
				else if (value == 2)
					chicken.add(new int[] { i, j });
			}
		}

		// 모든 가능한 조합을 검사하자
		selected = new int[M];
		combi(0, 0);

		System.out.println(answer);

		in.close();

	}

}

package Implementation.baekjoon;

import java.util.*;
import java.io.*;

public class baekjoon_17135 {

	static class Pos {
		int x;
		int y;

		Pos(int x_index, int y_index) {
			this.x = x_index;
			this.y = y_index;
		}
	}

	static int[][] map;
	static int[][] map_tmp;
	static Pos[] selected = new Pos[3];
	// static HashMap<Integer,Boolean> enemies = new HashMap<>();
	// static HashMap<Integer,Boolean> enemies_tmp = new HashMap<>();
	// static LinkedList<Integer> enemies = new LinkedList<>();
	static int N, M, D;
	static int full_enemy_count;
	static int answer = 0;
	static int answer_tmp = 0;

	static int[] dx = { -1, 0, 1 };
	static int[] dy = { 0, -1, 0 };

	static int distance(Pos soldier, Pos enemy) {
		return Math.abs(soldier.x - enemy.x) + Math.abs(soldier.y - enemy.y);
	}

	static Pos bfs(Pos pos) {

		Deque<Pos> q = new ArrayDeque<>();
		q.offer(pos);
		boolean[] visited = new boolean[(N + 1) * (M + 1)];
		visited[pos.x + pos.y * M] = true;

		while (!q.isEmpty()) {
			Pos now_pos = q.poll();

			// 거리가 같으면 왼쪽부터 돈다.
			for (int i = 0; i < 3; i++) {
				int new_x_pos = now_pos.x + dx[i];
				int new_y_pos = now_pos.y + dy[i];

				if (new_x_pos < 0 || new_x_pos >= M || new_y_pos < 0 || new_y_pos >= N)
					continue;

				if (visited[new_x_pos + new_y_pos * M])
					continue;

				if (distance(pos, new Pos(new_x_pos, new_y_pos)) > D)
					continue;
				// 적인지 판별

				if (map_tmp[new_y_pos][new_x_pos] == 1)
					return new Pos(new_x_pos, new_y_pos);

				q.offer(new Pos(new_x_pos, new_y_pos));
				visited[new_x_pos + new_y_pos * M] = true;

			}
		}
		return null;
	}

	static void playGame(int game_end_condition) {

		while (game_end_condition != 0) {

			// 3명의 궁수가 d 거리 이하로 존재하는 가장 가까운
			// 적 사살
			// 가장 가까운 적 bfs로 찾기
			Deque<Pos> enemy_pos = new ArrayDeque<>();
			for (int i = 0; i < 3; i++) {
				Pos result_pos = bfs(selected[i]);
				if (result_pos != null)
					enemy_pos.offer(result_pos);
			}

			// 사살
			while (!enemy_pos.isEmpty()) {
				Pos pos = enemy_pos.poll();
				if (map_tmp[pos.y][pos.x] == 1) {
					map_tmp[pos.y][pos.x] = 0;
					// enemies_tmp.remove( pos.x + pos.y*M );
					game_end_condition--;
					answer_tmp++;
				}
			}

			// 사살이 끝나고 턴이 끝나기 전에
			// 밑으로 한칸씩 내려감
			for (int i = 0; i < M; i++) {
				if (map_tmp[N - 1][i] == 1)
					game_end_condition--;
			}
			for (int i = N - 1; i > 0; i--) {
				map_tmp[i] = Arrays.copyOf(map_tmp[i - 1], M);
			}
			map_tmp[0] = new int[M];

			// List<Integer> remove_index = new ArrayList<>();
			// List<Integer> change_index = new ArrayList<>();
			// for(Integer i: enemies_tmp.keySet()) {
			// if(i/M+1 == N) remove_index.add(i);
			// else change_index.add(i);
			//
			// }
			//
			//
			// //성에 접근한 경우
			// for(int i =0; i<remove_index.size(); i++) {
			// enemies_tmp.remove(Integer.valueOf(remove_index.get(i)));
			// map_tmp[remove_index.get(i)/M][remove_index.get(i)%M] = 0;
			// game_end_condition --;
			// }
			//
			// //성에 접근하지 않은 경우
			// for(int i =change_index.size() - 1; i>=0; i--) {
			// enemies_tmp.remove(Integer.valueOf(change_index.get(i)));
			// enemies_tmp.put( Integer.valueOf(M*(((change_index.get(i)/M)+1)) +
			// change_index.get(i)%M), true);
			// map_tmp[change_index.get(i)/M][change_index.get(i)%M] = 0;
			// map_tmp[change_index.get(i)/M+1][change_index.get(i)%M] = 1;
			// }

		}
	}

	static void combi(int cnt, int start) {

		// 기저사례
		// 3 궁수의 위치를 다 골랐을 때
		if (cnt == 3) {
			answer_tmp = 0;
			// enemies_tmp.clear();
			//
			// for(Integer i: enemies.keySet()) {
			// enemies_tmp.put(i, true);
			// }

			// enemies.clear();
			map_tmp = new int[N + 1][M];
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					map_tmp[i][j] = map[i][j];
				}
			}
			playGame(full_enemy_count);
			answer = Math.max(answer, answer_tmp);

			return;
		}

		for (int j = start; j < M; j++) {
			selected[cnt] = new Pos(j, N);
			combi(cnt + 1, j + 1);
		}

	}

	public static void main(String[] args) throws Exception {

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

		String input = in.readLine();
		StringTokenizer st = new StringTokenizer(input, " ");

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		D = Integer.parseInt(st.nextToken());

		map = new int[N + 1][M];

		for (int i = 0; i < N; i++) {
			input = in.readLine();
			st = new StringTokenizer(input, " ");

			for (int j = 0; j < M; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				if (map[i][j] == 1) {
					full_enemy_count++;
					// enemies.put( i*M + j, true);
				}
			}
		}

		// 조합으로 궁수의 위치 구하기
		combi(0, 0);

		System.out.println(answer);
	}

}

#include<iostream>
#include<queue>
#define MAX 1000

using namespace std;

int N, M;
int map[MAX + 1][MAX + 1];
int visited[MAX + 1][MAX + 1][2];

//방향 전환
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

typedef struct pos {
	int x;
	int y;
	int breaking_walls;
}pos;

int bfs(int x, int y) {
	queue<pos> q;

	q.push({ x,y,0 });
	visited[x][y][0] = 1;

	while (!q.empty()) {

		pos now_pos = q.front();
		q.pop();

		if (now_pos.x == N - 1 && now_pos.y == M - 1) return visited[now_pos.x][now_pos.y][now_pos.breaking_walls];

		for (int i = 0; i < 4; i++) {
			pos new_pos;
			new_pos.x = dx[i] + now_pos.x;
			new_pos.y = dy[i] + now_pos.y;
			new_pos.breaking_walls = now_pos.breaking_walls;

			//new_pos의 값이 0보다 작거나 N-1 등의 값들 보다 클 경우 pass
			if (new_pos.x < 0 || new_pos.x > N - 1 || new_pos.y <0 || new_pos.y > M - 1) continue;
			if (visited[new_pos.x][new_pos.y][new_pos.breaking_walls]) continue;

			//map의 값이 0인 경우
			if (map[new_pos.x][new_pos.y] == 0) {
				visited[new_pos.x][new_pos.y][new_pos.breaking_walls] = visited[now_pos.x][now_pos.y][now_pos.breaking_walls] +1;
				q.push({new_pos.x, new_pos.y, now_pos.breaking_walls});
			}
			else {
				//map의 값이 벽일 경우//breaking walls가 0 의 값임을 확인
				if (new_pos.breaking_walls == 0) {
					//벽을 통과
					visited[new_pos.x][new_pos.y][1] = visited[now_pos.x][now_pos.y][0] + 1;
					q.push({new_pos.x, new_pos.y, 1});
				}
			}
		}
		
	}

	return -1;

}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf_s("%1d", &map[i][j]);
		}
	}

	int answer = bfs(0, 0);

	cout << answer << endl;
	return 0;
}
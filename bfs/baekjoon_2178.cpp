//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
//bool visited[10002] = { false, };
//int value[10002] = { 0, };
//int maze[101][101] = { 0, };
//int dx[4] = { 1,-1,0,0, };
//int dy[4] = { 0,0,1, -1 };
//int N, M;
////0보다 크고, N-1, M-1를 만나면 끝
//
//int bfs(int x, int y) {
//
//	queue<pair<int,int>> q;
//	visited[x * M + y] = true;
//	value[x * M + y] = 1;
//	q.push(make_pair(x, y));
//
//	while (!q.empty()) {
//
//		int rx = q.front().first;
//		int ry = q.front().second;
//
//		q.pop();
//
//		if (rx == N - 1 && ry == M - 1) {
//			return value[rx * M + ry];
//		}
//
//		for (int i = 0; i < 4; i++) {
//			int nx = rx + dx[i];
//			int ny = ry + dy[i];
//
//			if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
//				if (visited[nx*M+ny] == false && maze[nx][ny] == 1) {
//					q.push(make_pair(nx, ny));
//					visited[nx * M + ny] = true;
//					value[nx * M + ny] = value[rx * M + ry] + 1;
//				}
//			}
//		}
//	}
//}
//
//int main() {
//
//	cin >> N >> M;
//
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			//cin >> &maze[i][j]
//			scanf_s("%1d", &maze[i][j]);
//		}
//	}
//
//
//	int answer = bfs(0, 0);
//	cout << answer << endl;
//}
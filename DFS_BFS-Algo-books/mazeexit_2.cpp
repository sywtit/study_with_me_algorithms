#include<iostream>
#include<vector>
#include<ctime>
#include<queue>
using namespace std;

int N, M;
int map[201][201];

//direction별 이동
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0, -1,1 };

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	//queue가 빌때까지
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			//미로를 벗어난 경우 패쓰
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			// 벽인 경우 무시
			if (map[nx][ny] == 0) continue;
			// 해당 노드를 처음 방문하는 경우에만 최단 거리 기록
			if (map[nx][ny] == 1)
			{
				map[nx][ny] = map[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}

	cout << map[N - 1][M - 1] << endl;
}
int main()
{
	time_t start_time = time(0);

	//입력받기
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf_s("%1d", &map[i][j]);
		}
	}

	//최소칸의 개수 bfs를 사용 //fifo
	bfs(0, 0);

	//시간 경과
	time_t end_time = time(0);
	cout << "time: " << end_time - start_time << endl;

	return 0;

}

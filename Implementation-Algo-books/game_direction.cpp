#include<iostream>
#include<algorithm>
#include<vector>
#include<ctime>
using namespace std;

int main()
{
	//time_t start_time = time(0);

	int N, M;
	cin >> N >> M;

	int locX, locY, dir;
	cin >> locX >> locY >> dir;

	//북쪽, 동쪽, 남쪽, 서쪽
	int direction[] = { 0,1,2,3 };
	int dx[] = { 0,1,0,-1 };
	int dy[] = { -1,0,1,0 };

	int new_locX, new_locY;

	//입력
	vector<vector<pair<int,bool>>> map(N+1,vector<pair<int,bool>>(M+1,make_pair(0,false)));


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j].first;
			
		}
	}

	//change direction 
	int count = 0;

	while (true)
	{

		map[locX][locY].second = true;

		if (dir == 0) dir = 3;
		else dir -= 1;

		count++;

		//count가 4일때 모든 바향으로 다 돌음
		if (count == 4)
		{
			new_locX = locX - dx[dir];
			new_locY = locY - dy[dir];
			if (map[new_locX][new_locY].first == 0)
			{
				count = 0;
				locX = new_locX;
				locY = new_locY;
				continue;
			}
			else break;
		}

		new_locX = locX + dx[dir];
		new_locY = locY + dy[dir];

		if (new_locX >= 1 && new_locX <= M && new_locY >= 1 && new_locY <= N)
		{
			if (map[new_locX][new_locY].second == false && map[new_locX][new_locY].first == 0)
			{
				locX = new_locX;
				locY = new_locY;
				count = 0;
				continue;
			}
			else continue;
		}
		else continue;


	}

	int result = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j].second == true)
				result++;

		}
	}

	cout << result << endl;

	//time_t end_time = time(0);
	//cout << "time : " << end_time - start_time << endl;
	////time = 1


	return 0;

}
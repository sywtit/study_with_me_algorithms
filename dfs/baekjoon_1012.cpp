#include<iostream>
#include<math.h>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;
bool dfsVisited[50 * 50 + 2] = { false, };

bool compare(pair<int, int> left, pair<int, int> right)
{
	if (left.second < right.second)
		return true;
	else if (left.second == right.second)
	{
		if (left.first < right.first)
			return true;
	}

	return false;
}

void dfs(vector<vector<int>> temp, int startPoint)
{
	dfsVisited[startPoint] = true;

	for (int i = 0; i < temp[startPoint].size(); i++)
	{
		if (dfsVisited[temp[startPoint][i]] == false)
		{
			dfs(temp,  temp[startPoint][i]);
		}
	}
}
int main() {

	cin.tie(NULL);
	std::cout.tie(NULL);

	//test case
	int T = 0;
	cin >> T;

	//가로길이, 세로길이, 위치의 개수
	int M = 0, N = 0, K = 0;
	//배추의 위치
	int X = 0, Y = 0;
	//answer
	vector<int> answer;

	//dfs방식으로 try

	for (int test = 0; test < T; test++)
	{
		cin >> M >> N >> K;

		vector<int> field(M * N);
		vector<vector<int>> arr(M * N + 2);
		vector<pair<int, int>> changeXY;
		memset(dfsVisited, false, sizeof(dfsVisited));

		for (int i = 0; i < K; i++)
		{
			cin >> X >> Y;
			changeXY.push_back(make_pair(X, Y));

		}

		//sort changeXY with value Y
		sort(changeXY.begin(), changeXY.end(), compare);

		for (int i = 0; i < K; i++)
		{
			X = changeXY[i].first;
			Y = changeXY[i].second;

			field[X + Y * M] = 1;

			if (X > 0 && Y > 0)
			{
				if (field[(Y - 1) * M + X] == 1)
				{
					arr[Y * M + X].push_back((Y - 1) * M + X);
					arr[(Y - 1) * M + X].push_back(Y * M + X);
				}
				if (field[Y * M + X - 1] == 1)
				{
					arr[Y * M + X].push_back(Y * M + X - 1);
					arr[Y * M + X - 1].push_back(Y * M + X);
				}
			}
			else if (Y == 0 && X > 0) {
				if (field[X - 1] == 1)
				{
					arr[X].push_back(X - 1);
					arr[X - 1].push_back(X);
				}
			}
			else if (Y > 0 && X == 0)
			{
				if (field[(Y - 1) * M] == 1)
				{
					arr[Y * M].push_back((Y - 1) * M);
					arr[(Y - 1) * M].push_back(Y * M);
				}
			}
		}

		//sort
		for (int i = 0; i <= M * N; i++)
		{
			sort(arr[i].begin(), arr[i].end());
		}

		//dfs
		int answerCount = 0;

		for (int i = 0; i < M * N; i++)
		{
			if (dfsVisited[i] == false && field[i] == 1)
			{
				dfs(arr, i);
				answerCount++;

			}
		}
		answer.push_back(answerCount);

	}

	for (int i = 0; i < T; i++) {
		cout << answer[i] << endl;
	}

	return 0;

}
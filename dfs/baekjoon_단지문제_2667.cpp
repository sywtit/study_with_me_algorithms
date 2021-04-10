#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#pragma warning(disable: 4996)

using namespace std;
bool dfsVisited[25 * 25 + 2] = { false, };
int apartLine[25 * 25 + 1] = { 0, };
int dfsCount = 0;

void dfs(vector<vector<int>> temp, int mazePoint, int startPoint)
{
	dfsVisited[startPoint] = true;
	dfsCount++;

	for (int i = 0; i < temp[startPoint].size(); i++)
	{
		if (dfsVisited[temp[startPoint][i]] == false)
		{
			dfs(temp, mazePoint, temp[startPoint][i]);
		}
	}
}
int main()
{
	cin.tie(NULL);
	std::cout.tie(NULL);
	//ios::sync_with_stdio(false);
	//sync_with_stdio (false)쓰면 c, c++ 입출력 섞어 쓰면 안됨
	int mazeSize;
	cin >> mazeSize;

	vector<int> maze(mazeSize * mazeSize);
	vector<vector<int>> arr(mazeSize * mazeSize + 2);
	int apartLineIndex = 0;

	for (int i = 0; i < mazeSize; i++)
	{
		for (int j = 0; j < mazeSize; j++)
		{
			//cin >> maze[i*mazeSize+j];
			scanf("%1d", &maze[i * mazeSize + j]);

			if (maze[i * mazeSize + j] == 1)
			{
				if (i > 0 && j > 0)
				{
					if (maze[(i - 1) * mazeSize + j] == 1)
					{
						arr[i * mazeSize + j].push_back((i - 1) * mazeSize + j);
						arr[(i - 1) * mazeSize + j].push_back(i * mazeSize + j);
					}
					if (maze[i * mazeSize + j - 1] == 1)
					{
						arr[i * mazeSize + j].push_back(i * mazeSize + j - 1);
						arr[i * mazeSize + j - 1].push_back(i * mazeSize + j);
					}
				}
				else if (i == 0 && j > 0) {
					if (maze[j - 1] == 1)
					{
						arr[j].push_back(j - 1);
						arr[j - 1].push_back(j);
					}
				}
				else if (i > 0 && j == 0)
				{
					if (maze[(i - 1) * mazeSize] == 1)
					{
						arr[i * mazeSize].push_back((i - 1) * mazeSize);
						arr[(i - 1) * mazeSize].push_back(i * mazeSize);
					}
				}
			}
		}
	}

	//sort가 필요한가?
	for (int i = 1; i <= mazeSize * mazeSize; i++)
	{
		sort(arr[i].begin(), arr[i].end());
	}

	//dfs로 단지를 찾을 예정
	for (int i = 0; i < mazeSize * mazeSize; i++)
	{
		if (dfsVisited[i] == false && maze[i] == 1)
		{
			dfsCount = 0;
			dfs(arr, mazeSize * mazeSize, i);
			apartLine[apartLineIndex++] = dfsCount;
		}
	}

	sort(apartLine, apartLine + (apartLineIndex));

	//총 단지수 출력
	std::cout << apartLineIndex;

	for (int i = 0; i < apartLineIndex; i++)
	{
		std::cout << "\n" << apartLine[i];
	}

	return 0;

}
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<math.h>
using namespace std;

queue<int> rqueue;
bool bfsVisited[102] = { false, };
int defectedCom = -1;
//bfs방법이 더 좋을것 같다
//깊게 탐색하기 전에 넓게 탐색하는 방법

void bfs(vector<vector<int>> temp, int comNum)
{
	bfsVisited[1] = true;
	rqueue.push(1);

	while (!rqueue.empty())
	{
		int tmp = rqueue.front();
		rqueue.pop();
		defectedCom++;

		for (int i = 0; i < temp[tmp].size(); i++)
		{
			if (bfsVisited[temp[tmp][i]] == false)
			{
				rqueue.push(temp[tmp][i]);
				bfsVisited[temp[tmp][i]] = true;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);

	ios::sync_with_stdio(false);

	int comNum, comPair;
	int temp1, temp2;
	cin >> comNum >> comPair;

	vector<vector<int>> arr(comNum + 1);

	for (int i = 0; i < comPair; i++)
	{
		cin >> temp1 >> temp2;
		arr[temp1].push_back(temp2);
		arr[temp2].push_back(temp1);
	}

	//than sorting
	for (int i = 1; i <= comNum; i++)
	{
		sort(arr[i].begin(), arr[i].end());
	}

	//무조건 1번 컴퓨터 에러
	//1번부터 탐색시작
	bfs(arr, comNum);

	cout << defectedCom;

	return 0;
}
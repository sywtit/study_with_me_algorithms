#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<unordered_map>
#include<ctime>
using namespace std;

int main()
{
	//check time
	time_t start_time = time(0);

	int N, M, K;
	int min = 10000;
	int answer = 0;
	cin >> N >> M;


	unordered_map<int, int> minimumMap;

	for (int i = 0; i < N; i++)
	{
		min = 10000;

		for (int j = 0; j < M; j++)
		{
			cin >> K;
			if (min > K) min = K;
		}

		minimumMap.insert(make_pair(i, min));
	}

	//min을 기준으로  내림 차순으로 제일 큰 값을 구하기
	int max = -1;
	for (pair<int, int> minimum : minimumMap)
	{
		if (max < minimum.second)
			answer = minimum.second;
	}

	cout << answer << endl;
	time_t end_time = time(0);

	cout << "time : " << end_time - start_time;

	return 0;
}

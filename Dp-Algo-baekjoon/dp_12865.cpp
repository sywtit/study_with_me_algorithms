#include<iostream>
#include<algorithm>

using std::cin; 
using std::cout;
using namespace std;

int dp_12865[100001] = { 0, };

int main()
{
	std::ios::sync_with_stdio(false);
	int ans = 0;
	int N, K, W, V;
	
	cin >> N >> K;
	for (int i = 1; i <= N; ++i)
	{
		cin >> W >> V;
		if (V <= 0) continue;

		if (K < W) continue;
		else if( K == W)
		{
			//do nothing
		}
		else
		{
			for (int cur = K - W; cur >= 1; --cur)
			{
				if (dp_12865[cur] <= 0) continue;

				dp_12865[cur + W] = max(dp_12865[cur + W], dp_12865[cur] + V);
				ans = max(ans, dp_12865[cur + W]);
			}
		}
		dp_12865[W] = max(dp_12865[W], V);
		ans = max(ans, dp_12865[W]);
	}

	cout << ans << '\n';
	
	return 0;
}
//여기의 문제점은 k보다 큰 w가 입력으로 들어오는 경우
// 입력 받을 때 해당 케이스 넘기게끔 조건만 추가해주면 통과 가능
//2차원 배열보다 더 좋을지는 메모리와, 속도 상 생각해서 고쳐보장

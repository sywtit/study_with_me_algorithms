#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 10000000000

int N, M;
vector<int> trees;
int main() {
	scanf("%d %d", &N, &M);
	int left = 1, right = 0, sum;
	long long middle;
	
	for (int i = 0; i < N; i++) {
		int height;
		scanf("%d", &height);
		trees.push_back(height);
		right = max(right, height);
	}

	//ÀÌÁø Å½»ö
	int H = MAX;
	while (left <= right) {
		middle = (left + right) / 2;
		sum = 0;

		for (int i = 0; i < N && sum <= M; i++) {
			if (trees[i] - middle > 0)
				sum += trees[i] - middle;
		}
		
		if (!(sum - M)) {
			printf("%d\n", (int)middle);
			return 0;
		}
		else if (sum - M > 0)
			left = middle + 1;
		else right = middle - 1;
	}
	printf("%d\n", right);
	return 0;
}
//https://ksj14.tistory.com/entry/BackJoon2805-%EB%82%98%EB%AC%B4-%EC%9E%90%EB%A5%B4%EA%B8%B0

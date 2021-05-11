#include <iostream>
#include <unordered_map>

using namespace std;
int N, M;
unordered_map<int, int> number_map;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		auto item = number_map.find(x);
		
		if (item == number_map.end()) {
			number_map.insert({ x,1 });
		}
		else {
			number_map[x]++;
		}
	}

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int x;
		scanf("%d", &x);
		
		auto item = number_map.find(x);
		if (item == number_map.end()) {
			printf("0 ");
		}
		else {
			printf("%d ", number_map[x]);
		}
	}
	return 0;
}
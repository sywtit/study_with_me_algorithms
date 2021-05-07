#include <iostream>
using namespace std;

int N, M;
int parent[1000001] = { 0, };

int findParent(int x) {
	if (x == parent[x]) return x;
	return parent[x] = findParent(parent[x]);
}

void unionParent(int x, int y) {
	int xp = findParent(x);
	int yp = findParent(y);
	//if (xp < yp) parent[yp] = xp;
	//else parent[xp] = yp;
	if (xp != yp) parent[yp] = xp;
}

int main() {
	cin >> N >> M;

	//부모를 자기자신으로 모두 초기화
	for (int i = 0; i < 1000001; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int what, a, b;
		scanf("%d %d %d", &what, &a, &b);

		if (what == 0) {
			//if(findParent(a) != findParent(b))
			unionParent(a, b);
		}
		else {
			if (findParent(a) == findParent(b))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}

	return 0;
}
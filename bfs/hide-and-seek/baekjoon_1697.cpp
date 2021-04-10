#include <iostream>
#include <queue>
using namespace std;

#define MAX 100000


int N, K;
bool visited[MAX + 1] = { false, };

int bfs(int position) {
	
	queue<pair<int,int>> q;
	q.push(make_pair(position, 0));

	int count = 0;

	while (!q.empty()) {

		int p = q.front().first;
		int c = q.front().second;
		q.pop();

		visited[p] = true;

		//p의 값과 K의 값이 같으면 stop
		if (p == K || p<0 || p>MAX) return c;

		else {
			if (p * 2 <= MAX && !visited[p*2]) {
				int np = p * 2;
				int nc = c + 1;
				q.push(make_pair(np, nc));
			}
			if (p + 1 <= MAX && !visited[p+1]) {
				int np = p + 1;
				int nc = c + 1;
				q.push(make_pair(np, nc));
			}
			if (p-1 >= 0 && !visited[p-1]){
				int np = p - 1;
				int nc = c + 1;
				q.push(make_pair(np, nc));
			}
		}

	}
	return -1;
}

int main() {

	cin >> N >> K;

	int count = bfs(N);
	cout << count << endl;

	return 0;
}
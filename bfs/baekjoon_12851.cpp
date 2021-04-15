//#include <iostream>
//#include<queue>
//using namespace std;
//#define MAX 100000
//
//int N, K;
//
//int bfs(int position) {
//
//	int how = 1;
//	bool visited[MAX + 1] = { false, };
//
//	queue<pair<int, int>> q;
//	q.push(make_pair(position, 0));
//
//	while (!q.empty()) {
//
//		int p = q.front().first;
//		int c = q.front().second;
//
//		visited[p] = true;
//		q.pop();
//
//		if (p == K || p<0 || p>MAX) {
//
//			while (!q.empty()) {
//				int p2 = q.front().first;
//				int c2 = q.front().second;
//				q.pop();
//				if (c == c2 && p2 == K) how++;
//			}
//			cout << c << endl << how << endl;
//			return 0;
//		}
//
//		else {
//
//			if (p * 2 <= MAX && !visited[p * 2]) {
//				int np = p * 2;
//				int nc = c + 1;
//				q.push(make_pair(np, nc));
//			}
//			if (p + 1 <= MAX && !visited[p + 1]) {
//				int np = p + 1;
//				int nc = c + 1;
//				q.push(make_pair(np, nc));
//			}
//			if (p - 1 >= 0 && !visited[p - 1]) {
//				int np = p - 1;
//				int nc = c + 1;
//				q.push(make_pair(np, nc));
//			}
//		}
//
//		
//	}
//
//	return -1;
//}
//
//int main() {
//	cin >> N >> K;
//
//	bfs(N);
//
//	return 0;
//}
////#include <iostream>
////#include <queue>
////#include<vector>
////using namespace std;
////
////#define MAX 100000
////
////
////int N, K;
////bool visited[MAX + 1] = { false, };
////
////int bfs(int position) {
////	
////	queue<pair<vector<int>,int>> q;
////	vector<int> indexv;
////	//indexv.reserve(MAX);
////	indexv.push_back(position);
////	q.push(make_pair(indexv, 0));
////
////	int count = 0;
////
////	while (!q.empty()) {
////
////	
////		vector<int> vecp = q.front().first;
////		int p = vecp.back();
////		int c = q.front().second;
////		q.pop();
////
////		visited[p] = true;
////
////		//p의 값과 K의 값이 같으면 stop
////		if (p == K || p<0 || p>MAX) {
////			int min = c;
////			vector<int> resultv = vecp;
////
////			while (!q.empty()) {
////				vector<int> vecp2 = q.front().first;
////				int p2 = vecp2.back();
////				int c2 = q.front().second;
////
////				q.pop();
////
////				if (min > c2) {
////					min = c2;
////					resultv = vecp2;
////				}
////			}
////			cout << min << endl;
////			for (int i = 0; i < resultv.size(); i++) {
////				cout << resultv[i] << " ";
////			}
////			return -1;
////		}
////
////		else {
////			if (p * 2 <= MAX && !visited[p*2]) {
////				int np = p * 2;
////				int nc = c + 1;
////				vector<int> vecp2 = vecp;
////				vecp2.push_back(np);
////				q.push(make_pair(vecp2, nc));
////			}
////			if (p + 1 <= MAX && !visited[p+1]) {
////				int np = p + 1;
////				int nc = c + 1;
////				vector<int> vecp2 = vecp;
////				vecp2.push_back(np);
////				q.push(make_pair(vecp2, nc));
////			}
////			if (p-1 >= 0 && !visited[p-1]){
////				int np = p - 1;
////				int nc = c + 1;
////				vector<int> vecp2 = vecp;
////				vecp2.push_back(np);
////				q.push(make_pair(vecp2, nc));
////			}
////		}
////
////	}
////	return -1;
////}
////
////int main() {
////
////	cin >> N >> K;
////
////	bfs(N);
////
////	return 0;
////}
//
//#include <iostream>
//#include <queue>
//#include <stack>
//using namespace std;
//
//#define MAX 100000
//
//
//int N, K;
//bool visited[MAX + 1] = { false, };
//int from[MAX + 1];
//
//int bfs(int position) {
//
//	queue<pair<int, int>> q;
//	q.push(make_pair(position, 0));
//
//	int count = 0;
//
//	while (!q.empty()) {
//
//		int p = q.front().first;
//		int c = q.front().second;
//		q.pop();
//
//		visited[p] = true;
//
//		//p의 값과 K의 값이 같으면 stop
//		if (p == K || p<0 || p>MAX) return c;
//
//		else {
//			if (p * 2 <= MAX && !visited[p * 2]) {
//				int np = p * 2;
//				int nc = c + 1;
//				q.push(make_pair(np, nc));
//				from[np] = p;
//				visited[np] = true;
//			}
//			if (p + 1 <= MAX && !visited[p + 1]) {
//				int np = p + 1;
//				int nc = c + 1;
//				q.push(make_pair(np, nc));
//				from[np] = p;
//				visited[np] = true;
//			}
//			if (p - 1 >= 0 && !visited[p - 1]) {
//				int np = p - 1;
//				int nc = c + 1;
//				q.push(make_pair(np, nc));
//				from[np] = p;
//				visited[np] = true;
//			}
//		}
//
//	}
//	return -1;
//}
//
//int main() {
//
//	cin >> N >> K;
//
//	int count = bfs(N);
//	cout << count << endl;
//
//	//거꾸로 저장
//	stack<int> s;
//	s.push(K);
//
//	for (int i = K; i != N; i = from[i]) {
//		s.push(from[i]);
//	}
//
//	while (!s.empty()) {
//		cout << s.top() << " ";
//		s.pop();
//	}
//
//	return 0;
//}
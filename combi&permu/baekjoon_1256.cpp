//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int N,M,K;
//vector<int> charactor;
//
//void combination(int depth, int next)
//{
//	//기저 사례
//	
//}
//
//int main() {
//
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> N >> M >> K;
//	//n개의 'a'와 M개의 'z' 사전순대로 
//
//	////charactor안에 0,1,0,1집어 넣음
//	//for (int i = 0; i < N; i++) {
//	//	charactor.push_back(1);
//	//}
//	//for (int i = 0; i < M; i++) {
//	//	charactor.push_back(0);
//	//}
//
//	//조합으로 풀기
//	//depth, next
//	//M개의 값을 위치시키는 방법
//	combination(0, 1);
//
//
//	////prev_permutation
//	//int size = 0;
//	//do {
//	//	string answer = "";
//	//	for (int i = 0; i < charactor.size(); i++) {
//	//		if (charactor[i] == 1) {
//	//			answer.push_back('a');
//	//		}
//	//		else {
//	//			answer.push_back('z');
//	//		}
//	//	}
//	//	size++;
//	//	if (size == K) {
//	//		cout << answer;
//	//		return 0;
//	//	}
//	//} while (prev_permutation(charactor.begin(), charactor.end()));
//
//
//	cout << "-1";
//	return 0;
//	
//}
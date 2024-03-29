#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//노드의 개수(V)와 간선(Union 연산)의 개수(E)

int v, e;
int parent[100001];

//간선 리스트, 최종 비용
vector<pair<int, pair<int, int>>> edges;
int result = 0;

//특정 원소가 속한 집합을 찾기
int findParent(int x) {
	if (x == parent[x]) return x;
	return parent[x] = findParent(parent[x]);
}

//두 원소가 속한 집합을 합치기
void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}
int main() {
	cin >> v >> e;

	//부모 테이블 상에서, 부모를 자기 자신으로 초기화
	for (int i = 0; i <= v; i++) {
		parent[i] = i;
	}

	//모든 간선에 대한 정보를 입력받는다.
	for (int i = 0; i < e; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		edges.push_back({ cost,{a,b} });
	}

	//간선 비용 순으로 정렬
	sort(edges.begin(), edges.end());

	//간선을 하나씩 확인하며
	for (int i = 0; i < edges.size(); i++) {
		int cost = edges[i].first;
		int a = edges[i].second.first;
		int b = edges[i].second.second;

		//사이클이 발생하지 않는 경우에만 집합에 포함
		if (findParent(a) != findParent(b)) {
			unionParent(a, b);
			result += cost;
		}
	}

	cout << result << '\n';
}

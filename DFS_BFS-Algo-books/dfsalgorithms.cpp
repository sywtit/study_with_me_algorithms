#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<bool> visited(9, false);
vector<int> graph[9];

void dfs(int node)
{
    visited[node] = true;
    cout << node << ' ';
    //연결된 다른 노드를 재귀적으로 방문
    for (int i = 0; i < graph[node].size(); i++)
    {
        int nextnode = graph[node][i];
        if (visited[nextnode]==false) dfs(nextnode);
    }
}

int main_dfs()
{
	graph[1].push_back(2);
	graph[1].push_back(3);
	graph[1].push_back(8);

	sort(graph[1].begin(), graph[1].end());

    // 노드 2에 연결된 노드 정보 저장 
    graph[2].push_back(1);
    graph[2].push_back(7);

    // 노드 3에 연결된 노드 정보 저장 
    graph[3].push_back(1);
    graph[3].push_back(4);
    graph[3].push_back(5);

    // 노드 4에 연결된 노드 정보 저장 
    graph[4].push_back(3);
    graph[4].push_back(5);

    // 노드 5에 연결된 노드 정보 저장 
    graph[5].push_back(3);
    graph[5].push_back(4);

    // 노드 6에 연결된 노드 정보 저장 
    graph[6].push_back(7);

    // 노드 7에 연결된 노드 정보 저장 
    graph[7].push_back(2);
    graph[7].push_back(6);
    graph[7].push_back(8);

    // 노드 8에 연결된 노드 정보 저장 
    graph[8].push_back(1);
    graph[8].push_back(7);

    dfs(1);
    return 0;
}
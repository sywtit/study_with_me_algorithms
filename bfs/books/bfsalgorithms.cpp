#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<bool> visited(9, false);
vector<int> graph[9];

void bfs(int node)
{
    queue<int> q;
    q.push(node);

    visited[node] = true;

    //queue 빌 때까지 반복
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        cout << front << ' ';

        for (int i = 0; i < graph[front].size(); i++)
        {
            int nextnode = graph[front][i];
            if (visited[nextnode] == false)
            {
                q.push(nextnode);
                visited[nextnode] = true;
            }
        }
    }
}

int main()
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

    bfs(1);
    return 0;
}
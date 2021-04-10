#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

bool dfsVisited[1002] = { false, };
bool bfsVisited[1002] = { false, };
//왜 bfs rqueue로 한건지는 나중에 알아봐야 할듯
queue<int> bfsRq;
int dfsCount = 0, bfsCount = 0;

//preorder와 비슷한 dfs 1. 먼저 출력을하고 link로 타고 들어감
void dfs(vector<vector<int>> temp, int v, int n)
{
    //처음에 들어가는 v의 값 : 처음 시작 vertex
    //정점의 개수 : n
    dfsVisited[v] = true;
    cout << v << " ";

    if (dfsCount == n) return;

    for (int i = 0; i < temp[v].size(); i++)
    {
        if (dfsVisited[temp[v][i]] == false)
        {
            dfsCount++;
            dfs(temp, temp[v][i], n);
        }
    }

}

//levelorder와 비슷하고, 인접한 것들 부터 방문하는 방법
void bfs(vector<vector<int>> temp, int v, int n)
{
    bfsVisited[v] = true;
    bfsRq.push(v);

    while (!bfsRq.empty())
    {
        int tmp = bfsRq.front();
        bfsRq.pop();

        cout << tmp << " ";
        for (int i = 0; i < temp[tmp].size(); i++)
        {
            if (bfsVisited[temp[tmp][i]] == false)
            {
                bfsRq.push(temp[tmp][i]);
                bfsVisited[temp[tmp][i]] = true;

            }
        }
    }
}

int main()
{
    //cin를 flush 해주면서 그전에 cout 함수를 사용했다면 제대로 출력이 될 것이다.
    cin.tie(NULL);

    std::ios::sync_with_stdio(false);
    //정점의개수, 간선의 개수, 처음 시작 vertex 
    int N, M, V;
    cin >> N >> M >> V;


    vector<vector<int>> arr(N + 1);

    //temp으로 해서 다 저장하는 방법
    //우선 모든 vertex에 해당하는 모든 link의 값을 다 넣어준다.
    for (int i = 0; i < M; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        arr[temp1].push_back(temp2);
        arr[temp2].push_back(temp1);
    }

    //이후에 sort를 해주는 방법
    //하나의 정점에서 다음을 탐색할 때 node값에 순차적으로 접근하기 위해서
    for (int i = 1; i <= N; i++)
    {
        sort(arr[i].begin(), arr[i].end());
    }

    dfs(arr, V, N);
    cout << "\n";
    bfs(arr, V, N);

    return 0;
}
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int inf = 20000;
vector<int> dist;
queue<int> que;

void dijkstra(int start, int pos, vector<vector<int>>& nodes, vector<bool>& check)
{
    for (int i = 0; i < nodes[pos].size(); i++)
    {
        int endPos = nodes[pos][i];
        if (check[endPos] == true)
            continue;

        if (dist[endPos] >= dist[pos] + 1)
        {
            que.push(endPos);
            dist[endPos] = min(dist[endPos], dist[pos] + 1);
        }

        check[endPos] = true;
    }
    while (!que.empty())
    {
        int temp = que.front();
        que.pop();
        dijkstra(start, temp, nodes, check);
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> nodes(n+1);
    dist.resize(n + 1, inf);

    for (int i = 0; i < edge.size(); i++)
    {
        int start = edge[i][0];
        int end = edge[i][1];
        nodes[start].push_back(end);
        nodes[end].push_back(start);
        if (start == 1)
            dist[end] = 1;
    }
    dist[1] = 0;

    vector<bool> check(n+1,false);

    dijkstra(1, 1, nodes, check);

    int maxDis = 0;
    for (int i = 1; i < dist.size(); i++)
    {
        maxDis = max(maxDis, dist[i]);
    }
    for (int i = 1; i < dist.size(); i++)
    {
        if (maxDis == dist[i])
            answer++;
    }
    return answer;
}

int main()
{
    solution(6, { {3, 6} ,{4, 3},{3, 2},{1, 3},{1, 2},{2, 4},{5, 2} });
}



#include <string>
#include <vector>
#include <queue>

using namespace std;

int infy = 500001;
queue<int> que;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;

    vector<int> dist(n + 1, infy);
    vector<vector<int>> nodes(n + 1);


    for (int i = 0; i < roads.size(); i++)
    {
        nodes[roads[i][0]].emplace_back(roads[i][1]);
        nodes[roads[i][1]].emplace_back(roads[i][0]);

    }

    dist[destination] = 0;
    que.push(destination);

    int temp;
    while(!que.empty())
    {
        temp = que.front();
        que.pop();

        for (int i = 0; i < nodes[temp].size(); i++)
        {
            int endPos = nodes[temp][i];

            if (dist[endPos] > dist[temp] + 1)
            {
                dist[endPos] = dist[temp] + 1;
                que.push(endPos);
            }
        }

    }

    for (int i = 0; i < sources.size(); i++)
    {
        if (dist[sources[i]] == infy)
            temp = -1;
        else
            temp = dist[sources[i]];
        answer.push_back(temp);
    }

    return answer;
}

int main()
{
    solution(5, { {1, 2} ,{1, 4},{2, 4},{2, 5},{4, 5} }, { 1,3,5 }, 5);
}
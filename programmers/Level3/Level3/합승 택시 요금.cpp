#include <string>
#include <vector>
using namespace std;

int Infy = 50000000;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = Infy;

    vector<vector<int>> dist(n+1, vector<int>(n+1, Infy));

    for (int i = 0; i < fares.size(); i++)
    {
        int start = fares[i][0];
        int end = fares[i][1];
        int cost = fares[i][2];

        dist[start][end] = cost;
        dist[end][start] = cost;
    }
    int minNum = Infy;

    for (int i = 1; i <= n; i++)
        dist[i][i] = 0;

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (dist[s][i] + dist[i][a] + dist[i][b] <= minNum)
        {
            minNum = dist[s][i] + dist[i][a] + dist[i][b];
        }
    }

    answer = min(answer, minNum );


    return answer;
}
int main()
{
    solution(3, 1, 2, 3, { {1,2,3},{2,3,4},{3,1,4} });
}
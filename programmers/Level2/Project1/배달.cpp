#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int Infy;
int Max;


int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    Max = K;
    Infy = K + 1;
    vector<vector<int>> arr(N + 1, vector<int>(N + 1, Infy));


    unordered_map<int, bool> pre;
    for (int i = 0; i < road.size(); i++)
    {
        int start = road[i][0];
        int end = road[i][1];
        int kost = road[i][2];
        arr[start][end] = min(kost, arr[start][end]);
        arr[end][start] = min(kost, arr[end][start]);
    }

    for (int i = 1; i < arr.size(); i++)
    {
        for (int j = 1; j < arr.size(); j++)
        {
            if(i == j)
                arr[i][j] = 0;
            for (int k = 1; k < arr.size(); k++)
            {
                arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
            }
        }
    }

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[1][i] <= K)
            answer++;
    }

    return answer;
}

int main()
{
    solution(6, {{1, 2, 1}, {1, 3, 2}, {2, 3, 2}, {3, 4, 3}, {3, 5, 2}, {3, 5, 3}, {5, 6, 1}}, 4);
}
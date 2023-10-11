#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    const int max = 1000000007;

    vector<vector<int>> arr(n + 1, vector<int>(m + 1,0));

    for (vector<int> p : puddles)
    {
        arr[p[1]][p[0]] = -1;
    }
    arr[1][1] = 0;
    if(arr[1][2] != -1)
        arr[1][2] = 1;
    if(arr[2][1] != -1)
        arr[2][1] = 1;

    /*for (int i = 2; i < arr.size(); i++)
    {
        if (arr[i][1] == -1)
        {
            for (int j = 2; j < arr.size(); j++)
            {
                arr[j][1] = -1;
            }
        }
    }
    for (int i = 2; i < arr[1].size(); i++)
    {
        if (arr[1][i] == -1)
        {
            for (int j = 2; j < arr[1].size(); j++)
            {
                arr[1][j] = -1;
            }
        }
    }*/
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr[i][j] == -1)
                continue;

            if (j + 1 <= m && arr[i][j + 1] != -1)
            {
                arr[i][j + 1] += arr[i][j] % max;
                arr[i][j + 1] %= max;
            }

            if (i + 1 <= n && arr[i + 1][j] != -1)
            {
                arr[i+1][j] += arr[i][j] % max;
                arr[i + 1][j] %= max;
            }
        }
    }

    if (arr[n][m] == 0)
        return 0;

    answer = arr[n][m];

    return answer;
}

int main()
{
    solution(4,3, { { 2,1 } });
}
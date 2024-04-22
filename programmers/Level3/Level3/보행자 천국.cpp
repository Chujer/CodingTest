#include <vector>
#include <iostream>
using namespace std;

int MOD = 20170805;


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;

    vector<vector<int>> DPR(m, vector<int>(n, 0));
    vector<vector<int>> DPD(m, vector<int>(n, 0));

    DPR[0][0] = 1;
    DPD[0][0] = 1;
    for (int i = 0; i < m; i++)
    {
        DPD[i][0] = 1;
        if (city_map[i][0] == 1)
            break;
    }
    for (int i = 0; i < n; i++)
    {
        DPR[0][i] = 1; 
        if (city_map[0][i] == 1)
            break;
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n ; j++)
        {
            if (city_map[i][j] == 1)
                continue;

            if (city_map[i - 1][j] == 0)
                DPD[i][j] = (DPD[i - 1][j] + DPR[i - 1][j]) % MOD;
            if (city_map[i - 1][j] == 1)
                DPD[i][j] = 0;
            if (city_map[i - 1][j] == 2)
                DPD[i][j] =  DPD[i - 1][j];


            if (city_map[i][j - 1] == 0)
                DPR[i][j] = (DPD[i][j - 1] + DPR[i][j - 1]) % MOD;
            if (city_map[i][j - 1] == 1)
                DPR[i][j] = 0;
            if (city_map[i][j - 1] == 2)
                DPR[i][j] = DPR[i][j - 1];
        }
    }
    answer = (DPR[m - 1][n - 1] + DPD[m - 1][n - 1]) % MOD;

    return answer;
}

int main()
{
    solution(3, 6, { {0, 2, 0, 0, 0, 2} ,{0, 0, 2, 0, 1, 0},{1, 0, 0, 2, 2, 0} });
}
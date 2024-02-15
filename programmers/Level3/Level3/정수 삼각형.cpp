#include <string>
#include <vector>

using namespace std;

int DP[500][10000];

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    int tempNum = 1;
    
    DP[0][0] = triangle[0][0];

    for (int i = 1; i < triangle.size(); i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            int left = j - 1;
            int right = j;
            if (left < 0)
                DP[i][j] = DP[i - 1][j] + triangle[i][j];
            else if (right >= triangle[i - 1].size())
                DP[i][j] = DP[i - 1][left] + triangle[i][j];
            else
                DP[i][j] = max(DP[i - 1][left], DP[i - 1][right]) + triangle[i][j];
            if (i == triangle.size()-1)
                answer = max(answer, DP[i][j]);
        }
    }

    return answer;
}

int main()
{
    solution({{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}} );
}
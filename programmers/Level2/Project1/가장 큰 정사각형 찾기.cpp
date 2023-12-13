#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    int row_size = board.size();
    int col_size = board[0].size();
    vector<vector<int>> dp(row_size, vector<int>(col_size, 0));

    // 첫 번째 행과 열은 원래 보드의 값을 그대로 복사
    for (int i = 0; i < row_size; i++)
        dp[i][0] = board[i][0];

    for (int i = 0; i < col_size; i++)
        dp[0][i] = board[0][i];

    for (int i = 1; i < row_size; i++)
    {
        for (int j = 1; j < col_size; j++)
        {
            if (board[i][j] == 1)
            {
                // 위, 왼쪽, 왼쪽 위 대각선의 최솟값 + 1
                dp[i][j] = min({ dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] }) + 1;
            }
        }
    }

    // 가장 큰 정사각형 찾기
    for (int i = 0; i < row_size; i++)
    {
        for (int j = 0; j < col_size; j++)
        {
            answer = max(answer, dp[i][j]);
        }
    }

    return answer * answer;  // 정사각형의 넓이 반환
}

int main()
{
    //solution({ {0, 0, 1, 0}, {0, 1, 1, 0} });
    //solution({ {0, 1, 1, 1}, {1, 1, 1, 0} });
    solution({{0, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {0, 0, 1, 0}} );
}
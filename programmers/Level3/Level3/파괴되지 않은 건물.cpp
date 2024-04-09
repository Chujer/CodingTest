#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;

    vector<vector<int>> temp(board.size()+1, vector<int>(board[0].size()+1));

    for (int i = 0; i < skill.size(); i++)
    {
        int type = skill[i][0];
        int y1 = skill[i][1];
        int x1 = skill[i][2];
        int y2 = skill[i][3];
        int x2 = skill[i][4];
        int degree = skill[i][5];

        if (type == 1)
        {
            temp[y1][x1] -= degree;
            temp[y1][x2 + 1] += degree;
            temp[y2 + 1][x1] += degree;
            temp[y2 + 1][x2 + 1] -= degree;
        }
        else
        {
            temp[y1][x1] += degree;
            temp[y1][x2 + 1] -= degree;
            temp[y2 + 1][x1] -= degree;
            temp[y2 + 1][x2 + 1] += degree;
        }
    }

    for (int i = 0; i < temp.size(); i++)
    {
        for (int j = 1; j < temp[i].size(); j++)
        {
            temp[i][j] += temp[i][j - 1];
        }
    }
    for (int i = 1; i < temp.size(); i++)
    {
        for (int j = 0; j < temp[i].size(); j++)
        {
            temp[i][j] += temp[i - 1][j];
        }
    }
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] + temp[i][j] > 0)
                answer++;
        }
    }

    return answer;
}

int main()
{
    solution({ {5, 5, 5, 5, 5} ,{5, 5, 5, 5, 5},{5, 5, 5, 5, 5},{5, 5, 5, 5, 5} }, { {1, 0, 0, 3, 4, 4} ,{1, 2, 0, 2, 3, 2},{2, 1, 0, 3, 1, 2},{1, 0, 1, 3, 3, 1} });
}
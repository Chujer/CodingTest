#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;

    if (n == 1)
        return { 1 };

    vector<vector<int>> temp(n + 1, vector<int>(n + 1, 0));
    enum Direction { LD = 0, RIGHT = 1, LU = 2 };

    int x = 2;
    int dir[3][2] = { {0,1}, {1,0}, {-1,-1} };
    Direction curDir = LD;

    int curX = 1;
    int curY = 1;

    temp[1][1] = 1;

    while(true)
    {
        curX += dir[curDir][0];
        curY += dir[curDir][1];
        if (temp[curY][curX] != 0)
            break;
        temp[curY][curX] = x;


        int nextDir[2] = { (curX + dir[curDir][0]),  (curY + dir[curDir][1]) };
        if (nextDir[0] <= 0 || nextDir[1] <= 0 || nextDir[1] >= temp.size() || nextDir[0] > nextDir[1] || temp[nextDir[1]][nextDir[0]] != 0)
        {
            switch (curDir)
            {
            case LD:
                curDir = RIGHT;
                break;
            case RIGHT:
                curDir = LU;
                break;
            case LU:
                curDir = LD;
                break;
            default:
                break;
            }
        }

        x++;
    }

    for (int i = 1; i < temp.size(); i++)
    {
        for (int j = 1; j < temp.size(); j++)
        {
            if(temp[i][j] != 0)
                answer.push_back(temp[i][j]);
        }
    }
    return answer;
}

int main()
{
    solution(5);
}
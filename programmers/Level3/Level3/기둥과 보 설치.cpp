#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> board;
vector<vector<int>> pillar;
vector<vector<int>> beam;

bool Cmd(vector<int> a, vector<int>b)
{
    if (a[0] == b[0])
    {
        return a[1] < b[1];
    }
    else
        return a[0] < b[0];
}

bool Build(int type, int x, int y)
{
    if (type == 0)
    {
        if (y == 0)
        {
            board[y][x] = 0;
            pillar.push_back({ x,y, 1 });
            return true;
        }

        for (int i = 0; i < pillar.size(); i++)
        {
            if (pillar[i][0] == x && pillar[i][1] == y - 1)
            {
                if (pillar[i][2] == 1)
                {
                    board[y][x] = 0;
                    pillar.push_back({ x,y, 1 });
                    return true;
                }
            }
        }
        for (int i = 0; i < beam.size(); i++)
        {
            if (beam[i][1] == y)
            {
                if (beam[i][0] == x - 1 || beam[i][0] == x + 1)
                {
                    if (beam[i][2] == 1)
                    {
                        board[y][x] = 0;
                        pillar.push_back({ x,y, 1 });
                        return true;
                    }
                }
            }
        }
    }
    else if(type == 1)
    {
        if (y == 0)
        {
            board[y][x] = 1;
            beam.push_back({ x,y, 1 });
            return true;
        }

        for (int i = 0; i < pillar.size(); i++)
        {
            if (pillar[i][1] == y - 1)
            {
                if (pillar[i][0] == x || pillar[i][0] == x + 1)
                {
                    if (pillar[i][2] == 1)
                    {
                        board[y][x] = 1;
                        beam.push_back({ x,y, 1 });
                        return true;
                    }
                }
            }
        }
        for (int i = 0; i < beam.size(); i++)
        {
            if (beam[i][1] == y)
            {
                if (beam[i][0] == x - 1 || beam[i][0] == x + 1)
                {
                    if (beam[i][2] == 1)
                    {
                        board[y][x] = 1;
                        beam.push_back({ x, y, 1 });
                        return true;
                    }
                }
            }
        }
    }
    if (type == 2)
        return true;
    return false;
}

void Remove(int type, int x, int y)
{
    int dirX[3] = {-1,0,1};
    int dirY[3] = {-1,0,1};
    if (x == 1 && y == 1)
        int a = 0;
    
    int index;
    if (type == 0)
    {
        for (int i = 0; i < pillar.size(); i++)
        {
            if (pillar[i][0] == x && pillar[i][1] == y)
            {
                pillar[i][2] = 0;
                index = i;
            }
        }
    }
    else if (type == 1)
    {
        for (int i = 0; i < beam.size(); i++)
        {
            if (beam[i][0] == x && beam[i][1] == y)
            {
                beam[i][2] = 0;
                index = i;
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int tempX = x + dirX[j];
            int tempY = y + dirY[i];

            if (tempX < 0 || tempY < 0)
                continue;
            if (tempX >= board.size() || tempY >= board.size())
                continue;

            if (!Build(board[tempY][tempX], tempX, tempY))
            {
                if (type == 0)
                {
                    pillar[index][2] = 1;
                    return;
                }
                else
                {
                    beam[index][2] = 1;
                    return;
                }
            }
        }
    }
    board[y][x] = 2;
    
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

    board.resize(n+1, vector<int>(n+1, 2));


    for (int i = 0; i < build_frame.size(); i++)
    {
        if (build_frame[i][3] == 1)
            Build(build_frame[i][2], build_frame[i][0], build_frame[i][1]);
        if (build_frame[i][3] == 0)
            Remove(build_frame[i][2], build_frame[i][0], build_frame[i][1]);
    }
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            if (board[i][j] != 2)
                answer.push_back({ j,i,board[i][j] });
        }
    }

    sort(answer.begin(), answer.end(),Cmd);

    return answer;
}

int main()
{
    solution(5, {{0, 0, 0, 1}, {2, 0, 0, 1}, {4, 0, 0, 1}, {0, 1, 1, 1}, {1, 1, 1, 1}, {2, 1, 1, 1}, {3, 1, 1, 1}, {2, 0, 0, 0}, {1, 1, 1, 0}, {2, 2, 0, 1}} );
}
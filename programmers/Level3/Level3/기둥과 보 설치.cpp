#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(const vector<int>& a, const vector<int>& b) 
{
    if (a[0] < b[0]) 
        return true;
    if (a[0] == b[0] && a[1] < b[1]) 
        return true;
    if (a[0] == b[0] && a[1] == b[1]) 
        return a[2] < b[2];

    return false;
}

bool canExist(vector<vector<int>>& pillar, vector<vector<int>>& roof, int x, int y, int type) 
{
    if (type == 0) 
    { // ���
        if (y == 0) 
            return true; // �ٴ� ��
        if (y > 0 && pillar[y - 1][x] == 1) 
            return true; // �ٸ� ��� ��
        if (roof[y][x] == 1) 
            return true; // ���� ���� �� �κ� ��
        if (x > 0 && roof[y][x - 1] == 1) 
            return true; // ���� �ٸ� ���� �� �κ� ��
    }
    else if (type == 1) 
    { // ��
        if (pillar[y - 1][x] == 1 || pillar[y - 1][x + 1] == 1) 
            return true; // ���� �� �κ��� ��� ��
        if (x > 0 && x < pillar[0].size() - 1 && roof[y][x - 1] == 1 && roof[y][x + 1] == 1) 
            return true; // ���� �� �κ��� �ٸ� ���� ���ÿ� ����
    }
    return false;
}

bool canRemove(vector<vector<int>>& pillar, vector<vector<int>>& roof, int n) 
{
    for (int x = 0; x <= n; x++) 
    {
        for (int y = 0; y <= n; y++) 
        {
            if (pillar[y][x] == 1 && !canExist(pillar, roof, x, y, 0)) 
                return false; // ��� ���� ��������
            if (roof[y][x] == 1 && !canExist(pillar, roof, x, y, 1)) 
                return false; // �� ���� ��������
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) 
{
    vector<vector<int>> answer;
    vector<vector<int>> pillar(n + 1, vector<int>(n + 1, 0)), roof(n + 1, vector<int>(n + 1, 0));

    for (auto& frame : build_frame) 
    {
        int x = frame[0], y = frame[1], type = frame[2], action = frame[3];

        if (action == 1) 
        { // ��ġ
            if (canExist(pillar, roof, x, y, type)) 
            {
                if (type == 0) 
                    pillar[y][x] = 1;
                else 
                    roof[y][x] = 1;
            }
        }
        else 
        { // ����
            if (type == 0) 
                pillar[y][x] = 0;
            else 
                roof[y][x] = 0;

            if (!canRemove(pillar, roof, n)) 
            {
                if (type == 0) 
                    pillar[y][x] = 1;
                else 
                    roof[y][x] = 1;
            }
        }
    }

    for (int x = 0; x <= n; x++) 
    {
        for (int y = 0; y <= n; y++) 
        {
            if (pillar[y][x] == 1) 
                answer.push_back({ x, y, 0 });
            if (roof[y][x] == 1) 
                answer.push_back({ x, y, 1 });
        }
    }

    sort(answer.begin(), answer.end(), cmp);
    return answer;
}


int main()
{
     //solution(5, { {1,0,0,1} ,{1,1,1,1},{2,1,0,1},{2,2,1,1},{5,0,0,1},{5,1,0,1},{4,2,1,1},{3,2,1,1} } );
    //solution(5, { {0,0,0,1} ,{2,0,0,1},{4,0,0,1},{0,1,1,1},{1,1,1,1},{2,1,1,1},{3,1,1,1},{2,0,0,0},{1,1,1,0},{2,2,0,1} } );
    solution(5, { {3,0,0,1}, {2,1,1,1},{0,0,0,1}, {0,1,1,1},{1,1,1,1},{2,1,0,1},{2,2,1,1} });
}
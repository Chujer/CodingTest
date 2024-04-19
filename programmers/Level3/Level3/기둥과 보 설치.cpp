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
    { // 기둥
        if (y == 0) 
            return true; // 바닥 위
        if (y > 0 && pillar[y - 1][x] == 1) 
            return true; // 다른 기둥 위
        if (roof[y][x] == 1) 
            return true; // 보의 한쪽 끝 부분 위
        if (x > 0 && roof[y][x - 1] == 1) 
            return true; // 보의 다른 한쪽 끝 부분 위
    }
    else if (type == 1) 
    { // 보
        if (pillar[y - 1][x] == 1 || pillar[y - 1][x + 1] == 1) 
            return true; // 한쪽 끝 부분이 기둥 위
        if (x > 0 && x < pillar[0].size() - 1 && roof[y][x - 1] == 1 && roof[y][x + 1] == 1) 
            return true; // 양쪽 끝 부분이 다른 보와 동시에 연결
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
                return false; // 기둥 삭제 가능한지
            if (roof[y][x] == 1 && !canExist(pillar, roof, x, y, 1)) 
                return false; // 보 삭제 가능한지
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
        { // 설치
            if (canExist(pillar, roof, x, y, type)) 
            {
                if (type == 0) 
                    pillar[y][x] = 1;
                else 
                    roof[y][x] = 1;
            }
        }
        else 
        { // 삭제
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
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(vector<int> a, vector<int> b)
{
    if (a[0] < b[0])
        return true;
    if (a[0] == b[0])
        return b[1] > a[1];

    return false;
}
vector<vector<int>> pillar;
vector<vector<int>> roof;

bool Search(int type, int x, int y)
{
    if (type == 0) // ���
    {
        if (y == 0)
            return true;
        else
        {
            if (pillar[y - 1][x] == 1 || roof[y][x - 1] == 1 || roof[y][x + 1] == 1)
                return true;
            else 
                return false;
        }
    }
    else
    {
        if (pillar[y - 1][x] == 1 || pillar[y - 1][x + 1] == 1)
            return true;
        else if (roof[y][x - 1] == 1 && roof[y][x + 1] == 1)
            return true;
        else
            return false;
    }
}

bool removeSearch(int type, int x, int y)
{
    if (type == 0)  ///���
    {
        if (pillar[y + 1][x] == 1 && roof[y + 1][x - 1] == 0 && roof[y + 1][x + 1] == 0)
            return false;
        if (roof[y + 1][x] == 1 && pillar[y][x + 1] == 0 && (roof[y + 1][x - 1] == 0 || roof[y + 1][x + 1] == 0))
            return false;
        if (roof[y + 1][x - 1] == 1 && pillar[y][x - 1] == 0 &&  (roof[y + 1][x - 2] == 0 || roof[y + 1][x] == 0))
            return false;
        
        return true;
    }
    else
    {
        //�� ���ʿ� ���� �ִ°�� && ( ���� ���� �����ؿ� ����� ���� �Ǿ� ���� �ʰ� ���� �� �����ؿ� ����̾�����)
        if (x > 0 && roof[y][x - 1] == 1 && (pillar[y - 1][x - 1] == 0 && pillar[y - 1][x] == 0))
            return false;
        //�� �����ʿ� ���� �ִ°�� && ������ �� ���ʹؿ� ����� ����, �����ؿ��� ����� ���ٸ�
        if (x < roof[y].size() && roof[y][x + 1] == 1 && (pillar[y - 1][x + 1] == 0 && pillar[y - 1][x + 2] == 0))
            return false;
        //�� �������� ����� �ִ� ��� && ��� ���� �ؿ� ���� ����, �ؿ� ����� ���ٸ�
        if (pillar[y][x] == 1 && roof[y][x - 1] == 0 && pillar[y - 1][x] == 0)
            return false;
        //�� �������� ����� �ִ� ��� && ��� ���� �ؿ� ���� ����, �ؿ� ����� ���ٸ�
        if (pillar[y][x + 1] == 1 && roof[y][x + 1] == 0 && pillar[y - 1][x + 1] == 0)
            return false;
        
        return true;
    }
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

    pillar.resize(n + 1, vector<int>(n + 1));
    roof.resize(n + 1, vector<int>(n + 1));


    for (int i = 0; i < build_frame.size(); i++)
    {
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        bool isRoof = build_frame[i][2];
        bool isDelete = !build_frame[i][3];

        if (isDelete)
        {
            if (isRoof)
            {
                if (removeSearch(isRoof, x, y))
                {

                    roof[y][x] = 0;
                }
            }
            else
            {
                if (removeSearch(isRoof, x, y))
                     pillar[y][x] = 0;
            }
        }
        else
        {
            if (isRoof)
            {
                if (Search(isRoof, x, y))
                {
                    roof[y][x] = 1;
                }
            }
            else
            {
                if (Search(isRoof, x, y))
                {
                    pillar[y][x] = 1;
                }
            }
        }
    }

    int x = 0;
    int y = 0;
    for (int j = 0; j < pillar[0].size(); j++)
    {
        if (pillar[0][j] == 1)
        {
            x = j;
            break;
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (pillar[i][j] == 1)
                answer.push_back({ j,i,0 });
            if (roof[i][j] == 1)
                answer.push_back({ j,i,1 });
        }
    }
    sort(answer.begin(), answer.end(), cmp);

    return answer;
}

int main()
{
     //solution(5, { {1,0,0,1} ,{1,1,1,1},{2,1,0,1},{2,2,1,1},{5,0,0,1},{5,1,0,1},{4,2,1,1},{3,2,1,1} } );
    solution(5, { {0,0,0,1} ,{2,0,0,1},{4,0,0,1},{0,1,1,1},{1,1,1,1},{2,1,1,1},{3,1,1,1},{2,0,0,0},{1,1,1,0},{2,2,0,1} } );
    //solution(3, { {0,0,0,1}, {0,1,1,1}, {3,0,0,1} , {2,1,1,1}, {1,1,1,1}, {1,1,1,0} });
}
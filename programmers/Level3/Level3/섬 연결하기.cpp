#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

//가중치, 시작지점, 끝지점

bool cmd(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
}

struct Node
{
    int index;
};
vector<Node> datas;

int find(int index)
{
    if (index != datas[index].index)
        datas[index].index = find(datas[index].index);

    return datas[index].index;
}

bool merge(int a, int b)
{
    int x = find(a);
    int y = find(b);

    if (x != y)
    {
        if (x < y)
            datas[x].index = y;
        else
            datas[y].index = x;

        return true;
    }
     return false;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    //시작지점0 도착지점 1 가중치2 

    sort(costs.begin(), costs.end(), cmd);
    for (int i = 0; i < n; i++)
    {
        Node temp;
        temp.index = i;
        datas.push_back(temp);
    }

    for (int i = 0; i < costs.size(); i++)
    {
        if (merge(costs[i][0], costs[i][1]))
            answer += costs[i][2];
    }
    return answer;
}

int main()
{
    solution(4, { {1,3,2},{1,2,3}, {2,3,3},{0,3,4},{0,1,3} });
}

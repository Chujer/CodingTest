#include <string>
#include <vector>
#include <map>

using namespace std;

vector<pair<int, map<int,int>>> datas;
void DFS(vector<int> check,int curIndex, int& count)
{
    
    for (int i = 0; i < datas[curIndex].second.size(); i++)
    {
       // count +=        datas[curIndex].second[i];
    }
    
}

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    
    datas.resize(n + 1);

    for (int i = 0; i < wires.size(); i++)
    {
        datas[wires[i][0]].second[wires[i][1]] = 1;
        datas[wires[i][1]].second[wires[i][0]] = 1;
    }

    for (int i = 1; i < datas.size(); i++)
    {
        for (int j = 0; j < datas[i].second.size(); j++)
        {
           datas[i].second[datas[i].second[j]] = 1;
        }
        datas[i].first = datas[i].second.size() - 2;
    }
    return answer;
}

int main()
{
    //solution(9, { {1,3} ,{2,3},{3,4},{4,5},{4,6},{4,7},{7,8},{7,9} });
    solution(4, { {1,2},{2,3},{3,4} });
}
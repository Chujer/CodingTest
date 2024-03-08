#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

priority_queue<string> que;
int ticketsCount = 0;
vector<string> temp;

void DFS(map<string, vector<string>>& nodes, string pos, map<string, map<string,int>>& check, vector<vector<string>>& datas)
{
    temp.push_back(pos);
    if (temp.size() == ticketsCount+1)
        datas.push_back(temp);

    if (datas.size() > 0)
        return;
    for (int i = 0; i < nodes[pos].size(); i++)
    {
        if (check[pos][nodes[pos][i]] <= 0)
            continue;

        check[pos][nodes[pos][i]] = check[pos][nodes[pos][i]] - 1;

        DFS(nodes, nodes[pos][i], check, datas);   
        temp.pop_back();
        check[pos][nodes[pos][i]] = check[pos][nodes[pos][i]] + 1;
    }
}


vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;

    map<string, vector<string>> nodes;
    vector<string> data;
    map<string, map<string,int>> check;

    for (int i = 0; i < tickets.size(); i++)
    {
        nodes[tickets[i][0]].push_back(tickets[i][1]);
        check[tickets[i][0]][tickets[i][1]]++;
        ticketsCount++;
    }
    
    vector<vector<string>> datas;
    vector<string> temp;

    for (auto& n : nodes)
    {
        sort(n.second.begin(), n.second.end());
    }

    DFS(nodes, "ICN", check, datas);

    return datas[0];
}

int main()
{
    solution({ {"ICN", "SFO"} ,{"ICN", "ATL"},{"SFO", "ATL"},{"ATL", "ICN"},{"ATL","SFO"} });
}
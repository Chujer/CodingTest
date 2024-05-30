#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void DFS(vector<string> tt, string curString, int index, int score, map<string, vector<int>>& data)
{
    if (index >= tt.size())
    {
        data[curString].push_back(score);
    }
    else
    {
        DFS(tt, curString + tt[index], index + 1, score, data);
        DFS(tt, curString + "-", index + 1, score, data);
    }
}

vector<int> solution(vector<string> info, vector<string> query) {


    map<string, vector<int>> data;

    for (int i = 0; i < info.size(); i++)
    {
        string temp = "";
        vector<string> tt;

        while (info[i].find(" ") != string::npos)
        {
            string s = info[i].substr(0, info[i].find(" "));
            info[i] = info[i].substr(info[i].find(" ") + 1);

            tt.push_back(s);
        }

        DFS(tt, "", 0, stoi(info[i]), data);
    }

    for (auto& d : data)
        sort(d.second.begin(), d.second.end());

    vector<int> answer;
    for (int i = 0; i < query.size(); i++)
    {
        vector<string> infoData;

        string temp = "";
        while (query[i].find(" ") != string::npos)
        {
            string s = query[i].substr(0, query[i].find(" "));
            query[i] = query[i].substr(query[i].find(" ") + 1);

            if (s == "and")
            {
                continue;
            }
            temp += s;
        }
        //auto& a = data[temp];
        auto t = lower_bound(data[temp].begin(), data[temp].end(), stoi(query[i]));
        answer.push_back(data[temp].end() - t);
    }

    return answer;
}
int main()
{
    solution({ "java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50" }
    , { "java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150" });
}
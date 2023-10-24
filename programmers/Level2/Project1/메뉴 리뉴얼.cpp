#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
vector<map<string, int>> datas(11);

bool cmp(pair<string, int>& a, pair<string, int>& b)
{
    return a.second > b.second;
}

void DFS(string orders, vector<bool> check, string mix, int curPos,int size)
{
    mix += orders[curPos];
    check[curPos] = true;
    if (mix.size() == size)
    {
        datas[size][mix] += 1;
        return;
    }
    for (int i = curPos+1; i < orders.size(); i++)
    {
        if (check[i] == true)
            continue;
        DFS(orders,check, mix, i , size);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (int j = 0; j < orders.size(); j++)
    {
        sort(orders[j].begin(), orders[j].end());
    }

    for (int i = 0; i < course.size(); i++)
    {
        for (int j = 0; j < orders.size(); j++)
        {
            if (orders[j].size() < course[i])
                continue;

            for (int r = 0; r < orders[j].size(); r++)
            {
                string temp = "";
                vector<bool> check(orders[j].size(), false);
                DFS(orders[j], check, temp, r, course[i]);
            }
        }
    }

    for (int i = 0; i < course.size(); i++)
    {

        vector<pair<string,int>> temp(datas[course[i]].begin(), datas[course[i]].end());
        sort(temp.begin(), temp.end(), cmp);
        if (temp.empty())
            break;
        int max = temp.front().second;

        if (temp.front().second >= 2)
        {
            answer.push_back(temp.front().first);
            for (int j = 1; j < temp.size(); j++)
            {
                if (temp[j].second < max)
                    break;
                answer.push_back(temp[j].first);
            }
        }
    }
    sort(answer.begin(), answer.end());

    return answer;
}

int main()
{
    solution({ "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" }, { 2,3,4 });
}
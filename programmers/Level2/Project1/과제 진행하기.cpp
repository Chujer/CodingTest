#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int Converter(string time)
{
    string h = time.substr(0, 2);
    time = time.substr(3, 2);

    return stoi(h) * 60 + stoi(time);
}

bool cmp(vector<string> a, vector<string> b)
{
    return Converter(a[1]) < Converter(b[1]);
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;

    stack<pair<string, int>> data;

    sort(plans.begin(), plans.end(), cmp);

    for (int i = 0; i < plans.size(); i++)
    {
        int startTime = Converter(plans[i][1]);
        int playTime = stoi(plans[i][2]);
        if (i < plans.size() - 1)
        {
            int nextTime = Converter(plans[i + 1][1]);
            if (startTime + playTime <= nextTime)   //다음 시작시간보다 과제가 먼저 끝나는 경우
            {
                answer.push_back(plans[i][0]);
                int galTime = (nextTime - startTime) - playTime;    //남는 시간
                
                while (galTime > 0 && !data.empty())
                {
                    if (data.top().second - galTime <= 0)
                    {
                        answer.push_back(data.top().first);
                        galTime = galTime - data.top().second;
                        data.pop();
                    }
                    else
                    {
                        data.top().second -= galTime;
                        galTime = 0;
                    }
                }
            }
            else
                data.push({ plans[i][0], playTime - (nextTime - startTime) });
        }
        else
            answer.push_back(plans[i][0]);
    }

    while (!data.empty())
    {
        answer.push_back(data.top().first);
        data.pop();
    }
    return answer;
}
int main()
{
    solution({ {"science", "12:40", "50"} ,{"music", "12:20", "40"},{"history", "14:00", "30"},{"computer", "12:30", "100"} });
}
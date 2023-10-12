#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";

    vector<vector<pair<int, int>>> bus(n, vector<pair<int, int>>(m, { 540, false}));

    deque<int> timeT(timetable.size());
    for (int i = 0; i < timetable.size(); i++)
    {
        int h, m;
        h = stoi( timetable[i].substr(0,2)) * 60;
        m = stoi( timetable[i].substr(3,2));
        timeT[i] = h + m;
    }

    sort(timeT.begin(), timeT.end());

    for (int i = 0; i < n; i++)
    {
        int temp = 540 + (t * i);
        for (int j = 0; j < bus[i].size(); j++)
        {
            bus[i][j].first = temp;
            if (!timeT.empty() && bus[i][j].first>= timeT.front())
            {
                bus[i][j].first = timeT.front();
                bus[i][j].second = true;
                timeT.pop_front();
            }
            /*else
                break;*/
        }
    }
    int temp;
    if (bus.back().back().second == true)
    {
        temp = bus.back().back().first - 1;
    }
    else
        temp = bus.back().back().first;


    answer += to_string((temp / 60)) + ":";
    if (answer.size() <= 2)
        answer = "0" + answer;
    if (temp % 60 < 10)
        answer += "0" + to_string(temp % 60);
    else
        answer +=  to_string(temp % 60);

    return answer;
}
int main()
{
    solution(2, 10, 3, { "09:05","09:09","09:13" });
}
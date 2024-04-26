#include <string>
#include <vector>
#include<algorithm>
#include <map>

using namespace std;

int Converter(string time)
{
    int second = 0;
    int factor = 3600; // 처음에는 시간을 초로 변환, 따라서 3600을 곱함
    size_t pos = 0;
    while ((pos = time.find(":")) != string::npos)
    {
        second += stol(time.substr(0, pos)) * factor;
        time = time.substr(pos + 1);
        factor /= 60; // 다음은 분, 그 다음은 초를 의미, 따라서 60으로 나눔
    }
    second += stol(time) * factor; // 마지막 남은 초 처리
    return second;
}

string ConvertString(int n)
{
    string temp;

    temp += n / 3600 < 10 ? "0" : "";
    temp += to_string(n / 3600) + ":";
    n = n % 3600;
    temp += n / 60 < 10 ? "0" : "";
    temp += to_string(n / 60) + ":";
    n = n % 60;
    temp += n < 10 ? "0" : "";
    temp += to_string(n);

    return temp;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";

    int playTime = Converter(play_time);
    int advTime = Converter(adv_time);
    vector<long long> board(playTime+1);
    string test = ConvertString(advTime);
    vector<pair<int, int>> logTimes;

    for (int i = 0; i < logs.size(); i++)
    {
        int start = Converter(logs[i].substr(0, 8));
        int end = Converter(logs[i].substr(logs[i].find("-") + 1, logs[i].size()));

        board[start]++;
        board[end]--;
    }

    sort(logTimes.begin(), logTimes.end());

    long long maxTime = -1;
    int index = 0;

    for (int i = 1; i <= playTime; i++)
    {
        board[i] += board[i - 1];
    }
    for (int i = 1; i <= playTime; i++)
    {
        board[i] += board[i - 1];
    }
    for (int i = 0; i + advTime <= playTime; i++)
    {
        long long time = board[i + advTime - 1] - (i ? board[i - 1] : 0);
        if (time <= maxTime) 
            continue;
        
        maxTime = time;
        index = i;
    }
    
    answer = ConvertString(index);
    return answer;
}

int main()
{
    solution("99:59:59", "25:00:00", { "69:59:59-89:59:59", "01:00:00-21:00:00", "79:59:59-99:59:59", "11:00:00-31:00:00" });
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    vector<char> temps;
    sort(strings.begin(), strings.end());
    for (string str : strings)
    {
        temps.push_back(str[n]);
    }
    sort(temps.begin(), temps.end());
    temps.erase(unique(temps.begin(), temps.end()),temps.end());

    for (int i = 0; i < temps.size(); i++)
    {
        for (string str : strings)
        {
            if (str[n] == temps[i])
            {
                answer.push_back(str);
            }
        }
    }

    return answer;
}

/*
* 
* sort �Լ��� compare�� ���ص��� ���ڶ���.
* compare ���� true�� ������ ���� �켱������ �������� ���ĵȴ�.
    bool compare (string a, string b) {
        return a[i] == b[i] ? a < b : a[i] < b[i];
    }

    vector<string> solution(vector<string> strings, int n) {
        i = n;
        sort (strings.begin(), strings.end(), compare);
        return strings;
    }
*/

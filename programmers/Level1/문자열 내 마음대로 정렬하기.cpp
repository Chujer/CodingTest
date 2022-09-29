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
* sort 함수의 compare의 이해도가 모자랐다.
* compare 에서 true로 설정된 값이 우선적으로 앞쪽으로 정렬된다.
    bool compare (string a, string b) {
        return a[i] == b[i] ? a < b : a[i] < b[i];
    }

    vector<string> solution(vector<string> strings, int n) {
        i = n;
        sort (strings.begin(), strings.end(), compare);
        return strings;
    }
*/

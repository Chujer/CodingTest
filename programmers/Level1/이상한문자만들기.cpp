#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<string> temp;
    
    while (s.c_str() != "\0")
    {
        temp.push_back(s.substr(0, s.find(" ")));
        if (s.find(" ") == s.npos)
            break;
        s.erase(0,s.find(" ")+1);
    }

    for (string t : temp)
    {
        for (int i = 0; i < t.size(); i++)
        {
            if (i % 2 == 0)
            {
                if (t[i] > 96)
                    answer += t[i] - 32;
                else
                    answer += t[i];
            }
            else
            {
                if (t[i] < 91)
                    answer += t[i] + 32;
                else
                    answer += t[i];
            }
        }
        answer += " ";
    }
    answer.erase(answer.size()-1, 1);

    return answer;
}

/*
    include <ctype.h> : string에 포함되어있음
    toupper(int c) : 아스키표를 이용해 대문자인경우 소문자로 변경
    tolower(int c) : 아스키표를 이용해 소문자인경우 대문자로 변경

    toupper,tolower 모두 본인이 해당하는 문자가 아닐경우 그대로 반환한다.
*/
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";

    s[0] =  toupper(s[0]);
    string temp;
    while (true)
    {
        temp = s.substr(0, s.find(' '));
        for(char& t : temp)
           t = tolower(t);
        temp[0] = toupper(temp[0]);
        answer += temp;
        if (s.size() < temp.size() + 1)
            break;
        answer += ' ';
        s.erase(s.begin(), s.begin() + temp.size()+1);
   
    }
    


    return answer;
}

/*
* 어처피 필요한 문자는 문자앞에 공백이있으면 대문자로 바꿔주는 것이었다.
string solution(string s) {
    string answer = "";

    answer += toupper(s[0]);
    for (int i = 1; i < s.size(); i++)
        s[i - 1] == ' ' ? answer += toupper(s[i]) : answer += tolower(s[i]);

    return answer;
}
*/

int main()
{
    string s = "3people unFollowed me";

    solution(s);

    return 0;
}
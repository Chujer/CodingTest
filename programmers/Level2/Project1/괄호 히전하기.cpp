#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    string saveS = s;
    string data = s;

    string temp[3] = { "()","[]","{}" };

    for (int i = 0; i < s.length(); i++)
    {
        data = s.substr(0, i);
        s = s.substr(i,s.length());
        s += data;

        for (int i =0; i<3; i++)
        {
            if (s.find(temp[i]) != string::npos)
            {
                s.erase(s.find(temp[i]),2);
                i = -1;
            }
        }
        if (s.length() == 0)
            answer++;

        s = saveS;
    }

    return answer;
}

int main()
{
    solution("}{");

    return 0;
}
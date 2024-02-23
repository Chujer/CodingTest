#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.length();

    for (int i = 1; i <= s.size() / 2; i++) 
    {
        string compressed = "";
        string temp = s.substr(0, i);   //검사를 시작할 위치전의 문자열
        int count = 1;

        for (int j = i; j < s.size(); j += i) 
        {
            if (temp == s.substr(j, i))
            {
                count++;
            }
            else
            {
                if (count > 1) 
                {
                    compressed += to_string(count) + temp;
                }
                else 
                {
                    compressed += temp;
                }
                temp = s.substr(j, i);
                count = 1;
            }
        }

        if (count > 1) 
        {
            compressed += to_string(count) + temp;
        }
        else 
        {
            compressed += temp;
        }

        if (answer > compressed.size()) 
        {
            answer = compressed.size();
        }
    }

    return answer;
}

int main()
{
    solution("bababab");
}
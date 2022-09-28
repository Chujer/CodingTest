#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";

    int cSpace = 'a' - 'z';
    
    for (char temp : s)
    {
        if (temp == ' ')
        {
            answer += temp;
            continue;
        }

        for (int i = 0; i < n; i++)
        {
            temp++;
            if (temp == 'z'+1)
                temp = 'a';
            else if (temp == 'Z'+1)
                temp = 'A';
        }

        answer += temp;
    }

    return answer;
}

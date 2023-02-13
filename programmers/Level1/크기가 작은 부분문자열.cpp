#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    long answer = 0;
    long checkNum = stol(p);

    for (int i = 0; i < t.size() - (p.size()-1); i++)  
    {
        string temp = "";
        for (int j = 0; j < p.size(); j++)
        {
            temp += t[i + j];
        }
        if (stol(temp) <= checkNum)
            answer++;
    }

    return answer;
}

int main()
{
    solution("1234", "4");
}
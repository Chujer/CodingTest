#include <string>
#include <vector>

using namespace std;

void search(string& s, int & answer, bool & trigger)
{
    if (s.size() == 1)
    {
        answer++;
        trigger = true;
        return;
    }
    int yEqual = 1, nEqual = 0;
   
    for (int i = 1; i < s.size(); i++)
    {
        if (i == s.size() - 1)
        {
            answer++;
            trigger = true;
            return;
        }

        if (s[i] == s[0])
            yEqual++;
        else
            nEqual++;

        if (yEqual == nEqual)
        {
            answer++;
            s = s.substr(i+1);
            search(s, answer, trigger);

            if (trigger)
                return;
        }
    }
}

int solution(string s) {
    int answer = 0;
    bool trigger = false;
    search(s,answer, trigger);


    return answer;
}

int main()
{
    solution("abxabbacabddd");
}
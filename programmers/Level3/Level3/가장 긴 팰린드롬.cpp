#include <iostream>
#include <string>
#include <map>

using namespace std;

int solution(string s)
{
    int answer = 1;


    for (int i = 0; i < s.size(); i++)
    {
        int temp = 1;
        int head = i-1, tail = i+1;

        while (head >= 0 && s[head] == s[i])
        {
            head--;
            temp++;
        }

        while (tail < s.size() && s[tail] == s[i])
        {
            tail++;
            temp++;
        }

        while (head >= 0 && tail < s.size() && s[head] == s[tail])
        {
            temp += 2;
            head--;
            tail++;
        }
        if (temp > answer)
            answer = temp;
    }

    return answer;
}
int main()
{
    solution("aabbb");
}
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    int sine = 1;
    //answer = stoi(s);

    for (char a : s)
    {
        if (a == '-')
        {
            sine = -1;
            continue;
        }
        answer *= 10;
        answer += (a - '0');
    }

    answer *= sine;

    return answer;
}

int main()
{
    cout << solution("-8769548");
    return 0;
}
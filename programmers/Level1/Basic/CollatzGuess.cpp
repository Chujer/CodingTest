#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int num) {
    int answer = 0;

    long long temp;
    temp = num;

    if (num == 1)
        return 0;

    while (true)
    {
        if (temp % 2 == 0)
        {
            temp /= 2;
            answer++;
            cout << answer << " " << temp << endl;
        }
        else
        {
            temp = (temp * 3) + 1;
            answer++;
            cout << answer << " " << temp << endl;
        }

        if (answer == 486)
            int a = 0;

        if (answer > 500)
            return -1;

        if (temp == 1)
            return answer;
    }

    return answer;
}

int main()
{
    cout << solution(626331);
    return 0;
}
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(string dartResult) {
    int answer = 0;

    vector<int> point;
    vector<char> bonus(3);
    vector<char> option(3);

    vector<int> result(3);

    int count = -1;

    for (char c : dartResult)
    {
        if (c >= '0' && c <= '9')
        {
            count++;
            if (count > 0 && c == '0')
            {
                if (point[count - 1] == 1)
                {
                    point[count - 1] = 10;
                    count--;
                    continue;
                }
            }
            point.push_back((int)c - 48);
        }

        if (c == 'S' || c == 'D' || c == 'T')
            bonus[count] = c;

        if (c == '*' || c == '#')
            option[count] = c;
    }

    for (int i = 0; i < 3; i++)
    {
        result[i] = point[i];

        switch (bonus[i])
        {
        case 'D':
            result[i] = pow(result[i], 2);
            break;

        case 'T':
            result[i] = pow(result[i], 3);
            break;

        default:
            break;
        }

        switch (option[i])
        {
        case '*':
        {
            result[i] *= 2;
            if (i != 0)
            {
                result[i - 1] *= 2;
            }
            break;
        }
        case '#':
            result[i] *= -1;
            break;

        default:
            break;
        }
    }
    for (int r : result)
    {
        answer += r;
    }
    return answer;
}

int main()
{
    solution("1D2S0T");
    return 0;
}
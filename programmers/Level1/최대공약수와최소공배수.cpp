#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    answer.resize(2);
    vector<int> temp;

    for (int i = n; i >= 1; i--)
    {
        if (n % i == 0)
            temp.push_back(i);
    }

    for (int t : temp)
    {
        if (m % t == 0)
        {
            answer[0] = t;
            break;
        }
    }
    for (int i = answer[0]; true; i += answer[0])
    {
        if (i % n == 0 && i % m == 0)
        {
            answer[1] = i;
            break;
        }
    }

    return answer;
}
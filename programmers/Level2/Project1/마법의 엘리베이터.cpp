#include <string>
#include <vector>
#include <math.h>

using namespace std;


int solution(int storey) {
    int answer = 0;

    int max = pow(10, to_string(storey).size());

    vector<int> DP(max+1, 100000000);
    DP[0] = 0;
    for (int i = 1; i < max+1; i *= 10)
    {
        DP[i] = 1;
    }

    for (int i = 1; i < max + 1; i++)
    {
        for (int j = 1; j < max; j *= 10)
        {
            if(i + j <= max)
                DP[i + j] = min(DP[i + j], DP[i] + 1);
        }
    }
    for (int i = max; i >= 0; i--)
    {
        for (int j = 1; j < max; j *= 10)
        {
            if (i - j >= 0)
                DP[i - j] = min(DP[i - j], DP[i] + 1);
        }
    }
    for (int i = 1; i < max + 1; i++)
    {
        for (int j = 1; j < max; j *= 10)
        {
            if (i + j <= max)
                DP[i + j] = min(DP[i + j], DP[i] + 1);
        }
    }

    answer = DP[storey];

    return answer;
}
int main()
{
    solution(91);
}
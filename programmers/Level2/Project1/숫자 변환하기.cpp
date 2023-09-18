#include <string>
#include <vector>

using namespace std;

vector<int> DP;

int solution(int x, int y, int n) {
    int answer = 0;

    DP.resize(y + 1, 1000001);

    DP[x] = 0;
    if (y >= x + n)
        DP[x + n] = 1;
    if (y >= x * 2)
        DP[x * 2] = 1;
    if (y >= x * 3)
        DP[x * 3] = 1;

    for (int i = x; i <= y; i++)
    {
        if (i >= n && DP[i - n] != 1000001)
            DP[i] = min(DP[i], DP[i - n] + 1);

        if (i >= 2)
        {
            if (i % 2 == 0 && DP[i / 2] != 1000001)
                DP[i] = min(DP[i], DP[i / 2] + 1);

            if (i % 3 == 0 && DP[i / 3] != 1000001)
                DP[i] = min(DP[i], DP[i / 3] + 1);
        }
    }

    answer = DP[y];
    if (answer == 1000001)
        answer = -1;

    return answer;
}

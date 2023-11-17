#include <string>
#include <vector>


using namespace std;


int solution(int N, int number) {
    int answer = 0;

    vector<int> DP(32001, 50000);

    DP[0] = 2;
    DP[1] = 2;
    for (int i = 1; i <= 5; i++)
    {
        string indexStr = "";
        for (int j = 1; j <= i; j++)
        {
            indexStr += N + '0';
        }

        int index = stoi(indexStr);

        if (index >= DP.size())
            continue;
        int temp = indexStr.size();
        DP[index] = min(DP[index], temp);
        if (index + index < DP.size())
        {
            temp = indexStr.size() * 2;
            DP[index + index] = min(DP[index + index], temp);
        }

        if (index * index < DP.size())
        {
            temp = indexStr.size() * 2;
            DP[index * index] = min(DP[index * index], temp);
        }
    }

    for (int i = 2; i < DP.size(); i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (i + j < DP.size())
                DP[i + j] = min(DP[i + j], DP[i] + DP[j]);
            if (i - j >= 0)
                DP[i - j] = min(DP[i - j], DP[i] + DP[j]);
            if (i / j >= 0)
                DP[i / j] = min(DP[i / j], DP[i] + DP[j]);
            if (i* j < DP.size())
                DP[i * j] = min(DP[i * j], DP[i] + DP[j]);
        }
    }

    for (int i = DP.size() - 1; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            if (i + j < DP.size())
                DP[i + j] = min(DP[i + j], DP[i] + DP[j]);
            if (i - j >= 0)
                DP[i - j] = min(DP[i - j], DP[i] + DP[j]);
            if (i / j >= 0)
                DP[i / j] = min(DP[i / j], DP[i] + DP[j]);
            if (i * j < DP.size())
                DP[i * j] = min(DP[i * j], DP[i] + DP[j]);
        }
    }

    answer = DP[number];

    if (answer > 8)
        answer = -1;

    return answer;
}

int main()
{
    solution(1, 37);
}
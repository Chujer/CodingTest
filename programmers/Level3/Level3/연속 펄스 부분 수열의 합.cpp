#include <string>
#include <vector>

using namespace std;

long long P1[2] = { 1,-1 };
long long P2[2] = { -1,1 };

long long solution(vector<int> sequence) {
    long long answer = 0;

    vector<long long> DP1(sequence.size());
    vector<long long> DP2(sequence.size());
    vector<long> test(sequence.size());

    DP1[0] = sequence[0] * P1[0];
    DP2[0] = sequence[0] * P2[0];
    answer = max(DP1[0], DP2[0]);

    for (int i = 1; i < sequence.size(); i++)
    {
        DP1[i] = max(DP1[i - 1] + (sequence[i] * P1[i%2]), sequence[i] * P1[i % 2]);
        DP2[i] = max(DP2[i - 1] + (sequence[i] * P2[i%2]), sequence[i] * P2[i % 2]);
        long long temp = max(DP1[i], DP2[i]);
        answer = max(answer, temp);
    }
   


    return answer;
}

int main()
{
    solution({ 2, 3, -6, 1, 3, -1, 2, 4 });
}
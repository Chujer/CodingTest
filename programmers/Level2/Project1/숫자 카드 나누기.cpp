#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;

    bool isAnswerA = true;
    bool isAnswerB = true;

    sort(arrayA.begin(), arrayA.end());
    sort(arrayB.begin(), arrayB.end());

    int maxN = max(arrayA.front(), arrayB.front());

    for (int r = maxN; r >= 2; r--)
    {
        isAnswerA = true;
        isAnswerB = true;
        for (int j = 0; j < arrayA.size(); j++)
        {
            if (arrayB[j] % r == 0 || arrayA[j] % r != 0)
                isAnswerA = false;

            if (arrayA[j] % r == 0 || arrayB[j] % r != 0)
                isAnswerB = false;

            if (isAnswerA == false && isAnswerB == false)
                break;
        }

        if (isAnswerA == true || isAnswerB == true)
        {
            answer = max(r, answer);
            break;
        }
    }
    return answer;
}

int main()
{
    solution({ 14,35,119 }, { 18,30,102 });
}
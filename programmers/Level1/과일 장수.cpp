#include <stdio.h>
#include <stdbool.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    int maxBox = (score.size() / m) + 1;
    int curBox = 1;

    sort(score.begin(), score.end(), greater<int>());

    while (curBox < maxBox)
    {
        answer += score[curBox * m - 1] * m;
        curBox += 1;
    }


    return answer;
}

int main()
{
    int score[] = { 3,2,5,1,5 };
    cout<<endl<<solution(3, 4, { 1, 2, 3, 1, 2, 3, 1 });
}
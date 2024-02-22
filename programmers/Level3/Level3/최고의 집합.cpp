#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;

    if (n > s) {
        answer.push_back(-1);
        return answer;
    }

    for (int i = 0; i < n; i++) {
        answer.push_back(s / n);
    }

    for (int i = 0; i < s % n; i++) {
        answer[i]++;
    }

    sort(answer.begin(), answer.end());

    return answer;
}


int main()
{
    solution(3, 25);
}
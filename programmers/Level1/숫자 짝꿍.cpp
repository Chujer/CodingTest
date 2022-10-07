#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool high(char a, char b)
{
    return a > b;
}

string solution(string X, string Y) {
    string answer = "";
    string pairNum ="";

    unordered_map<char, int> xNum;

    for (char num : X)
    {
        xNum[num] += 1;
    }

    for (char num : Y)
    {
        if (xNum[num] > 0)
        {
            pairNum += num;
            xNum[num]--;
        }
    }

    sort(pairNum.begin(), pairNum.end(), high);

    answer = pairNum;

    if (pairNum == "")
    {
        answer += '-';
        answer += '1';
    }
    else if (answer[0] == '0')
        answer = '0';

    return answer;
}

int main()
{
    string x = "12321";
    string y = "42531";

    solution(x, y);
}
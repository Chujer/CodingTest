#include <string>
#include <vector>
#include<algorithm>

using namespace std;

bool FirstCmd(int a, int b)
{
    string aStr, bStr;
    aStr = to_string(a);
    bStr = to_string(b);

    if (aStr[0] > bStr[0])
        return true;
    else if(aStr[0] < bStr[0])
        return false;

    if (aStr.size() > 1 || bStr.size() > 1)
    {
        char lastA = aStr[0], lastB = bStr[0];
        for (int i = 1; i < 6; i++)
        {
            lastA = aStr[i % aStr.size()];
            lastB = bStr[i % bStr.size()];

            if (lastA > lastB)
                return true;
            else if (lastA < lastB)
                return false;
        }

    }

    return false;
}




string solution(vector<int> numbers) {
    string answer = "";

    string s;
    long long a = 0;

    sort(numbers.begin(), numbers.end(), FirstCmd);

    for (int i : numbers)
    {
        s += to_string(i);
        a += i;
    }
    if (a == 0)
        return "0";

    answer = s;
    
    return answer;
}

int main()
{
    solution({ 12,1213 });
}
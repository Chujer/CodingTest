    #include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    for (int i = 0; i < k; i++)
    {
        int index = 0;
        int curSize = number.size();
        for (int j = 0; j < number.size() - 1; j++)
        {
            if (number[index] > number[j + 1])
                index = j + 1;

            if (number[j] < number[j + 1])
            {
                number.erase(number.begin() + j);
                break;
            }
        }
        if (curSize == number.size())
            number.erase(number.begin() + index);
    }
    answer = number;

    return answer;
}

int main()
{
    solution("31", 1);
}


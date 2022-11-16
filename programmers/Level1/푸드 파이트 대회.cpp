#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string answer = "";

    string halfAnswer = "";

    for (int i =1; i<food.size(); i++)
    {
        int temp = food[i] / 2;
        for (int j = 0; j < temp; j++)
        {
            halfAnswer += to_string(i);
        }
    }
    answer = halfAnswer;
    reverse(halfAnswer.begin(), halfAnswer.end());
    answer += "0" + halfAnswer;

    return answer;
}

int main()
{
    solution({ 1, 3, 4, 6 });
    return 0;
}
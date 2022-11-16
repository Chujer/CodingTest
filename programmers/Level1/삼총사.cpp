#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;

    for (int i = 0; i < number.size(); i++)
    {
        for (int j = i + 1; j < number.size(); j++)
        {
            for (int r = j + 1; r < number.size(); r++)
            {
                if (number[i] + number[j] + number[r] == 0)
                    answer++;
            }
        }
    }

    return answer;
}

int main()
{
    solution({ -2, 3, 0, 2, -5 });
    return 0;
}
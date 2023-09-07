#include <string>
#include <vector>
#include <deque>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    vector<int> data(numbers.size());
    int max = 0;

    data.back() = -1;

    for (int i = numbers.size() - 2; i >= 0; i--)
    {
        if (numbers[i] < numbers[i + 1])
            data[i] = i + 1;
        else
        {
            int index = i+1;
            while (true)
            {
                if (data[index] == -1)
                {
                    data[i] = -1;
                    break;
                }
                if (numbers[data[index]] > numbers[i])
                {
                    data[i] = data[index];
                    break;
                }

                index = data[index];
            }
        }
    }

    for (int i = 0; i < data.size(); i++)
    {
        if (data[i] == -1)
            answer.push_back(-1);
        else
            answer.push_back(numbers[data[i]]);
    }

    return answer;
}
int main()
{
    solution({ 9, 1, 5, 3, 6, 2 });
}
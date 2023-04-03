#include <string>
#include <vector>

using namespace std;

void DFS(vector<int> numbers, int index, bool isMinus, int target, int sum, int& answer)
{

    if (index == numbers.size())
    {
        return;
    }

    if (isMinus)
        sum += numbers[index];
    else
        sum -= numbers[index];


    if (index + 1 == numbers.size() && sum == target)
    {
        answer++;
        return;
    }

    DFS(numbers, index+1, true, target, sum, answer);
    DFS(numbers, index+1, false, target, sum, answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int sum = 0;
    int index = 0;
  
    DFS(numbers, index, true, target, sum, answer);
    DFS(numbers, index, false, target, sum, answer);

    return answer;
}


int main()
{
    int i = solution({ 1,1,1,1,1 }, 3);
    return 0;
}
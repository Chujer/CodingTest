#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int solution(vector<int> numbers) {
    int answer = -1;
    int temp = 45;
    /*sort(numbers.begin(), numbers.end());
    for (int i = 0; i < numbers.size(); i++)
    {
        temp -= numbers[i];
    }*/
    temp -= accumulate(numbers.begin(), numbers.end(), 0);

    answer = temp;


    return answer;
}
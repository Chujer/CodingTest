#include <map>
#include <vector>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;

    int count = nums.size() / 2;

    map<int, int> poke(nums.begin(), nums.end());

    if (poke.size() < count)
        answer = poke.size();
    else
        answer = count;

    return answer;
}

int main()
{
    solution({ 1,1,2,3,4,5 });
}
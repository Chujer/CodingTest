#include <vector>
#include <iostream>
#include <map>

using namespace std;

int solution(vector<int> nums)
{
    map<int, int> pNumCount;
    int count = nums.size()/2;
    int answer = 0;

    for (int i : nums)
    {
        pNumCount.insert(make_pair(i, 1));
    }

    
    answer = pNumCount.size();

    if (answer > count)
        answer = count;

    return answer;
}

int main()
{
    vector<int> num = { 3,1,2,3 };
    
    int a;

    a = solution(num);

    cout << a;

    return 0;
}
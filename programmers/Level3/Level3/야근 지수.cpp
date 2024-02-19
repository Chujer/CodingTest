#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    //for (int i = 0; i < n; i++)
    //{
    //    sort(works.begin(), works.end());
    //    if (works.empty())
    //        break;
    //    works.back()--;
    //    if (works.back() < 1)
    //        works.pop_back();
    //}
    //
    //for (int i = 0; i < works.size(); i++)
    //{
    //    answer += works[i] * works[i];
    //}

    //return answer;

    priority_queue<int, vector<int>, less<>> queue;

    for (int i = 0; i < works.size(); i++)
    {
        queue.push(works[i]);
    }
    for (int i = 0; i < n; i++)
    {
        int temp;

        if (queue.empty())
            break;
        
        temp = queue.top()-1;
        queue.pop();

        if(temp > 0)
            queue.push(temp);
    }

    while (!queue.empty())
    {
        answer += queue.top()* queue.top();
        queue.pop();
    }
    return answer;
}

int main()
{
    solution(3, {1,1});
}
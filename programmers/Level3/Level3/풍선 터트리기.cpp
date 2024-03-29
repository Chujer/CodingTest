#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> a) {
    int answer = a.size();

    int minLeft = 1000000000;
    priority_queue<int, vector<int>, less<>> que;

    for (int i = 0; i < a.size(); i++)
    {
        while(!que.empty() && a[i] < que.top())
        {
            answer--;
            que.pop();
        }
        if (a[i] < minLeft)
        {
            minLeft = a[i];
        }
        else
        {
            que.push(a[i]);
        }
    }

    return answer;
}

int main()
{
    solution({ -16, 27, 65, -2, 58, -92, -71, -68, -61, -33 });
}
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct  cmp
{
    bool operator()(vector<int> a, vector<int> b)
    {
        if (a[1] > b[1])
            return true;
        else
            return false;
    }
};

int solution(vector<vector<int>> jobs) {
    priority_queue<vector<int>, vector<vector<int>>, cmp> queue;
    int answer = 0;
    int j = 0, time = 0;
    sort(jobs.begin(), jobs.end());

    while (jobs.size() > j || !queue.empty())
    {
        if (jobs.size() > j && time >= jobs[j][0])
        {
            queue.push(jobs[j++]);
            continue;
        }
        if (!queue.empty())
        {
            time += queue.top()[1];
            answer += time - queue.top()[0];
            queue.pop();
        }
        else
            time = jobs[j][0];
    }

    return answer / jobs.size();
}

int main()
{
    solution({ {0,3},{1,9},{2,6} });
}
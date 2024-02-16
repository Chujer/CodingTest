#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;


    priority_queue<int, vector<int>, greater<>> min_queue;
    priority_queue<int, vector<int>, less<>> max_queue;
    unordered_map<int, int> data;

    for (int i = 0; i < operations.size(); i++)
    {
        if (operations[i][0] == 'I')
        {
            int temp = stoi(operations[i].substr(2, operations[i].size()));
            min_queue.push(temp);
            max_queue.push(temp);
            data[temp]++;
        }
        else if (operations[i][2] == '-')
        {
            while (!min_queue.empty() && data[min_queue.top()] <= 0)
            {
                min_queue.pop();
            }
            if (min_queue.empty())
                continue;
            data[min_queue.top()]--;
            min_queue.pop();

        }
        else
        {
            while (!max_queue.empty() && data[max_queue.top()] <= 0)
            {
                max_queue.pop();
            }
            if (max_queue.empty())
                continue;
            data[max_queue.top()]--;
            max_queue.pop();
        }
    }

    while (!min_queue.empty() && data[min_queue.top()] <= 0)
    {
        min_queue.pop();
    }
    while (!max_queue.empty() && data[max_queue.top()] <= 0)
    {
        max_queue.pop();
    }

    if (max_queue.empty())
        answer.push_back(0);
    else
        answer.push_back(max_queue.top());

    if (min_queue.empty())
        answer.push_back(0);
    else
        answer.push_back(min_queue.top());


    return answer;
}

int main()
{
    solution({ "I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1" });
}
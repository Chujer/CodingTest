#include <string>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    deque<int> bridge(bridge_length);
    queue<int> truck;

    for (int t : truck_weights)
    {
        truck.push(t);
    }
    vector<pair<int, int>> a;
    
    
    while (!truck.empty())
    {
        bridge.pop_back();
        bridge.push_front(0);
        if (bridge.front() == 0 && weight >= truck.front())
        {
            bridge[0] = (truck.front());
            weight -= truck.front();
            truck.pop();
        }
        else
        {
        }

        if (bridge.back() != 0)
            weight += bridge.back();
        answer++;
    }

    for (int i = 0; i < bridge.size(); i++)
    {
        if (bridge[i] != 0)
        {
            answer += bridge.size() - i;
            break;
        }
    }

    return answer;
}

int main()
{
    solution(100, 100, { 10,10,10,10,10,10,10,10,10,10 });
}
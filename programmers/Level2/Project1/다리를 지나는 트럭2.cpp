#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    queue<int> trucks;
    for (int i = 0; i < truck_weights.size(); i++)
    {
        trucks.push(truck_weights[i]);
    }
    
    deque<int> bridge(bridge_length);
    while(!trucks.empty())
    {
        bridge.pop_back();
        bridge.push_front(0);
        if(trucks.front() <= weight)
        {
            bridge[0] = trucks.front();
            weight -= trucks.front();
            trucks.pop();
        }
        if (bridge.back() > 0)
            weight += bridge.back();
        answer++;
    }

    for(int i = 0; i < bridge.size(); i++)
    {
        if (bridge[i] != 0)
        {
            answer += bridge_length - i;
            break;
        }
    }
    

    return answer;
}

int main()
{
    solution(100 , 100, {10,10,10,10,10,10,10,10,10,10});
}
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int day = 0;

    while (!progresses.empty())
    {
        if (progresses.front() >= 100)
        {
            int index = 0;
            for (int i = 0; progresses[i] >= 100; i++)
            {
                index++;
                if (index == progresses.size())
                    break;
            }
            progresses.erase(progresses.begin(), progresses.begin() + index);
            speeds.erase(speeds.begin(), speeds.begin() + index);
            answer.push_back(index);
        }

        for (int i = 0; i <progresses.size();i++)
        {
            progresses[i] = (progresses[i] >= 100) ? 100 : progresses[i] + speeds[i];
        }
        
    }

    return answer;
}

int main()
{
    solution({ 95,95,95,95 }, { 4,3,2,1 });
}
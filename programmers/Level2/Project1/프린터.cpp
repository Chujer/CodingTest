#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    deque<int> data;

    int count = 0;

    for(int p : priorities)
    {
        data.push_back(p);
    }

    while (true)
    {
        int index = 1;
        while (index <data.size())
        {
	        if (data[0 + index] > data.front())
	        {
	            while (data.front() < data[0 + index])
	            {
	                if (location == 0)
	                    location = data.size();
	                int temp = data.front();
	                data.pop_front();
	                data.push_back(temp);
                    index = 1;
                    location--;
	            }
	        }
	        else
	            index++;
	    }

        data.pop_front();
        location--;
        answer++;

        if (location < 0)
        {
            break;
        }
        count++;
    }    

    return answer;
}

int main()
{
    solution({ 2, 1, 3, 2 }, 2);
}
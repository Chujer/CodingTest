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
	                else if (count > location)
	                    location--;
	                int temp = data.front();
	                data.pop_front();
	                data.push_back(temp);
                    index = 0;
	            }
	        }
	        else
	            index++;
	    }

        data.pop_front();
        location--;
        answer++;

        if (location == 0)
        {
            break;
        }
        count++;
    }
    
   /* queue<int> data;
    for (int p : priorities)
    {
        if (!data.empty() && p > data.front())
        {
            while (data.front() < p)
            {
                if (location == 0)
                    location = data.size();
                else if (count > location)
                    location--;
                int temp = data.front();
                data.push(p);
                data.pop();
                data.push(temp);
            }
        }
        else
            data.push(p);
        count++;
    }
    
    answer = location;
    */

    

    return answer-1;
}

int main()
{
    solution({ 2, 1, 3, 2 }, 2);
}
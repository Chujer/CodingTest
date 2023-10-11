#include <string>
#include <vector>
#include <stack>

using namespace std;

void Check(vector<int> order, stack<int>& suv, int& answer, int& index)
{
    if (!suv.empty() && suv.top() == order[index])
    {
        answer++;
        suv.pop();
        index++;
        Check(order, suv, answer, index);
    }
}

int solution(vector<int> order) {

    int index = 0;
    stack<int> suv;
    int answer = 0;

    for (int i = 1; i <= order.size(); i++)
    {
        if (order[index] == i)
        {
            answer++;
            index++;
        }
        else
        {
            while (!suv.empty() && suv.top() != order[index])
            {
                answer++;
                suv.pop();
                index++;
               // Check(order, suv, answer, index);
            }
            suv.push(i);
            //Check(order, suv, answer, index);
        }
    }while (!suv.empty() && suv.top() != order[index])
    {
        answer++;
        suv.pop();
        index++;
    }

    return answer;
}

int main()
{
    solution({ 5, 4, 3, 2, 1 });
}
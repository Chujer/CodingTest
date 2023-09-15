#include <string>
#include <vector>
#include <map>

using namespace std;

int DP1[1000001];
int DP2[1000001];

int solution(vector<int> topping) {
    int answer = -1;

    map<int, int> temp;
    int count = 0;
    for (int i = 0; i < topping.size(); i++)
    {
        if (temp.find(topping[i]) == temp.end())
        {
            temp[topping[i]]++;
            count++;
            DP1[i + 1] = count;
        }
        else
            DP1[i+1] = DP1[i];
    }
    temp.clear();
    count = 0;
    for (int i = 1; i <= topping.size(); i++)
    {
        if (temp.find(topping[topping.size() - i]) == temp.end())
        {
            temp[topping[topping.size() - i]]++;
            count++;
            DP2[i] = count;
        }
        else
            DP2[i] = DP2[i - 1];
    }


    for (int i = 1; i <= topping.size(); i++)
    {
        if (DP1[i] == DP2[topping.size() - i])
            answer++;
    }

    if (answer < 0)
        return 0;
    answer++;

    return answer;
}

int main()
{
    solution({ 1,2,3,1,4 });
}
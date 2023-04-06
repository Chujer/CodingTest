#include <string>
#include <vector>
#include <map>

using namespace std;

bool Search(map<string, int> wantItem, vector<string> discount)
{
    for (int i = 0; i < discount.size(); i++)
    {
        if (wantItem.find(discount[i]) != wantItem.end())
        {
            wantItem[discount[i]]--;

            if (wantItem[discount[i]] == 0)
                wantItem.erase(discount[i]);
        }
        
        if (wantItem.empty())
            return true;
    }
    return false;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;

    map<string, int> wantItem;

    for (int i =0; i<want.size(); i++)
    {
        wantItem[want[i]] = number[i];
    }
    for (int i = 0; i < discount.size(); i++)
    {
        if (i + 10 > discount.size())
            break;

        vector<string> dis;
        dis.insert(dis.end(), discount.begin() + i, discount.begin() + 10 +i);

        if (Search(wantItem, dis))
        {
            answer++;
        }
    }

    return answer;
}

int main()
{
    int a =  solution({ "banana", "apple", "rice", "pork", "pot" }, { 3,2,2,2,1 }, { "chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana" });
    return 0;
}
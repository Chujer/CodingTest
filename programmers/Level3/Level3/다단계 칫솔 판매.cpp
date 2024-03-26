#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

void Plus(unordered_map<string, unordered_map<string, int>>& data,string seller, int money)
{
    int mm = money/10;
    money -= mm;
    if (data[seller].size() > 0)
    {
        for (auto& s : data[seller])
        {
            s.second += money;
            if (s.first == "-" || mm == 0)
                break;
            Plus(data, s.first, mm);
        }
    }
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;

    unordered_map<string, unordered_map<string,int>> data;

    for (int i = 0; i < enroll.size(); i++)
    {
        if (referral[i] == "-")
        {
            data[enroll[i]].insert({ "-", 0 });
        }
        else
        {
            data[enroll[i]].insert({ referral[i],0 });
        }
    }

    for (int i = 0; i < seller.size(); i++)
    {
        int m = amount[i] * 100;
        
        Plus(data, seller[i], m);
    }
    for (int i = 0; i < enroll.size(); i++)
    {
        for (auto& s : data[enroll[i]])
        {
            answer.push_back(s.second);
        }
    }

    return answer;
}

int main()
{
    solution({ "john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young" }, { "-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward" }
    , { "young", "john", "tod", "emily", "mary" }, { 12,4,2,5,10 });
}
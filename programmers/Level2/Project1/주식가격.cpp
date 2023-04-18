#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;

    for (int idx = 0; idx < prices.size(); ++idx) 
    { 
        int chk = 0;
        for (int i = idx + 1; i < prices.size(); ++i) 
        {
            chk++;
            if (prices[idx] > prices[i]) 
                break;
        }
        answer.push_back(chk); 
    }
    return answer;
}


int main()
{
    solution({1,2,3,2,1,3});

    return 0;
}
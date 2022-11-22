#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool big(pair<int,int> a, pair<int,int> b)
{
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> temp;
    map<int, int> count;
    s.erase(s.begin());
    s.pop_back();
    s.pop_back();

    while (s.size() != 0)
    {
        vector<int> data;
        string tempS = s.substr(s.find_first_of("{") + 1, s.find_first_of("}", 0) -1);
        while (tempS.size() != 0)
        {
            int tempI = stoi(tempS.substr(0,tempS.find(',')));
            data.push_back(tempI);
            if (tempS.find(',') == string::npos)
                break;
            tempS = tempS.substr(tempS.find(',')+1);
        }
        temp.push_back(data);
        if (s.find("}") == string::npos)
            break;
        s = s.substr(s.find("}")+2,s.npos);
    }

    for (vector<int> datas : temp)
    {
        for (int data : datas)
        {
            count[data]++;
        }
    }
    vector<pair<int, int>> tt(count.begin(), count.end());
    sort(tt.begin(), tt.end(), big);

    for (pair<int, int> t : tt)
    {
        answer.push_back(t.first);
    }

    return answer;
}

int main()
{
    solution("{{2,3},{2,3,1},{2,3,1,2},{2}}");
    return 0;
}
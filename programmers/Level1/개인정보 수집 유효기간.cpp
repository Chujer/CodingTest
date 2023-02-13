#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int daySum(string data)
{
    int baseYear = stoi(data.substr(0, data.find('.')));
    data = data.substr(data.find('.') + 1);
    int baseMonth = stoi(data.substr(0, data.find('.')));
    data = data.substr(data.find('.') + 1);
    int day = stoi(data.substr(0, data.find('.')));
    data = data.substr(data.find('.') + 1);

    int daySum = (baseYear * 12 * 28) + (baseMonth * 28) + (day);

    return daySum;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    map<string, int> baseTerms;
    
    int todaySum = daySum(today);

    for (int i = 0; i < terms.size(); i++)
    {
        pair<string, int> tempTerms;
        tempTerms.first = terms[i][0];
        terms[i] = terms[i].substr(2);
        tempTerms.second = stoi(terms[i]) * 28;
        baseTerms.insert(tempTerms);
    }

    for (int i = 0; i < privacies.size(); i++)
    {
        string tempterms = privacies[i].substr(privacies[i].find(" ")+1);
        privacies[i] = privacies[i].substr(0,privacies[i].find(" "));
        
        int thisDaySum = daySum(privacies[i]);
       
        if (thisDaySum + baseTerms[tempterms] <= todaySum)
        {
            int a = thisDaySum + baseTerms[tempterms];
            answer.push_back(i + 1);
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}

int main()
{
    solution("2020.01.01", { "Z 3", "D 5" }, { "2019.01.01 D", "2019.11.15 Z", "2019.08.02 D", "2019.07.01 D", "2018.12.28 Z" });
}


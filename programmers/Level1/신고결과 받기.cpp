#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    answer.resize(id_list.size());

    //id_list 플레이어 종류
    // report 신고한사람 신고당한사람
    //신고당한사람, 신고한사람, 횟수

    map<string, vector<string>> reportList;

    for (string re : report)
    {
        string reporter;        //신고한사람
        string man;             //신고 당한사람
        reporter = re.substr(0, re.find(" "));
        man = re.substr(re.find(" ")+1,re.size()-1);
        reportList[man].push_back(reporter);
        sort(reportList[man].begin(), reportList[man].end());
        reportList[man].erase(unique(reportList[man].begin(), reportList[man].end()), reportList[man].end());
    }

    for (int i = 0; i < id_list.size(); i++)
    {
        if (reportList[id_list[i]].size() >= k)
        {
            for (string reporter : reportList[id_list[i]])
            {
                answer[find(id_list.begin(), id_list.end(), reporter) - id_list.begin()]++;
            }
        }
    }

    return answer;
}

int main()
{
    vector<string> id_list = {  "muzi", "frodo","con", "ryan" };
    vector<string> report = { "ryan con", "muzi con", "ryan con", "ryan con" };
   /* vector<string> id_list = { "muzi", "frodo", "apeach", "neo" };
    vector<string> report = { "muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi" };*/

    solution(id_list, report, 2);
}
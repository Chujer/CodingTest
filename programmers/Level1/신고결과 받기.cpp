#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    answer.resize(id_list.size());

    //id_list �÷��̾� ����
    // report �Ű��ѻ�� �Ű���ѻ��
    //�Ű���ѻ��, �Ű��ѻ��, Ƚ��

    map<string, vector<string>> reportList;

    for (string re : report)
    {
        string reporter;        //�Ű��ѻ��
        string man;             //�Ű� ���ѻ��
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
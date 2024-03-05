#include <string>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    unordered_map<string, int> data;
    set<string> count(gems.begin(), gems.end());

    int Min, start = 0, end = 0;
    for (int i = 0; i < gems.size(); i++)
    {
        data[gems[i]]++;
        if (data.size() == count.size())
            break;
        end++;
    }
    Min = end - start;

    answer.push_back(start + 1);
    answer.push_back(end + 1);

    while (end < gems.size())
    {
        string temp = gems[start];  //���� ù ��
        data[temp]--;               //�����
        start++;                    //���� �� �̵�

        if (data[temp] == 0)        //�������� ���� ������ �ִٸ�
        {
            //���� �˻縦 �ϸ� ���� ������ ã���� ���� Ž��
            end++;                 
            for (; end < gems.size(); end++)    
            {
                data[gems[end]]++;
                if (temp == gems[end])
                    break;
            }
            if (end == gems.size()) 
                break;
        }
        if (Min > end - start)  //���� Ž���� ���� �� �۴ٸ� ���� ����
        {
            answer[0] = start + 1;
            answer[1] = end + 1;
            Min = end - start;
        }
    }


    return answer;
}

int main()
{
    solution({ "AA", "AB", "AC", "AA", "AC" });
}
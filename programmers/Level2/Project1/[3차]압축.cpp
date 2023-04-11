#include <string>
#include <vector>
#include <map>

/*
������ ������ w�� Ž��
w�� �ش��ϴ� ��ȣ�� ���, �Է¿��� w�� ����
ó������ ���� ���� ���ڰ� �ִٸ� (c), w+c�� �ش��ϴ� �ܾ ������ ���
*/

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<int, string> list;
    int count = 1;
    for (char i = 'A'; i < 'Z' + 1; i++)
    {
        string temp = "";
        temp += i;
        list[count] = i;
        count++;
    }

    while (!msg.empty())
    {
        for (auto iter = --list.end(); iter != --list.begin(); iter--)
        {
            pair<int, string> temp = *iter;
            string a = msg.substr(0, temp.second.size());

            if (temp.second == msg.substr(0, temp.second.size()))
            {
                answer.push_back(temp.first);
                string t = msg.substr(0, temp.second.size() + 1);
                list.insert(make_pair(count++, t));
                msg = msg.substr(temp.second.size(), msg.size());
                break;
            }
        }
    }
    return answer;
}

int main()
{
    solution("KAKAO");

    return 0;
}
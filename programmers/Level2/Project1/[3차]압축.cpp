#include <string>
#include <vector>
#include <map>

/*
사전에 만들어둔 w를 탐색
w에 해당하는 번호를 출력, 입력에서 w를 제거
처리되지 않은 다음 글자가 있다면 (c), w+c에 해당하는 단어를 사전에 등록
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
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/*
  Enter 접속, Leave 탈출, Change 변경
  데이터 쌓기
  아이디와 이름
  저장되는 이름
  ["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]	
  ["Prodo님이 들어왔습니다.", "Ryan님이 들어왔습니다.", "Prodo님이 나갔습니다.", "Prodo님이 들어왔습니다."]
*/
vector<string> solution(vector<string> record) {
    vector<string> answer;

    unordered_map<string, string> user;

    for (string s : record)
    {
        string InOut = s.substr(0, s.find(" "));
        s = s.substr(s.find(" ") + 1, s.size());

        string id = s.substr(0, s.find(" "));
        s = s.substr(s.find(" ") + 1, s.size());

        string name = s.substr(0, s.size());

        if(user.find(id) == user.end())
            user.insert(make_pair(id, name));

        if (InOut == "Change")
        {
            user[id] = name;
        }
        else if(InOut == "Enter" && user.find(id) != user.end())
            user[id] = name;

    }
    for (string s : record)
    {
        string InOut = s.substr(0, s.find(" "));
        s = s.substr(s.find(" ") + 1, s.size());

        string id = s.substr(0, s.find(" "));
        s = s.substr(s.find(" ") + 1, s.size());

        if (InOut == "Enter")
        {
            string temp = " 님이 들어왔습니다.";
            answer.push_back(user[id] + temp);
        }
        else if (InOut == "Leave")
        {
            string temp = " 님이 나갔습니다.";
            answer.push_back(user[id] + temp);
        }
    }

    return answer;
}

int main()
{
    solution({ "Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan" });
}
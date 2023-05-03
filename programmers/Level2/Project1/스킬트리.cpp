#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    unordered_map<char, char> skillProviso;

    for (int i = 1; i < skill.size(); i++)
    {
        skillProviso.insert(make_pair(skill[i], skill[i - 1]));
    }


    for (string skills : skill_trees)
    {
        int index = 0;
        char ready = '-';

        for (char c : skills)
        {
            if (skillProviso.find(c) != skillProviso.end())
            {
                if (skillProviso[c] == ready)
                {
                    index++;
                    ready = skill[index];
                    continue;
                }
                else
                {
                    answer--;
                    break;
                }
            }
            if (c == skill[index])
            {
                ready = skill[index];
            }
        }
        answer++;
    }

    return answer;
}

int main()
{
    solution({ "CBDK" }, { "CB", "CXYB", "BD", "AECD", "ABC", "AEX", "CDB", "CBKD", "IJCB", "LMDK" });
}
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;

    vector<string> sample = { "aya","ye", "woo", "ma" };


    for (string s : babbling)
    {
        vector<string> log;

        for (int i = 0; i < 4; i++)
        {
            int a = s.find(sample[i]);
            if (s.find(sample[i]) == 0)
            {
                if (!log.empty() && log.back() == sample[i])
                {
                    log.clear();
                    break;
                }
                s = s.substr(sample[i].length());
                log.push_back(sample[i]);
                i = -1;
            }
        }
        if (s.empty())
            answer++;
    }

    return answer;
}

int main()
{
    solution({ "mayewooaya" });
    return 0;
}
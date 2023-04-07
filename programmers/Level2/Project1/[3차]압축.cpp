#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, bool> list;

    for (char i = 'a'; i < 'z' + 1; i++)
    {


        list[i] = true;
    }

    return answer;
}

int main()
{
    solution("a");

    return 0;
}
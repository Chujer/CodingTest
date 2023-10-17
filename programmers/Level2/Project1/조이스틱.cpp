#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    
    vector<bool> check(name.size(), false);
    
    string temp(name.size(), 'A');
    for (int i = 0; i < name.size(); i++)
    {
        if (temp[i] != name[i])
            check[i] = true;
    }

    int index = 0;
    while (true)
    {

        int answerPlus = 0;
        if (temp[index] != name[index])
        {
            answerPlus = min(abs(name[index] - temp[index]), abs('Z' - name[index]) + 1);
            temp[index] = name[index];
            answer += answerPlus;
        }

        if (name == temp)
            break;

        for( )
    }

    return answer;
}

int main()
{
    solution("ZZZ");
}
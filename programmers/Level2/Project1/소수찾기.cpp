#include <string>
#include <vector>
#include <math.h>
#include <map>

using namespace std;

map<int, int> rem;

int aa = 0;

void DFS(string numbers, string curNum, vector<int> check, int index = -1)
{
    if (index != -1)
    {
        check[index] = -1;
        curNum += numbers[index];
    }

    if (curNum != "")
    {
        int temp = stoi(curNum);
        bool t = true;
        for (int i = 2; i <= sqrt(temp) + 1; i++)
        {
            if (temp % i == 0)
            {
                t = false;
                break;
            }
        }
        if (t && curNum != "1" && rem[temp] == 0)
        {
            aa++;
            rem[temp] = 1;
        }
        if (temp == 2 && rem[temp] == 0)
        {
            aa++;
            rem[temp] = 1;
        }
    }

    for (int i = 0; i < numbers.size(); i++)
    {
        if (check[i] != 0)
            continue;

        if (curNum == "" && numbers[i] == '0')
        {
            continue;
        }

        DFS(numbers, curNum, check, i);
    }
}

int solution(string numbers) {
    int answer = 0;

    string temp;
    vector<int> check(numbers.size(), 0);

    DFS(numbers, temp, check);

    answer = aa;

    return answer;
}

int main()
{
    solution("22");
}
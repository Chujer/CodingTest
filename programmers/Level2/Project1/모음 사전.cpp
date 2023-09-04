#include <string>
#include <iostream>
#include <vector>

using namespace std;

char arr[5] = { 'A', 'E', 'I', 'O', 'U' };
int answer = 0;

void DFS(string word, string curStr, int& count, int index)
{
    count++;
    curStr += arr[index];

    if (curStr == word)
    {
        answer = count;
        return;
    }

    if (curStr.size() < 5)
    {
        for(int i = 0; i <5; i++)
            DFS(word, curStr, count, i);
    }

}

int solution(string word) {

    string a = "";
    int count = 0;

    for(int i = 0; i < 5; i++)
        DFS(word, a, count,i);
    return answer;
}

int main()
{
    solution("EIO");
}
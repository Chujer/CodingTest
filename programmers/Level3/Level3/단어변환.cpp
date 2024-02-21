#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

queue<string> que;
int tempAnswer = 0;

void BFS(string curWord, unordered_map<string, int> check, string target, vector<string> words, int count)
{
    if (curWord == target)
    {
        tempAnswer = check[curWord] - 1;
    }

    for (int i = 0; i < words.size(); i++)
    {
        int tempCount = 0;
        for (int j = 0; j < curWord.size(); j++)
        {
            if (curWord[j] != words[i][j])
                tempCount++;

        }
        if (tempCount == 1)
        {
            tempCount = 0;
            if (check[words[i]] == 0)
            {
                que.push(words[i]);
                check[words[i]] = check[curWord] + 1;
            }
        }
        tempCount = 0;
    }

    while (!que.empty())
    {
        string temp = que.front();
        que.pop();
        BFS(temp,check, target, words, count+1);
    }

}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    unordered_map<string, int> check;
    check[begin] = 1;
    BFS(begin,check, target, words, 0);

    return tempAnswer;
}

int main()
{
    solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" });
}
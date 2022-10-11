#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2);

    unordered_map<string, int> useWords;

    for (int i = 0; i < words.size(); i++)
    {
        if (i % n == 0)
            answer[1]++;

        if (i != 0)
        {
            if (useWords.count(words[i]) > 0
                || words[i][0] != words[i - 1][words[i-1].size() - 1])
            {
                answer[0] = i % n + 1;
                return answer;
            }
        }

         useWords[words[i]]++;
    }

    return {0,0};
}


int main()
{
    vector<string> words = { "hello", "observe", "effect", "take", "either", "recognize", "encourage", "ensure", "establish", "hang", "gather", "refer", "reference", "estimate", "executive" };
    
    solution(5, words);
    return 0;
}
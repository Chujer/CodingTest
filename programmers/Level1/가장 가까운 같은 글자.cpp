#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<char, int> charIndex;

    for (int i = 0; i < s.size(); i++)
    {
        if (charIndex[s[i]] == 0)
        {
            charIndex[s[i]] = i + 1; // ù��° ������ ���ڴ� 0�̱⿡ +1�����ش�
            answer.push_back(-1);
        }
        else
        {
            answer.push_back(i -(charIndex[s[i]] - 1) );
            charIndex[s[i]] = i + 1;
        }
    }
    return answer;
}

int main()
{
    solution("banana");
}
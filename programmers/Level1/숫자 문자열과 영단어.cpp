#include <string>
#include <vector>
#include <map>

#include <regex>

using namespace std;

int solution(string s) {
    int answer = 0;
    map<string, int> numString;
   
    vector<string> numName = { "zero", "one", "two", "three", "four", "five",
    "six","seven", "eight", "nine" };
    
    for (int i = 0; i < 10; i++)
        numString.insert(make_pair(numName[i], i));



    string temp = "";
    string tempNum = "";
    for (char c : s)
    {
        if (c >= 'a' && c <= 'z')
        {
            tempNum += c;
            if (numString.find(tempNum) != numString.end())
            {
                temp += to_string(numString[tempNum]);
                tempNum = "";
            }
        }
        else
        {
            temp += c;
        }
    }
    answer = stoi(temp);

    return answer;
}

/*
���ڿ� ġȯ�Լ� replace, regex_replace
    string.replace(������ġ, ����, ġȯ ���ڿ�) : ������ġ���� ���̸�ŭ ġȯ���ڿ��� ��ȯ�Ѵ�.
  
  [ include<regex> ] 
   regex_replace(����ڿ�, regex(���Խ�), ġȯ ���ڿ�)
     : ���Խ����� ������ ���ڿ��� ġȯ ���ڿ��� ��ȯ�Ѵ�.
     ex)  regex_replace(s, regex("1"), "one");
*/
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
문자열 치환함수 replace, regex_replace
    string.replace(시작위치, 길이, 치환 문자열) : 시작위치부터 길이만큼 치환문자열로 변환한다.
  
  [ include<regex> ] 
   regex_replace(대상문자열, regex(정규식), 치환 문자열)
     : 정규식으로 지정한 문자열을 치환 문자열로 변환한다.
     ex)  regex_replace(s, regex("1"), "one");
*/
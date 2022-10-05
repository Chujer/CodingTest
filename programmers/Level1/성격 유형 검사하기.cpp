#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";

    map<char, int> mbti;
    mbti['R'] = 0; mbti['T'] = 0; 
    mbti['C'] = 0; mbti['F'] = 0; 
    mbti['J'] = 0; mbti['M'] = 0; 
    mbti['A'] = 0; mbti['N'] = 0; 

    for (int i = 0; i<survey.size(); i++)
    {
        int temp = 4 - choices[i];
        if (temp > 0)
            mbti[survey[i][0]] += temp;
        else if (temp < 0)
            mbti[survey[i][1]] += abs(temp);
    }
    answer +=  mbti['R'] < mbti['T'] ?  'T' : 'R';
    answer +=  mbti['C'] < mbti['F'] ?  'F' : 'C';
    answer +=  mbti['J'] < mbti['M'] ?  'M' : 'J';
    answer +=  mbti['A'] < mbti['N'] ?  'N' : 'A';


    return answer;
}

//int main()
//{
//    vector<string> s =  {"AN", "CF", "MJ", "RT", "NA"};
//    vector<int> a = { 5, 3, 2, 7, 5 };
//
//    solution(s, a);
//    return 0;
//}
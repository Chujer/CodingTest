#include <string>
#include <vector>
#include <queue>
#include <deque>
using namespace std;
deque<string> test;

long long solution(string expression) {
    long long answer = 0;

    char preority[6][3] = { {'+','-','*'} , {'+','*','-'}, {'-','+','*'} , {'-','*','+'}, {'*','-','+'}, {'*','+','-'} };

    long long cur = 0;
    for (long long i = 0; i < expression.size(); i++)
    {
        if (expression[i] < '0' || expression[i] > '9')
        {
            if(test.empty() )
                test.push_back(expression.substr(0, i - cur));
            else
                test.push_back(expression.substr(cur+1, i - cur-1));

            cur = i;

            string tempstring = "";
            tempstring += expression[i];
            test.push_back(tempstring);
        }
    }
    test.push_back(expression.substr(cur + 1, expression.size()));

    deque<string> origin = test;

    for (int i = 0; i < 6; i++)
    {
        deque<string> tempresult;
        for (int j = 0; j < 3; j++)
        {
            long long curNum = 0;
            while (!test.empty())
            {
                if (test.front()[0] < '0' || test.front()[0] > '9')
                {
                    if (test.front()[0] == preority[i][j])  //연산식이 동일할 때
                    {
                        test.pop_front();
                        long long tempAnswer = 0;
                        switch (preority[i][j])
                        {
                        case '+':
                            curNum = stoll(tempresult.back());
                            tempresult.pop_back();
                            tempAnswer = curNum + stoll(test.front());
                            tempresult.push_back(to_string(tempAnswer));
                            curNum = tempAnswer;
                            test.pop_front();
                            break;
                        case '-':
                            curNum = stoll(tempresult.back());
                            tempresult.pop_back();
                            tempAnswer = curNum - stoll(test.front());
                            tempresult.push_back(to_string(tempAnswer));
                            curNum = tempAnswer;
                            test.pop_front();
                            break;
                        case '*':
                            curNum = stoll(tempresult.back());
                            tempresult.pop_back();
                            tempAnswer = curNum * stoll(test.front());
                            tempresult.push_back(to_string(tempAnswer));
                            curNum = tempAnswer;
                            test.pop_front();
                            break;
                        default:
                            break;
                        }
                    }
                    else
                    {
                        tempresult.push_back(test.front());
                        test.pop_front();
                    }
                }
                else
                {
                    curNum = stoll(test.front());
                    tempresult.push_back(test.front());
                    test.pop_front();
                }
            }
            test = tempresult;
            tempresult = deque<string>();
        }
        long long mbAnswer = stoll(test.front());
        answer = max(answer, abs(mbAnswer));
        test = origin;
    }
    return answer;
}

int main()
{
    solution("5+5+5*5-10");
}
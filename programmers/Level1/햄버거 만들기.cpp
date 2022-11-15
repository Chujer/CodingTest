#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <stack>
#include <iostream>
using namespace std;

//의문 - stack.pop()을사용시 주소지의 변경점

bool makeBuger(int* num)
{
    int *a = --num;
    int b = *(num - 2);
    int c = *(num - 3);

    if (*a == 3)
    {
        if (b == 2)
        {
            if (c == 1)
                return true;
        }
    }
    return false;
}

/*
* int solution(vector<int> ingredient) {
    int answer = 0;
    stack<int> datas;

    for (int temp : ingredient)
    {
        datas.push(temp);
        if (datas.top() == 1 && datas.size() > 3)
        {
            datas.pop();
            if (datas.top() != 3)
            {
                datas.push(1);
                continue;
            }
            else
            {
                datas.pop();
                if (datas.top() != 2)
                {
                    datas.push(3);
                    datas.push(1);
                    continue;
                }
                else
                {
                    datas.pop();
                    if (datas.top() != 1)
                    {
                        datas.push(2);
                        datas.push(3);
                        datas.push(1);
                        continue;
                    }
                    else
                    {
                        datas.pop();
                        answer++;
                    }
                }
            }
        }
    }


    return answer;
}

*/
int solution(vector<int> ingredient) {
    int answer = 0;
    stack<int> datas;

    for (int temp : ingredient)
    {
        datas.push(temp);
        cout << &datas.top() << endl << endl;
        if (datas.top() == 1 && datas.size()>3)
        {
            if (makeBuger(&datas.top()))
            {
                for (int i = 0; i < 4; i++)
                {
                    cout << "파괴" << endl;
                    datas.pop();
                }
                answer++;
            }
        }
    }



    return answer;
}

int main()
{
    solution({ 2,1,2,3,1,1,2,3,1,3,1,3 });
}
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>

using namespace std;

void DFS(vector<int>& data, int& answer, int col) 
{
    if (data.size() == col) 
    {
        answer++;
    }
    else 
    {
        for (int i = 0; i < data.size(); i++) 
        {
            bool flag = true;
            data[col] = i;

            for (int j = 0; j < col; j++) 
            {
                if (data[col] == data[j] || abs(data[col] - data[j]) == abs(col - j)) 
                {
                    flag = false;
                    break;
                }
            }
            if (flag) 
                DFS(data, answer, col + 1);
        }
    }
}

int solution(int n) {
    int answer = 0;
    vector<int> data(n);
    DFS(data, answer, 0);


    return answer;
}

int main()
{
    solution(4);
}
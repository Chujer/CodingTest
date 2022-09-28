#include <string>
#include <vector>

using namespace std;

string ConvertBinary(int num)
{
    string answer = "";
    string temp = "";

    while (num > 0)
    {
        temp += to_string(num % 2);
        num /= 2;
    }
    for (int i = temp.size()-1; i >= 0; i--)
    {
        answer += temp[i];
    }

    return answer;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    string temp1 = "";
    string temp2 = "";



    for (int i = 0; i < n; i++)
    {
        temp1 = ConvertBinary(arr1[i]);
        temp2 = ConvertBinary(arr2[i]);

        if (temp1.size() < n)
        {
            int space = n - temp1.size();
            string tempStr = "";
            for (int i = 0; i < space; i++)
                tempStr += "0";
            temp1 = tempStr + temp1;
        }
        if (temp2.size() < n)
        {
            int space = n - temp2.size();
            string tempStr = "";
            for (int i = 0; i < space; i++)
                tempStr += "0";
            temp2 = tempStr + temp2;
        }

        string temp = "";
        for (int j = 0; j < temp1.size(); j++)
        {
            if (temp1[j] == '0' && temp2[j] == '0')
                temp += " ";
            else
                temp += "#";
        }
        answer.push_back(temp);
    }


    return answer;
}

/*
* //이미 컴퓨터 내부의 숫자는 2진수이다. 비트연산 |을 이용하면 바로 검사를 실행할수 있다.
* vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i=0; i <n; i++){
        arr1[i] = arr1[i]|arr2[i];
        string ans = "";
        for(int j = 0; j<n; j++){
            if(arr1[i] % 2 == 0) ans = " " + ans;
            else ans = "#" + ans;
            arr1[i] = arr1[i] >> 1;
        }
        answer.push_back(ans);
    }
    return answer;
}
나는 바보다..ㅠ
*/


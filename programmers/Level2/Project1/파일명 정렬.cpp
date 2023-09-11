#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmd(tuple<string, int, int> a, tuple<string, int, int> b)
{
    if (get<0>(a) < get<0>(b))
    {
        return 1;
    }
    else if (get<0>(a) > get<0>(b))
    {
        return 0;
    }
    else
    {
        if (get<1>(a) < get<1>(b))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    map<string, map<int,int>> data;
   // tuple<string, int, int> datas;
    vector <tuple<string, int, int>> datas;

    for (int i = 0; i < files.size(); i++)
    {
        string head = "", tail = "";
        string strNum = "";
        int num;

        int pro = 1;
        for (int j = 0; j < files[i].size(); j++)
        {
            if (files[i][j] >= '0' && files[i][j] <= '9')
            {
                if (pro == 1)
                    pro = 2;
                if(pro == 2)
                    strNum += files[i][j];
            }
            else
            {
                if (pro == 1)
                    head += tolower(files[i][j]);
                else if (pro == 2)
                    pro = 3;
                
                if (pro == 3)
                    tail += tolower(files[i][j]);
            }
        }

        num = stoi(strNum);

        data[head][num] = i;
        datas.push_back({ head, num, i });
    }

    stable_sort(datas.begin(), datas.end(), cmd);
    

    for (tuple<string, int, int> d : datas)
    {
        answer.push_back(files[get<2>(d)]);
    }

    return answer;
}

int main()
{
    solution({ "a000011", "a00001" });
}
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<vector<int>> datas;
vector<vector<int>> temp;
void DFS(vector<bool> check, int start, int& count)
{
    check[start] = false;
    count++;
    
    for (int i = 1; i < temp[start].size(); i++)
    {
        if (check[i] == false || temp[start][i] == 0)
            continue;

        check[i] = false;

        DFS(check, i, count);
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    
    datas.resize(n + 1, vector<int>(n+1, 0));
    vector<bool> check(n + 1, true);

    for (int i = 0; i < wires.size(); i++)
    {
        datas[wires[i][0]][wires[i][1]] = 1;;
        datas[wires[i][1]][wires[i][0]] = 1;;
    }

    for (int i = 0; i < wires.size(); i++)
    {
        temp = datas;
        temp[wires[i][0]][wires[i][1]] = 0;
        temp[wires[i][1]][wires[i][0]] = 0;

        int one = 0; DFS(check, wires[i][0], one);
        int two = 0; DFS(check, wires[i][1], two);
        answer = min(answer, abs(one - two));
    }

    return answer;
}

int main()
{
    solution(9, { {1,3} ,{2,3},{3,4},{4,5},{4,6},{4,7},{7,8},{7,9} });
    //solution(4, { {1,2},{2,3},{3,4} });
}
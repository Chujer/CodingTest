#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

queue<pair<int,int>> que;
int Infy = 50000000;
int answerCost = Infy;

void Search(map<int, map<int, int>> data, map<int,int> check,int curPos, int end,  int cost)
{
    if (curPos == end)
        answerCost = min(answerCost, check[end]);
    for (auto d : data[curPos])
    {
        if (check[d.first] != 0 && check[d.first] < check[curPos] + cost)
            continue;
        que.push({ d.first, d.second});
        check[d.first] = d.second + check[curPos];
        
    }

    while (!que.empty())
    {
        int temp = que.front().first;
        int tempCost = que.front().second;
        que.pop();
        Search(data, check, temp, end, tempCost);
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;

    map<int, map<int, int>> data;
    map<int, int> check;
    check[s] = 0;
    for (int i = 0; i < fares.size(); i++)
    {
        int start = fares[i][0];
        int end = fares[i][1];
        int cost = fares[i][2];

        data[start][end] = cost;
        data[end][start] = cost;
    }
    Search(data, check, s, a, 0);
    int sToaAndB = answerCost;
    answerCost = Infy;
    Search(data, check, a, b, 0); 
    sToaAndB += answerCost;


    answerCost = Infy;
    Search(data, check, s, a, 0);
    int sab = answerCost;
    answerCost = Infy;
    Search(data, check, s, b, 0);
    sab += answerCost;

    answerCost = Infy;
    Search(data, check, s, b, 0);
    int sTobAnda = answerCost;
    answerCost = Infy;
    Search(data, check, b, a, 0);
    sTobAnda += answerCost;

    answer = min(sToaAndB, sTobAnda);
    answer = min(answer, sab);

    return answer;
}
int main()
{
    solution(6, 4, 6, 2, { {4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25} });
}
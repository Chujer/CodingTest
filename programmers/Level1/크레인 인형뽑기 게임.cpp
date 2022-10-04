#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<vector<int>>tempBaords;

    tempBaords.resize(board.size());
    for (vector<int>& temp : tempBaords)
    {
        temp.resize(tempBaords.size());
    }

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            tempBaords[j][i] = board[i][j];
        }
    }
    for(vector<int>& temp : tempBaords)
        reverse(temp.begin(), temp.end());
    vector<int> items;

    for (int move : moves)
    {
        int mPos = move - 1;

        if (tempBaords[mPos].size() == 0)
            continue;

        int temp = 0;
        while (tempBaords[mPos][tempBaords[mPos].size() - 1 - temp] == 0)
        {
            temp++;
            if (temp > tempBaords[mPos].size() - 1)
                break;
        }

        if (temp == tempBaords[mPos].size())
            continue;

        items.push_back(tempBaords[mPos][tempBaords[mPos].size() - 1 - temp]);
        tempBaords[mPos].erase(tempBaords[mPos].begin() + (tempBaords[mPos].size() -1 - temp)); 
        if (items.size() > 1)
        {
            if (items[items.size() - 1] == items[items.size() - 2])
            {
                answer += 2;
                items.erase(items.begin() + items.size() - 2);
                items.erase(items.begin() + items.size() - 1);
            }
        }
  
    }
    int a = 10;

    return answer;
}

//int main()
//{
//    vector<vector<int>> temp =
//    {
//        {0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},
//        {4,2,4,4,2},{3,5,1,3,1}
//    };
//    vector<int> moves = { 1,5,3,5,1,2,1,4 };
//
//    solution(temp, moves);
//    return 0;
//}
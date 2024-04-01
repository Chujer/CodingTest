#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;

    vector<vector<vector<int>>> keys(4,vector<vector<int>>(key.size() , vector<int>(key[0].size(),0)));
    int size = key.size() - 1;
    vector<vector<int>> loc(lock.size() + (key.size() * 2) - 2, vector<int>(lock.size()+ (key.size() * 2) - 2, -1));
    int lockCount = 0;

    for (int i = 0; i < lock.size(); i++)
    {
        for (int j = 0; j < lock.size(); j++)
        {
            if (lock[i][j] == 0)
            {
                lockCount++;
            }
            loc[i + key.size()-1][j + key.size() - 1] = lock[i][j];
        }
    }

    keys[0].clear();
    keys[0].insert(keys[0].begin(), key.begin(), key.end());;
    for (int k = 1; k < 4; k++)
    {
        for (int i = 0; i < key.size(); i++)
        {
            for (int j = 0; j < key.size(); j++)
            {
                    keys[k][i][j] = keys[k-1][abs(j - size)][i];
            }
        }
    }

    int tempCount = 0;
    bool isNot = false;
    for (int startY = 0; startY < loc.size()- (key.size()-1); startY++)
    {
        for (int startX = 0; startX < loc.size() - (key.size()-1); startX++)
        {
            for (int k = 0; k < keys.size(); k++)
            {
                tempCount = 0;
                isNot = false;
                for (int i = 0; i < key.size(); i++)
                {
                    for (int j = 0; j < key.size(); j++)
                    {
                        if (loc[startY + i][startX + j] != keys[k][i][j] && keys[k][i][j] == 1 && loc[startY + i][startX + j] == 0)
                        {
                            tempCount++;
                        }
                        else if (loc[startY + i][startX + j] == keys[k][i][j] && keys[k][i][j] == 1)
                        {
                            isNot = true;
                            break;
                        }
                    }
                    if (isNot == true)
                        break;
                }
                if (!isNot && tempCount >= lockCount)
                    return true;

            }
        }


    }

    return answer;
}

int main()
{
    //solution({ {0, 0, 0,1} ,{1, 0, 0,1},{0, 1, 1,1},{0, 1, 1,1} }, { {1, 1, 1,1,1} ,{1, 1, 0,1,1},{1, 0, 1,1,1},{1, 0, 1,1,1},{1, 0, 1,1,1} });
    solution({ {0, 0, 0} ,{1, 0, 0},{0, 1, 1} }, { {1, 1, 1} ,{1, 1, 0},{1, 0, 1}});
}
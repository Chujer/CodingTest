#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<vector<int>> giveupMans = { 
        {1,2,3,4,5},
        {2,1,2,3,2,4,2,5},
        {3,3,1,1,2,2,4,4,5,5} 
    };

    int mansNum = 0;
    vector<int> mansScore = { 0,0,0 };
    int maxScore = 0;

    for (int answer : answers)
    {
        if (giveupMans[0][mansNum % giveupMans[0].size()] == answer)
            mansScore[0]++; 

        if (giveupMans[1][mansNum % giveupMans[1].size()] == answer)
            mansScore[1]++;

        if (giveupMans[2][mansNum % giveupMans[2].size()] == answer)
            mansScore[2]++;

        mansNum++;
    }

    maxScore = *max_element(mansScore.begin(), mansScore.end());
    for (int i = 0; i < 3; i++)
    {
        if (maxScore == mansScore[i])
            answer.push_back(i+1);
    }
    

    return answer;
}
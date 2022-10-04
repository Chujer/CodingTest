#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";

    vector<vector<int>> numberPad = 
    { {1, 2, 3}, { 4,5,6 }, { 7,8,9 },{-100,0,100} };

    int lHandPos[2] = { 3,0 };
    int rHandPos[2] = { 3,2 };

    int destination[2];

    for (int number : numbers)
    {
        //number가 1,4,7일때는 바로 위치를 저장
        if (number == 1 || number == 4 || number == 7)
        {
            for (int i = 0; i < numberPad.size(); i++)
            {
                for (int j = 0; j < numberPad[0].size(); j++)
                {
                    if (numberPad[i][j] == number)
                    {
                        destination[0] = i;
                        destination[1] = j;
                        break;
                    }
                }
            }
            answer += 'L';
            lHandPos[0] = destination[0];
            lHandPos[1] = destination[1];
            continue;
        }
        else if (number == 3 || number == 6 || number == 9)
        {
            //number가 3,6,9일때는 바로 위치를 저장
            for (int i = 0; i < numberPad.size(); i++)
            {
                for (int j = 0; j < numberPad[0].size(); j++)
                {
                    if (numberPad[i][j] == number)
                    {
                        destination[0] = i;
                        destination[1] = j;
                        break;
                    }
                }
            }
            answer += 'R';
            rHandPos[0] = destination[0];
            rHandPos[1] = destination[1];
            continue;
        }
        else
        {
            //입력받은값의 패드의 위치를 검색후 거리를 계산하여 왼손으로 사용할지 왼손으로 사용할지 지정
            for (int i = 0; i < numberPad.size(); i++)
            {
                for (int j = 0; j < numberPad[0].size(); j++)
                {
                    if (numberPad[i][j] == number)
                    {
                        destination[0] = i;
                        destination[1] = j;
                        break;
                    }
                }
            }

            int distanceL = abs(destination[0] - lHandPos[0]) + abs(destination[1] - lHandPos[1]);
            int distanceR = abs(destination[0] - rHandPos[0]) + abs(destination[1] - rHandPos[1]);

            if (distanceL == distanceR)
            {
                if (hand == "left")
                {
                    answer += 'L';
                    lHandPos[0] = destination[0];
                    lHandPos[1] = destination[1];
                }
                else
                {
                    answer += 'R';
                    rHandPos[0] = destination[0];
                    rHandPos[1] = destination[1];
                }
            }
            else if (distanceL < distanceR)
            {
                answer += 'L';
                lHandPos[0] = destination[0];
                lHandPos[1] = destination[1];
            }
            else
            {
                answer += 'R';
                rHandPos[0] = destination[0];
                rHandPos[1] = destination[1];
            }
        }
    }
    return answer;
}

//int main()
//{
//    solution({ 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 }, "right");
//    return 0;
//}
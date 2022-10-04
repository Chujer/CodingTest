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
        //number�� 1,4,7�϶��� �ٷ� ��ġ�� ����
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
            //number�� 3,6,9�϶��� �ٷ� ��ġ�� ����
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
            //�Է¹������� �е��� ��ġ�� �˻��� �Ÿ��� ����Ͽ� �޼����� ������� �޼����� ������� ����
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
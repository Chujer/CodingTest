#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer(2);

    int x;
    int temp;
   
    temp = yellow / 2;

    if (temp == 0) temp = 1;

    for (int y = 1; y <= temp; y++)
    {
        if (yellow % y != 0)
            continue;

        x = yellow / y;
        
        int size = (2 * x) + (2 * y) + 4;

        if (size == brown)
        {
            answer[0] = x+2;
            answer[1] = y + 2;
            return answer;
        }
    }    

    return answer;
}

int main()
{
    solution(48, 21);

    return 0;
}
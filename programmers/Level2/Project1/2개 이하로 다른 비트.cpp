#include <string>
#include <vector>
#include <deque>
#include<math.h>
using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for (long long number : numbers)
    {
        deque<char> bit;
        int count = 0;
        long long tempNum = 0;
        while (number >= 2)
        {
            if (number % 2 == 0)
            {
                bit.push_front('0');
                count++;
            }
            else
                bit.push_front('1');

            number /= 2;
        }
        if (number > 0)
            bit.push_front('1');  //비트변환


        if (count > 0)
        {
            for (int i = bit.size() - 1; i >= 0; i--)
            {
                if (bit[i] == '0')
                {
                    bit[i] = '1';
                    if (i+1 < bit.size())
                        bit[i + 1] = '0';
                    break;
                }
            }
        }
        else
        {
            bit.push_front('1');
            bit[1] = '0';
        }
        
        for (int i = bit.size() - 1; i >= 0 ; i--)
        {
            if(bit[i]== '1')
                tempNum += pow(2, bit.size()-1-i);
        }

        answer.push_back(tempNum);
    }

    return answer;
}

int main()
{
    solution({ 5,7 });
}
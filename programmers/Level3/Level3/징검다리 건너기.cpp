#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;    
    int high = *max_element(stones.begin(), stones.end());
    int low = 1;
    int mid;


    while (low <= high)
    {
        mid = (high + low) / 2;
        int count = 0;
        for (int i = 0; i < stones.size(); i++)
        {
            if (mid > stones[i])
                count++;
            else
                count = 0;
            if (count == k)
            {
                high = mid - 1;
                break;
            }
        }
        if (count < k)
            low = mid+1;
    }



    return high;
}

int main()
{
    solution({ 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 }, 3);
}
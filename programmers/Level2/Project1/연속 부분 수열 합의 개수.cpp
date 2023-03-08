#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    set<int> sums;

    int count = 1;

    while(count != elements.size()+1)
    {
        int j = 1;
        for(int i = 0; i < elements.size();i+=j)
        {
            int tempNum = 0;

            for(int temp = 0; temp < count; temp++)
            {
                int index = temp + i;

                if (index > elements.size() - 1)
                    index -= elements.size() ;

                tempNum += elements[index];
            }
            
            sums.insert(tempNum);
        }
        j++;

        count++;
    }

    answer = sums.size();

    return answer;
}

int main()
{
    solution({ 7,9,1,1,4 });
    return 0;
}
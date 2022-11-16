#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int answer = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {

        if (answer >= arr[i] && answer % arr[i] == 0)
            continue;

        int temp = 2;
        while (true)
        {
            if (answer * temp >= arr[i] && (answer * temp) % arr[i] == 0)
            {
                answer = answer * temp;
                break;
            }
            temp++;
        }
    }

    return answer;
}

int main()
{
    solution({ 2,6,8,14 });
    return 0;

}
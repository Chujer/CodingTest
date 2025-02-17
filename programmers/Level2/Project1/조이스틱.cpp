#include <string>
#include <vector>

using namespace std;

int solution(string name)
{
    int a[26] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,12,11,10,9,8,7,6,5,4,3,2,1 };

    int answer = 0;
    int n = name.length();
    int min_move = n - 1;

    for (int x = 0; x < n; x++)
    {
        answer += a[name[x] - 'A'];

        int y = x + 1;
        while (x < n && name[y] == 'A')
            y++;

        min_move = min(min_move, x + n - y + min(x, n - y));
    }
    answer += min_move;

    return answer;
}

int main()
{
    solution("ABABAAAAAAABA");
}
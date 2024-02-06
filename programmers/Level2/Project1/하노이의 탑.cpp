#include <string>
#include <vector>

using namespace std;

void hanoi(int n, int go, int to, vector<vector<int>>& answer) {
    if (n == 1) {// ���� ������ �Ѱ���� 
        answer.push_back({ go, to });
        return;
    }
    hanoi(n - 1, go, 6 - go - to, answer);// n-1 ���� ������ ������, ��ǥ���� ������ ������ �̵�
    hanoi(1, go, to, answer);// n��° ������ ��ǥ�������� �̵�
    hanoi(n - 1, 6 - go - to, to, answer);// n-1 ���� ������ ��ǥ������ �̵�
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanoi(n, 1, 3, answer);
    return answer;
}
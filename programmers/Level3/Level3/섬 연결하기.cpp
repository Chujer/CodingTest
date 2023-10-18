#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

//가중치, 시작지점, 끝지점

bool cmd(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
}

struct Node
{
    Node* parent;
    Node* child = 0;
    int cost = 0;
    
    Node() {}
    Node(Node* parent, Node* child, int cost) : parent(parent), child(child), cost(cost) {}
};

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    Node* start;
    
    //시작지점0 도착지점 1 가중치2

    sort(costs.begin(), costs.end(), cmd);

    for (int i = 0; i < costs.size(); i++)
    {
        Node parent(costs[i][0], costs[i][1], costs[i][2]);
        bool stop = false;
        while (brdge[node.parent].cost != 0)
        {
            node = brdge[node.parent];
            if (node.parent == costs[i][1])
                stop = true;
        }
        if(!stop)
            brdge[costs[i][1]] = node;
    }

    

    return answer;
}

int main()
{
    solution(4, { {0,1,1} ,{0,2,2},{1,2,5}, {1,3,1}, {2,3,8} });
}
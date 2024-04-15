#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct Node
{
    int num;
    int nodeNum;
    Node* left = nullptr;
    Node* right = nullptr;
};

void DFS(Node* cur, int sheep, int wolf, queue<Node*> que, int &answer)
{
    if (cur->num == 1)
        sheep++;
    else
        wolf++;

    if (wolf >= sheep) 
        return;
    if (answer < sheep)
        answer = sheep;

    if (cur->left != nullptr)
        que.push(cur->left);
    if (cur->right != nullptr)
        que.push(cur->right);

    for (int i = 0; i < que.size(); i++)
    {
        Node* temp = que.front();
        que.pop();
        DFS(temp, sheep, wolf,que, answer);
        que.push(temp);
    }

}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    queue<Node*> que;
    vector<Node> nodes;

    for (int i = 0; i < info.size(); i++)
    {
        Node temp;
        if (info[i] == 1)
            temp.num = -1;
        else
            temp.num = 1;
        temp.nodeNum = i ;
        nodes.push_back(temp);
    }

    for (int i = 0; i < edges.size(); i++)
    {
        int start = edges[i][0];
        int end = edges[i][1];
        if (nodes[start].left == nullptr)
            nodes[start].left = &nodes[end];
        else
            nodes[start].right = &nodes[end];
    }

    DFS(&nodes[0], 0, 0,que, answer);

    return answer;
}

int main()
{
    solution({ 0,0,1,1,1,0,1,0,1,0,1,1 }, { {0,1} ,{1,2},{1,4},{0,8},{8,7},{9,10},{9,11},{4,3},{6,5},{4,6},{8,9} });
}
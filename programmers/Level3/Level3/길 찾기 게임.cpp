#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Node
{
    Node(int name, Node* left, Node* right, int x, int y) : name(name), left(left), right(right), x(x), y(y) {}
    int name;
    Node* left = nullptr;
    Node* right = nullptr;
    int y;
    int x;
};

void SearchF(Node* node, vector<int>& answer)
{
    answer.push_back(node->name);
    if (node->left != nullptr)
        SearchF(node->left, answer);
    if (node->right != nullptr)
        SearchF(node->right,answer);
}

void SearchB(Node* node, vector<int>& answer)
{
    if (node->left != nullptr)
        SearchB(node->left, answer);
    if (node->right != nullptr)
        SearchB(node->right, answer);
    answer.push_back(node->name);
}

void MBT(Node* root, Node* child)
{
    if (root->x > child->x)
    {
        if (root->left == nullptr)
        {
            root->left = child;
            return;
        }
        MBT(root->left, child);
    }
    else
    {
        if (root->right == nullptr)
        {
            root->right = child;
            return;
        }
        MBT(root->right, child);
    }
}

bool cmp(Node a, Node b)
{
    if (a.y > b.y)
        return true;
    else if (a.y == b.y)
    {
        if (a.x > b.x)
            return true;
    }

    return false;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    
    vector<Node> data;

    for (int i = 0; i < nodeinfo.size(); i++)
    {
        int x = nodeinfo[i][0];
        int y = nodeinfo[i][1];
        int name = i + 1;
        data.push_back({ name, nullptr, nullptr,x, y, });
    }

    sort(data.begin(), data.end(), cmp);

    Node* root = &data.front();
    for (int i = 1; i < data.size(); i++)
        MBT(root, &data[i]);

    vector<int> front;
    vector<int> back;

    SearchF(root,front);
    SearchB(root,back);

    answer.push_back(front);
    answer.push_back(back);
    return answer;
}

int main()
{
    solution({ {5,3} ,{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2} });
}

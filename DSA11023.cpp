#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->val = data;
        this->left = this->right = nullptr;
    }
};

void buildTree(Node*& root, int val)
{
    if(!root)
    {
        root = new Node{val};
        return;
    }

    if(root->val < val)
        buildTree(root->right, val);
    else
        buildTree(root->left, val);
}

int height(Node* root)
{
    if(!root)
        return 0;

    return max(height(root->left), height(root->right)) + 1;
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int n;
        cin >> n;

        Node* root{};
        while(n--)
        {
            int val;
            cin >> val;
            buildTree(root, val);
        }

        cout << height(root) - 1 << '\n';
    }

    return 0;
}
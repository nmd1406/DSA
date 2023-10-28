#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

Node* buildTree(vector<int> levelOrder, vector<int> inOrder, int levelS, int levelE, int inS, int inE)
{
    int rootData{levelOrder[levelS]};

    auto itr{find(inOrder.begin(), inOrder.end(), rootData)};
    int rootIndex = itr - inOrder.begin();

    
}

void postOrder(Node* root)
{
    if(!root)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << ' ';
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int n{};
        cin >> n;

        vector<int> inOrder(n);
        vector<int> levelOrder(n);

        for(int i{}; i < n; ++i)
            cin >> inOrder[i];
        
        for(int i{}; i < n; ++i)
            cin >> levelOrder[i];

        Node* root{buildTree(levelOrder, inOrder, 0, n - 1, 0, n - 1)};

        postOrder(root);
        cout << '\n';
    }

    return 0;
}
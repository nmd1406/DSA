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

void postOrder(Node* root)
{
    if(!root)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << ' ';
}

void insert(Node*& root, int data)
{
    if(!root)
    {
        root = new Node{data};
        return;
    }

    if(root->data > data)
        insert(root->left, data);
    if(root->data < data)
        insert(root->right, data);
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int n{};
        cin >> n;

        Node* root{};
        while(n--)
        {
            int data{};
            cin >> data;
            insert(root, data);
        }

        postOrder(root);
        cout << '\n';
    }

    return 0;
}
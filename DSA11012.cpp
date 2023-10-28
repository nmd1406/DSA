#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data{};
    Node* left{};
    Node* right{};

    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

void insert(Node* root, int rootData, int childData, char pos)
{
    if(!root)
        return;

    if(root->data == rootData)
    {
        if(pos == 'L')
            root->left = new Node{childData};
        else
            root->right = new Node{childData};
    }
    else
    {
        insert(root->left, rootData, childData, pos);
        insert(root->right, rootData, childData, pos);
    }
}

Node* createRoot()
{
    int n{};
    cin >> n;

    Node* root{};

    while(n--)
    {
        int u{};
        int v{};
        char ch{};
        cin >> u >> v >> ch;

        if(!root)
        {
            root = new Node{u};

            if(ch == 'R')
                root->right = new Node{v};
            else
                root->left = new Node{v};
        }
        else
            insert(root, u, v, ch);
    }

    return root;
}

int isIdentical(Node* r1, Node* r2)
{
    if(!r1 && !r2)
        return 1;

    if(r1 && r2)
    {
        if(isIdentical(r1->left, r2->left) && r1->data == r2->data && isIdentical(r1->right, r2->right))
            return 1;
        else
            return 0;
    }

    return 0;
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        Node* r1{createRoot()};
        Node* r2{createRoot()};

        cout << isIdentical(r1, r2) << '\n';
    }

    return 0;
}
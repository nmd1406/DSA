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

bool isFullTree(Node* root)
{
    if(!root)
        return true;
    if(!root->left && !root->right)
        return true;

    Node* l{root->left};
    Node* r{root->right};

    if(l && r)
    {
        if(isFullTree(l) && isFullTree(r))
            return true;
    }
    
    return false;
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

        if(isFullTree(root))
            cout << "1\n";
        else
            cout << "0\n";
    }

    return 0;
}
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

void buildTree(Node* root, int rootData, int childData, char pos)
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
        buildTree(root->left, rootData, childData, pos);
        buildTree(root->right, rootData, childData, pos);
    }
}

int maxHeight(Node* root)
{
    if(!root)
        return 0;
    
    return 1 + max(maxHeight(root->left), maxHeight(root->right));
}

int minHeight(Node* root)
{
    if(!root)
        return INT_MAX;

    if(!root->left && !root->right)
        return 1;

    return 1 + min(minHeight(root->left), minHeight(root->right));
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
            int rootData{};
            int childData{};
            char pos{};
            cin >> rootData >> childData >> pos;

            if(!root)
            {
                root = new Node{rootData};

                if(pos == 'L')
                    root->left = new Node{childData};
                else
                    root->right = new Node{childData};
            }
            else
                buildTree(root, rootData, childData, pos);
        }

        if(minHeight(root) == maxHeight(root))
            cout << "1\n";
        else
            cout << "0\n";
    }

    return 0;
}
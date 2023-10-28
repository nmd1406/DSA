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

void levelOrder(Node* root)
{
    queue<Node*> q{};
    q.push(root);

    while(!q.empty())
    {
        Node* temp{q.front()};
        q.pop();

        cout << temp->data << ' ';
        
        if(temp->left)      
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
}

void insert(Node* root, int rootData, int childData, char ch)
{
    if(!root)
        return;

    if(root->data == rootData)
    {
        if(ch == 'L')
            root->left = new Node{childData};
        else
            root->right = new Node{childData};
    }
    else
    {
        insert(root->left, rootData, childData, ch);
        insert(root->right, rootData, childData, ch);
    }
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

        for(int i{}; i < n; ++i)
        {
            int u{};
            int v{};
            char x{};
            cin >> u >> v >> x;

            if(!root)
            {
                root = new Node{u};

                if(x == 'R')
                    root->right = new Node{v};
                else
                    root->left = new Node{v};
            }
            else
                insert(root, u, v, x);
        }

        levelOrder(root);
        cout << '\n';
    }

    return 0;
}
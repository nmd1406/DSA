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

bool isPerfect(Node* root)
{
    queue<Node*> q{};
    q.push(root);

    int level{};

    while(!q.empty())
    {
        int s = q.size();
        if(s != int(pow(2, level)))
            return false;

        for(int i{}; i < s; ++i)
        {
            Node* temp{q.front()};
            q.pop();

            if(temp->right)
                q.push(temp->right);
            if(temp->left)
                q.push(temp->left);
        }

        ++level;
    }

    return true;
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

        if(isPerfect(root))
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}
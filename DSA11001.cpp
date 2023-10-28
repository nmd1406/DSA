#include<bits/stdc++.h>

using namespace std;

struct Node
{
    char data{};
    Node* left{};
    Node* right{};

    Node(char data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

void inOrder(Node* root)
{
    if(!root)
        return;

    inOrder(root->left);
    cout << root->data << ' ';
    inOrder(root->right);
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        string str{};
        stack<Node*> s{};
        cin >> str;

        Node* root{};

        for(int i = 0; i < str.length(); ++i)
        {
            if(!isalpha(str[i]))
            {
                root = new Node{str[i]};
                root->right = s.top();
                s.pop();
                root->left = s.top();
                s.pop();

                s.push(root);
            }
            else
                s.push(new Node{str[i]});
        }

        inOrder(s.top());
        cout << '\n';
    }

    return 0;
}
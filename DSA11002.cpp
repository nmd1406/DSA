#include<bits/stdc++.h>

using namespace std;

struct Node
{
    string data{};
    Node* left{};
    Node* right{};

    Node(string data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

Node* createTree(Node* root, vector<string>& v, int n, int i)
{
    if(i < n)
    {
        root = new Node(v[i]);
        root->left = createTree(root->left, v, n, i * 2 + 1);
        root->right = createTree(root->right, v, n, i * 2 + 2);
    }

    return root;
}

int calc(Node* root)
{
    if(root->data != "+" && root->data != "-" && root->data != "*" && root->data != "/")
        return stoi(root->data);
    
    if(root->data == "+")
        return calc(root->left) + calc(root->right);
    else if(root->data == "-")
        return calc(root->left) - calc(root->right);
    else if(root->data == "*")
        return calc(root->left) * calc(root->right);
    else
        return calc(root->left) / calc(root->right);
}

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
        int n{};
        cin >> n;

        vector<string> v(n);
        for(int i{}; i < n; ++i)
            cin >> v[i];

        // for(auto itr : v)
        //     cout << itr << ' ';

        Node* root{createTree(root, v, n, 0)};
        cout << calc(root) << '\n';
        // inOrder(root);
    }    

    return 0;
}
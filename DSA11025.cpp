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

Node* buildTree(int arr[], int n, int s, int e)
{
    if(s > e)
        return nullptr;

    int mid{(s + e) / 2};
    Node* root{new Node{arr[mid]}};
    root->left = buildTree(arr, n, s, mid - 1);
    root->right = buildTree(arr, n, mid + 1, e);

    return root;
}

void preOrder(Node* root)
{
    if(!root)
        return;

    cout << root->data << ' ';
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    int test{};
    cin >> test;
    
    while(test--)
    {
        int n{};
        cin >> n;
        int arr[n]{};
        for(int i{}; i < n; ++i)
            cin >> arr[i];

        sort(arr, arr + n);

        Node* root{buildTree(arr, n, 0, n - 1)};

        preOrder(root);
        cout << '\n';
    }

    return 0;
}
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

Node* buildTree(vector<int> preOrder, vector<int> inOrder, int preS, int preE, int inS, int inE)
{
    if(preS > preE || inS > inE)
        return nullptr;

    int rootData{preOrder[preS]};

    auto itr{find(inOrder.begin(), inOrder.end(), rootData)};
    int rootIndex = itr - inOrder.begin();

    int leftInS{inS};
    int leftInE{rootIndex - 1};
    int leftPreS{preS + 1};
    int leftPreE{leftInE - leftInS + leftPreS};

    int rightInS{rootIndex + 1};
    int rightInE{inE};
    int rightPreS{leftPreE + 1};
    int rightPreE{preE};

    Node* root{new Node{rootData}};
    root->left = buildTree(preOrder, inOrder, leftPreS, leftPreE, leftInS, leftInE);
    root->right = buildTree(preOrder, inOrder, rightPreS, rightPreE, rightInS, rightInE);

    return root;
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

        vector<int> preOrder(n);
        vector<int> inOrder(n);

        for(int i{}; i < n; ++i)
            cin >> inOrder[i];
        
        for(int i{}; i < n; ++i)
            cin >> preOrder[i];

        Node* root{buildTree(preOrder, inOrder, 0, n - 1, 0, n - 1)};

        postOrder(root);
        cout << '\n';
    }

    return 0;
}
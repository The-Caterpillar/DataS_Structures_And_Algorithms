#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int key;
    Node *right;
    Node *left;

    Node(int data)
    {
        key = data;
        right = NULL;
        left = NULL;
    }
Node(){} // Default Constructor
};

int main()
{
    int a; cin>>a;
    Node *root = new Node(a);
    int data;
    cin>>data; root->left = new Node(data);
    cin>>data; root->right = new Node(data);
    cin>>data; root->left->left = new Node(data);
    cin>>data; root->left->right = new Node(data);
    // cin>>data; root->right->left = new Node(data);
    cin>>data; root->right->right = new Node(data);

return 0;
}

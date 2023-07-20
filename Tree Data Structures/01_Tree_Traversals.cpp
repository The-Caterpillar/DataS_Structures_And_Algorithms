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


// Time Complexity: O(n)
void inorder(Node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}

void preorder(Node *root)
{
    if(root!=NULL)
    {
        cout<<root->key<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->key<<" ";
    }
}

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

    cout<<"\n\nInorder Traversal= "<<endl;
    inorder(root);

    cout<<"\n\nPreorder Traversal="<<endl;
    preorder(root);

    cout<<"\n\nPost  Order Traversal="<<endl;
    postorder(root);

return 0;
}
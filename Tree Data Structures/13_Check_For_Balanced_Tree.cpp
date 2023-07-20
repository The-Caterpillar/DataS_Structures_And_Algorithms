// Children Sum Property of Binary Tree
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

int height(Node *root)
{
    if(root==NULL) return 0;
    return 1 + height(root->left) + height(root->right);
}


// O(N^2)
bool Check_For_Balanced_Tree(Node *root)
{
    // 3 2 1
    if(root==NULL) return true;
    int lh = height(root->left);
    int rh = height(root->right);

    return (abs(lh-rh)<=1 && Check_For_Balanced_Tree(root->left) && Check_For_Balanced_Tree(root->right));
}
int main()
{
    cout<<"Enter the data: ";
    int data; cin>>data;
    Node *root = new Node(data);

    cin>>data; root->left = new Node(data);
    // cin>>data; root->right = new Node(data);
    cin>>data; root->left->left = new Node(data);
    // cin>>data; root->left->right = new Node(data);
    // cin>>data; root->right->left = new Node(data);
    // cin>>data; root->right->right = new Node(data);

    if(Check_For_Balanced_Tree(root)) cout<<"True"<<endl;
    else cout<<"False"<<endl;

return 0;
}
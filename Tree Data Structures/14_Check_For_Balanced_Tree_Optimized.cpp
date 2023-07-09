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

// O(N)
int Check_For_Balanced_Tree(Node *root)
{
    if(root==NULL) return 0;

    int lh = Check_For_Balanced_Tree(root->left);
    if(lh==-1) return -1;
    int rh = Check_For_Balanced_Tree(root->right);
    if(rh==-1) return -1;

    if(abs(lh-rh)>1) return -1;
    else return max(lh,rh) + 1;
}
int main()
{
    cout<<"Enter the data: ";
    int data; cin>>data;
    Node *root = new Node(data);

    cin>>data; root->left = new Node(data);
    cin>>data; root->right = new Node(data);
    cin>>data; root->left->left = new Node(data);
    cin>>data; root->left->right = new Node(data);
    cin>>data; root->right->left = new Node(data);
    cin>>data; root->right->right = new Node(data);

    if(Check_For_Balanced_Tree(root)>0) cout<<"Balanced"<<endl;
    else cout<<"Not Balanced"<<endl;

return 0;
}
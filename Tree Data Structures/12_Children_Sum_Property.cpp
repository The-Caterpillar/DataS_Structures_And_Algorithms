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
bool Check_For_Children_Sum_Property(Node *root)
{
    // 3 2 1
    if(root==NULL) return true;
    if((root->left == NULL ) && (root->right == NULL)) return true;

    int x=0,y=0;
    if(root->left!=NULL) x = root->left->key;
    if(root->right!=NULL) y = root->right->key;

return ((x+y == root->key) && Check_For_Children_Sum_Property(root->left) && Check_For_Children_Sum_Property(root->right));
}
int main()
{
    cout<<"Enter the data: ";
    int data; cin>>data;
    Node *root = new Node(data);

    cin>>data; root->left = new Node(data);
    cin>>data; root->right = new Node(data);
    // cin>>data; root->left->left = new Node(data);
    // cin>>data; root->left->right = new Node(data);
    // cin>>data; root->right->left = new Node(data);
    // cin>>data; root->right->right = new Node(data);

    if(Check_For_Children_Sum_Property(root)) cout<<"True"<<endl;
    else cout<<"False"<<endl;

return 0;
}
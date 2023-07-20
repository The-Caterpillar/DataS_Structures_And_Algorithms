// level order traversal = Breadth First Search
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

int  height(Node *root)
{
    if(root==NULL) return 0;
    return max(height(root->left),height(root->right)) +1;
}

void printLevel(Node *root, int level)
{
    if(root==NULL) return;

    if(level==0)
    {
        cout<<root->key<<" ";
    }
    else
    {
        printLevel(root->left,level-1);
        printLevel(root->right,level-1);
    }
}

void LTraversal(Node *root)
{
    int h =  height(root);
    cout<<"Height of tree = "<<h<<endl<<endl;
    for(int i=0; i<h; ++i)
    {
        printLevel(root,i);
        cout<<endl;
    }
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

    LTraversal(root);

return 0;
}
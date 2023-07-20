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
// Right View of the Tree
int maxlevel = 0;
void Right_View(Node *root, int level)
{
    if(root==NULL) return;
            //      1
            //    2   3
            //   4 5  6 7
    if(maxlevel<level)
    {
        cout<<root->key<<" ";
        maxlevel = level;
    }
    Right_View(root->right,level+1);
    Right_View(root->left,level+1);
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

    Right_View(root,1);

return 0;
}
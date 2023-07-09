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
int maximum_width(Node *root)
{
    if(root==NULL) return 0;

    queue<Node*> q;
    q.push(root);
    int max = 0;

    while (q.size()>0)
    {
        int s = q.size();
        if(s>max) max = s;
        for(int i=0; i<s; ++i)
        {
            Node  *curr = q.front();
            q.pop();

            if(curr->left!=NULL) q.push(curr->left);
            if(curr->right!=NULL) q.push(curr->right);
        }
    }
return max;
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
    // cin>>data; root->right->right = new Node(data);

    cout<<"Maximum width = "<<maximum_width(root)<<endl;
return 0;
}
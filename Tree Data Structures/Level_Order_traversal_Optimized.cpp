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

void LTraversal(Node *root)
{
    if(root==NULL) return;
    queue<Node*> q;
    q.push(root);
    // 1 2 3
    while(!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        cout<<curr->key<<" ";

        if(curr->left!=NULL) q.push(curr->left);
        if(curr->right!=NULL) q.push(curr->right);
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
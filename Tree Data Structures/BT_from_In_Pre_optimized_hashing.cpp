// Constructing a Binary Tree from inOrder and preorder traversals- O(n)
#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int key;
    Node *left;
    Node *right;

    Node(int k)
    {
        key = k;
        left = NULL;
        right = NULL;
    }
};

void print_level_traversal(Node *root)
{
    if(root==NULL) return;
    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        int count = q.size();
        for(int i=0; i<count; ++i)
        {
            Node *curr = q.front();
            q.pop();
            cout<<curr->key<<" ";

            if(curr->left!=NULL) q.push(curr->left);
            if(curr->right!=NULL) q.push(curr->right);
        } cout<<endl;
    }
}
int main()
{
    int in[5] = {20,10,40,30,50}, pre[5] = {10,20,30,40,50};

    Node *root = construct(in,pre,0,4);

    print_level_traversal(root);
return 0;
}
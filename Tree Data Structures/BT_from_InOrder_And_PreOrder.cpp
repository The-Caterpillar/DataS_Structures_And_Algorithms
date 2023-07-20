// level order traversal = Breadth First Search
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

int pi = 0;
Node* construct_B_Tree(int in[], int pre[], int is, int ie)
{
    if(is>ie) return NULL;

    Node *root = new Node(pre[pi++]);

    int inIndex;

    for(int i=is; i<=ie; ++i)
    {
        if(root->key == in[i])
        {
            inIndex = i; break;
        }
    }

    root->left = construct_B_Tree(in,pre,is,inIndex-1);
    root->right = construct_B_Tree(in,pre,inIndex+1,ie);
return root;
}

void print(Node *root)
{
    if(root==NULL) return;
    cout<<root->key<<" ";
    print(root->left);
    print(root->right);
}

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

    Node *root = construct_B_Tree(in,pre,0,4);

    print_level_traversal(root);
return 0;
}
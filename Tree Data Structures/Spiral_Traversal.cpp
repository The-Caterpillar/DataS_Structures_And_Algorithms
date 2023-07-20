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


// Constructing a Binary Tree from inoOrder and preorder traversals- O(n^2)
int prei = 0;
Node* construct_B_Tree(int in[], int pre[], int is, int ie)
{
    if(is>ie) return NULL;

    Node *root = new Node(pre[prei++]);

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

// Printing level order traversal line by line
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

void Spiral_Traversal(Node *root)
{
    if(root==NULL) return;

    queue<Node*> q;
    q.push(root);
    bool term=0;

    while (!q.empty())
    {
        int count = q.size();
        if(!term)
        {
            for(int i=0; i<count; ++i)
            {
                Node *curr = q.front();
                q.pop();
                cout<<curr->key<<" ";
                if(curr->left!=NULL) q.push(curr->left);
                if(curr->right!=NULL) q.push(curr->right);
            }
        }
        else
        {
            stack<Node*> st;
            for(int i=0; i<count; ++i)
            {
                Node *curr = q.front();
                q.pop();
                st.push(curr);

                if(curr->left!=NULL) q.push(curr->left);
                if(curr->right!=NULL) q.push(curr->right);
            }
            while(!st.empty())
            {
                Node *a = st.top();
                st.pop();
                cout<<a->key<<" ";
            }
        }
    cout<<"\n ";
    term = !term;
    }
}

int main()
{
    int in[5] = {20,10,40,30,50}, pre[5] = {10,20,30,40,50};

    Node *root = construct_B_Tree(in,pre,0,4);

    cout<<"Level Traversal: "<<endl;
    print_level_traversal(root); cout<<endl;

    cout<<"Spiral traversal: "<<endl;
    Spiral_Traversal(root);
return 0;
}
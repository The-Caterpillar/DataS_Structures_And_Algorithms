// Binary Tree to Doubly Linked List
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
Node *curr = NULL;
Node *convert_To_Doubly(Node *root)
{
    // 1 2 3
    if(root==NULL) return NULL;

    Node *head = convert_To_Doubly(root->left);
    if(curr==NULL)
    {
        head = root;
    }
    else
    {
        root->left = curr;
        curr->right = root;
    }
    curr = root;
    convert_To_Doubly(root->right);

return head;
}

void printDoubly(Node *head)
{
    if(head==NULL) return;
    cout<<head->key<<" ";
    printDoubly(head->right);
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

    Node *head = convert_To_Doubly(root);
    printDoubly(head);
return 0;
}
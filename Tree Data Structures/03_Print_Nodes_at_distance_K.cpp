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

void print(Node *root, int distance)
{
    if(root == NULL) return;

    if(distance==0)
    {
        cout<<root->key<<" ";
    }
    else{
        print(root->left,distance-1);
        print(root->right,distance-1);
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

    cout<<"Enter the distance: ";
    int distance; cin>>distance;

    print(root,distance);

return 0;
}

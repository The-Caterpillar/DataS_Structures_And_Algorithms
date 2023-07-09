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

// O(N)
int Max(Node *root)
{
    if(root==NULL) return INT_MIN;
    return max(root->key,max(Max(root->left),Max(root->right)));
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

    cout<<"Maximum Value: "<<Max(root)<<endl;

return 0;
}
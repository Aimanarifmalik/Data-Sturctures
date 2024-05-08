#include <iostream>

#include<iostream>
using namespace std;

class Node{
    private:
    int data;
    Node *right;
    Node *left;
    public:
    Node()
    {
        this->data = 0;
        left=right=NULL;
    }
    Node(int data)
    {
        this->data = data;
        right=NULL;
        left=NULL;
    }
    friend class BST;
    friend int main();
};
class BST
{
    private:
        Node *root;

    public:
        BST()
        {
            this->root = NULL;
        }

Node* deleteNode(Node* node, int data) {
    if (node==NULL) 
    {
        return node;
    }

    
    if (data<node->data) {   //Searching for the node to be deleted
        node->left = deleteNode(node->left,data);
    } else if (data>node->data) {
        node->right = deleteNode(node->right,data);
    } else {
       
        if (node->left==NULL) {
            Node* temp1=node->right;
            delete node;
            return temp1;
        } else if (node->right==NULL) {
            Node* temp=node->left;
            delete node;
            return temp;
        }

        Node* temp=node->right;
        while (temp->left!=NULL) {
            temp=temp->left;
        }
        node->data=temp->data;
        node->right = deleteNode(node->right,temp->data);
    }
    return node;
}

// Function to print 
void inorderTraversal(Node* node) {
    if (node==NULL) return;
    inorderTraversal(root->left);
    cout<<node->data<<;
    inorderTraversal(node->right);
}

int main() {
   
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    inorderTraversal(root);
   

    // Delete a node from the binary tree
    root=deleteNode(root, 50);

    cout<<"inorder traversal after deletion: ";
    inorderTraversal(root);
    

    return 0;
}

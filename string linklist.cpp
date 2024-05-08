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

        
    Node* deleteleaf(Node *node, int data) {
        if (node == NULL) 
        {
            return node;
        }

        if (node->data == data) 
        {
            delete node;
            return NULL; // Return NULL as the parent's reference should be updated
        }

        if (node->left && node->left->data == data && node->left->left == NULL && node->left->right == NULL) {
            delete node->left;
            node->left = NULL;
            return node; // Return the node with the updated child reference
        }

        if (node->right && node->right->data == data && node->right->left == NULL && node->right->right == NULL) {
            delete node->right;
            node->right = NULL;
            return node; // Return the node with the updated child reference
        }

        if (data < node->data) {
            node->left = deleteleaf(node->left, data);
        } 
        else 
        {
            node->right = deleteleaf(node->right, data);
        }

        return node;
    }

    void inorder(Node *node) //To print
    {
        if(node==NULL)
        {
            return;
        }
        inorder(node->left);
        cout<<node->data<<"\t";
        inorder(node->right);
    }
    friend int main();
};

int main() 
{
    BST b1;
   
    b1.root = new Node(5);
    b1.root->left = new Node(3);
    b1.root->right = new Node(8);
    b1.root->left->left = new Node(2);
    b1.root->left->right = new Node(4);
    b1.root->right->left = new Node(7);
    b1.root->right->right = new Node(9);

   
    b1.deleteleaf(b1.root, 4);
    b1.deleteleaf(b1.root, 7);

    // Printing the inorder traversal
    b1.inorder(b1.root);
    cout << "\n";

    return 0;
}

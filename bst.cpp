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

        Node* insert(Node *node, int data)
        {
            if(node==NULL)
            {
                Node *temp=new Node(data);
                if(root==NULL)
                {
                    root=temp;
                }
                return temp;
            }

            if(node->data == data)
            {
                cout<<"value already present ";
                return node;
            }

            if(data > node->data)
            {
             node->right = insert(node->right,data);
            }
            else
            {
                node->left=insert(node->left,data);
            }
            return node;
        }
        Node* inorder(Node *node)
        {
            if(node==NULL)
            {
                return node;
            }
            inorder(node->left);
            cout<<node->data<<"\t";
            inorder(node->right);
        }
        
        Node* preorder(Node *node)
        {
            if(node == NULL)
            {
                return node;
            }
            inorder(node->right);
            cout<<node->data<<"\t";
            inorder(node->left);
        }
        Node* postorder(Node *node)
        {
            if(node == NULL)
            {
                return node;
            }
            inorder(node->left);
            inorder(node->right);
            cout<<node->data<<"\t";
        }
        Node*  findsibling(Node *node,int val)
        {
            if(node == NULL)
            {
                return NULL;
            }

            if(node->right!=NULL && node->right->data==val)
            {
                return node->left;
            }

            else if(node->left!=NULL && node->left->data==val)
            {
                return node->right;
            }

            if(val > node->right->data)
            {
                return findsibling(node->right,val);
            }

            else
            {
                return findsibling(node->left,val);
            }
        }

        Node* findparent(Node* node, int val)
        {
             if(node == NULL)
            {
                return NULL;
            }
             if(node->right!=NULL && node->right->data == val)
            {
                return node;
            }

             else if(node->left!=NULL && node->left->data==val)
            {
                return node;
            }
             if(val>node->right->data)
            {
                return findparent(node->right,val);
            }

            else
            {
                return findparent(node->left,val);
            }




        }

        Node* findchildern();
        friend int main();
};

int main()
{
    BST b1;

    b1.insert(b1.root, 10);
    b1.insert(b1.root, 7);
    b1.insert(b1.root, 12);
    b1.insert(b1.root, 6);
    b1.insert(b1.root, 8);
    b1.insert(b1.root, 11);
    b1.insert(b1.root, 17);


    cout<<"\n\n";
    b1.inorder(b1.root);
    cout<<"\n\n";
    b1.preorder(b1.root);
    cout<<"\n\n";
    b1.postorder(b1.root);

    cout<<"\n\n";

    Node *ptr = b1.findsibling(b1.root, 6);

    cout<<"Sibling of 6 is : "<<ptr->data<<"\n\n";

    Node *ptr2 = b1.findparent(b1.root,6);

    cout<<"Parent of 6 is : "<<ptr2->data<<"\n\n";

    return 0;
}
#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int key) {
    if (root == nullptr) return new Node(key);
    if (key < root->data) root->left = insert(root->left, key);
    else if (key > root->data) root->right = insert(root->right, key);
    return root;
}

Node* findLCA(Node* root, int n1, int n2) {
    if (root == nullptr) return nullptr;

    if (root->data > n1 && root->data > n2)
        return findLCA(root->left, n1, n2);
    if (root->data < n1 && root->data < n2)
        return findLCA(root->right, n1, n2);

    return root;
}

int findLevel(Node* root, int key, int level) {
    if (root == nullptr) return -1;

    if (root->data == key)
        return level;

    int left = findLevel(root->left, key, level + 1);
    if (left == -1)
        return findLevel(root->right, key, level + 1);

    return left;
}

int findDistance(Node* root, int n1, int n2) {
    Node* lca = findLCA(root, n1, n2);
    if (lca == nullptr) return -1;

    int d1 = findLevel(lca, n1, 0);
    int d2 = findLevel(lca, n2, 0);

    return d1 + d2;
}

int main() {
    Node* root = nullptr;
    // Example: Constructing a BST
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 30);
    insert(root, 5);
    insert(root, 15);
    insert(root, 25);
    insert(root, 35);

    int key1 = 5, key2 = 35;
    int distance = findDistance(root, key1, key2);
    if (distance != -1)
        std::cout << "Distance between " << key1 << " and " << key2 << " is: " << distance << std::endl;
    else
        std::cout << "One or both keys not present in the BST." << std::endl;

    return 0;
}



#include<iostream>
using namespace std;

class Node
{
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

        Node* insert(Node *node, int data)
        {
            if(node==NULL)
            {
                Node *temp=new Node(data);
                if(root==NULL)
                {
                    root=temp;
                }
                return temp;
            }

            if(node->data == data)
            {
                cout<<"value already present ";
                return node;
            }

            if(data > node->data)
            {
             node->right = insert(node->right,data);
            }
            else
            {
                node->left=insert(node->left,data);
            }
            return node;
        }
        Node* inorder(Node *node)
        {
            if(node==NULL)
            {
                return node;
            }
            inorder(node->left);
            cout<<node->data<<"\t";
            inorder(node->right);
        }
        
        int findDistance(Node* node, int n1, int n2)
        {
            if (node == NULL)
                return -1;

            if (node->data == n1 || node->data == n2)
                return 0;

            int leftDist = findDistance(node->left, n1, n2);
            int rightDist = findDistance(node->right, n1, n2);

            if (leftDist >= 0 && rightDist >= 0)
                return leftDist + rightDist + 2;

            if (leftDist >= 0)
                return leftDist + 1;

            if (rightDist >= 0)
                return rightDist + 1;

            return -1;
        }

        friend int main();
};

int main()
{
    BST b1;

    b1.insert(b1.root, 5);
    b1.insert(b1.root, 2);
    b1.insert(b1.root, 12);
    b1.insert(b1.root, 1);
    b1.insert(b1.root, 3);
    b1.insert(b1.root, 9);
    b1.insert(b1.root, 21);
    b1.insert(b1.root, 19);
    b1.insert(b1.root, 25);
    


    cout<<"\n\n";
    b1.inorder(b1.root);
    cout<<"\n\n";
    
    cout<<"\n\n";

    return 0;
}

#include<iostream>
#include<string>

using namespace std;

const int MAX_SUGGESTIONS = 100;

class Node
{
public:
    string word;
    int frequency;
    Node *left, *right;
    int height;

    Node(string word, int frequency)
    {
        this->word = word;
        this->frequency = frequency;
        height = 1;
        left = right = NULL;
    }
};

class AVL
{
public:
    Node *root;

    AVL()
    {
        root = NULL;
    }

    int getHeight(Node *node)
    {
        if (node == nullptr)
            return 0;

        return node->height;
    }

    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }


    int getBalance(Node *node)
    {
        if (node == NULL)
            return 0;

        return getHeight(node->left) - getHeight(node->right);
    }

    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    Node *leftRotate(Node *x)
    {
        Node *y = x->right;

        Node *T2 = y->left;

        y->left = x;

        x->right = T2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    Node *insert(Node *node, string word, int frequency)
    {
        if (node == NULL)
            return new Node(word, frequency);

        if (word < node->word)
            node->left = insert(node->left, word, frequency);

        else if (word > node->word)
            node->right = insert(node->right, word, frequency);

        else
            return node; 

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balance = getBalance(node);


        if (balance > 1 && word < node->left->word)
            return rightRotate(node);


        if (balance < -1 && word > node->right->word)
            return leftRotate(node);


        if (balance > 1 && word > node->left->word) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }


        if (balance < -1 && word < node->right->word) 
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void insert(string word, int frequency) 
    {
        root = insert(root, word, frequency);
    }

    void collectSuggestions(Node* node, const string& prefix, string* suggestions, int& count)
    {
        if (node == NULL) 
        {
            return;
        }

        collectSuggestions(node->left, prefix, suggestions, count);

        if (node->word.compare(0, prefix.length(), prefix) == 0) 
        {
            suggestions[count++] = node->word;
        }
        collectSuggestions(node->right, prefix, suggestions, count);
    }

    void getSuggestions(const string& prefix) 
    {
        string suggestions[MAX_SUGGESTIONS];
        int count = 0;
        
        collectSuggestions(root, prefix, suggestions, count);

        cout<< "Suggestions for prefix '" << prefix << "':" << endl;

        for(int i = 0; i < count; ++i) 
        {
            cout<<suggestions[i]<<"\n\n";
        }
    }


};

int main() 
{
    AVL t1;
    cout<<"\n\n";
    t1.insert("the", 200);
    t1.insert("there", 150);
    t1.insert("that", 130);

    string prefix = "th";
    
    t1.getSuggestions(prefix);

    return 0;
}
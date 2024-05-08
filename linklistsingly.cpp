#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
        Node()
        {
            data = 0;
            next = NULL;
        }
        Node(int data)
        {
            this->data = data;
            next = NULL;
        }
};

class LinkedList
{
    public:
        Node *head;
        int length;

        LinkedList()
        {
            head = NULL;
            length = 0;
        }

        void insert(int data)
        {
            Node *newnode = new Node(data);

            if(head==NULL)
            {
                head = newnode;
            }

            else
            {
                Node *temp = head;
                while(temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newnode;
            }     
            length++;
        }

        void insertat(int pos, int data)
        {
            Node *newNode = new Node(data);
            Node *temp = head;

            for(int i = 1; i<pos-1; i++)
            {
                temp = temp->next;

            }
            newNode->next = temp->next;

            temp->next = newNode;

            length++;
        }

        void remove()
        {
            Node *temp = head;

            while(temp->next->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = NULL;
            length--;
        }

        void removeat(int pos)
        {
            Node *temp = head;
            int count = 0;

            while(count<=pos-1)
            {
                
                if(temp->next->next == NULL)
                {
                    temp->next = NULL;
                    return;
                }
                
                temp = temp->next;
            }

        }

        void display()
        {
            Node *temp = head;
            cout<<"\n\n";
            while(temp != NULL)
            {
                cout<<temp->data<<"\t";
                temp=temp->next;
            }
            cout<<"\n\n";
        }
};

int main()
{
    LinkedList l1;

    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(4);
    l1.insert(5);
    cout<<"\nList: ";
    l1.display();

    l1.insertat(2, 33);

    cout<<"List after updating second position: ";
    l1.display();

    l1.remove();
    cout<<"List after removing last : ";
    l1.display();



    return 0;
}
#include<iostream>
using namespace std;

class Node
{
    private:
        int data;
        Node *next;
    public:
        Node(int data)
        {
            this->data = data;
            next = NULL;
        }

        friend class queuell;
};

class queuell
{
    private:
        Node *front;
        Node *rear;

    public:
        queuell()
        {
            front = NULL;
            rear = NULL;
        }

        void enqueue(int val)
        {
            Node *n=new Node(val);

		    if(front==NULL)
		    {
				front=n;
				front->next=NULL;
				rear=front;
		    }	
		    else
		    {
			    rear->next=n;
			    rear=n;
		    }
        }
        void dequeue()
        {
            if(front!=NULL)
		    {
			    Node *curr=front;
			    front=curr->next;
			    delete curr;
		    }	
		    else
		    {
			    cout<<"queue is underflow";
		    }
        }

        void display()
        {
            cout<<"\n\n";

            Node *temp = front;

            while(1)
            {

                cout<<temp->data<<"\t";

                if(temp->data == rear->data)
                {
                    break;
                }

                temp = temp->next;
            }
        }
};

int main()
{
    queuell q1;

    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    q1.enqueue(6);

    q1.display();

    q1.dequeue();

    q1.display();

    return 0;
}
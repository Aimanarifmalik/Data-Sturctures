#include<iostream>
using namespace std;
class Queue{

    private:
    int size;
    int *arr;
    int front;
    int rear;

    public:
    Queue(int size)
    {
        this->size = size;
        front=-1;
        rear=-1;
        arr= new int[size];
    }

   bool isempty()
	{
		if(length==0)
		{
			cout<<"queue is underflow"<<endl;
			return true;
		}
		else
		{
			return false;
		}
	}

  bool isfull()
	{
		if(length==size)
		{
			cout<<"queue is overflow"<<endl;
			return true;
		}
		else{
            return false;
        }
    }
    void print()
    {

     for(int i=front+1; i<=rear;i++)
     {
        cout<<arr[i]<<"\t";
     }

    }
    void dequeue()
    {
        if(!isfull())
        {
            front++;
        }
        else
        {
            cout<<"array is full";
        }

    }
    void enqueue( int data)
    {
        if(!isEmpty())
        {
            rear++;
            arr[rear] = data;
        }
         else
        {
            cout<<"array is empty";
        }

    }



};

int main()
{
    Queue q1(5);

    q1.enqueue(4);

    q1.enqueue(3);

    q1.enqueue(1);

    q1.print();
}
#include<iostream>
using namespace std;

class node
{
	public:
		int data;
		node *next;
	node(int val)
	{
		data=val;
		next=NULL;	
	}	
};

class stackll
{
	private:
		node *top;
		
	public:
		stackll()
		{
			top=NULL;
		}

	void push(int val)
	{
		node *n=new node(val);

		if(top==NULL)
		{
				top=n;
				top->next=NULL;
		}	
		else
		{
			n->next=top;
			top=n;
		}
	}

	int pop()
	{
		if(top!=NULL)
		{
			node *temp=top;
			top=temp->next;
			int val;
			val=temp->data;
			delete temp;
			return val;
		}	
		else
		{
			cout<<"stack is underflow";
		}
	}

	void printing()
	{
		node *curr=top;

		while(top!=NULL)
		{
			cout<<top->data<<endl;
			top=top->next;
		}
		top=curr;	
	}	

  	void reverseStack(stackll& stack2) 
	{
		stackll reversedStack;
		
		while (top != NULL) {
			reversedStack.push(pop());
		}
		stack2 = reversedStack;
	}

	
};

int main()
{
	stackll l,l2;
	l.push(1);
	l.push(2);
	l.push(3);
	l.push(4);
	l.push(5);
	cout<<" printing stack through ll"<<endl;
	l.printing();
	cout<<"-----------------------------------------------------"<<endl;
	cout<<"Pop the top value in stack"<<endl;
	l.pop();
	l.printing();
	cout<<"-------------------------------------------------------"<<endl;
	cout<<"Reverse stack"<<endl;
	l.reverseStack(l2);
	l2.printing();
}

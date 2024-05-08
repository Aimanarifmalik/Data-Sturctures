#include<iostream>
using namespace std;
class Arraylist{
	private:
	 int *arr;
	 int *curr;
	 int length;
	 int size;
	 public:
	 	Arraylist()
	 	{
	 	
	 		arr=new int[size];
	 		length=0;
	 		curr=NULL;
		 }
		void printlist()
		{
			curr=arr;
			for(int i=1;i<=size;i++)
			{
				*curr++;
				
			}
			cout<<"\n\tlist elements are: ";
		}
};
int main()
{
	int size;
	cout<<"\n enter size of array list: ";
	cin>>size;
	Arraylist a;
	a.printlist();
	
}

#include<iostream>
#include<string>
using namespace std;

class Node
{
    public:
        Node *next;
        Node *prev;
        string data;

        Node(string data)
        {
            this->data = data;
            next = NULL;
            prev = NULL;
    }
};

class CircularList
{
    private:
        Node *head;

    public:
        CircularList()
        {
            head = NULL;
        }

        void addPerson(string name)
        {
            Node *newNode = new Node(name);

            if (head == NULL)
            {
                head = newNode;
                head->next = head;
                head->prev = head;
            }
        else
        {
            newNode->next = head;

            newNode->prev = head->prev;

            head->prev->next = newNode;

            head->prev = newNode;
        }

        cout<<"\n\n"<<name<<" added!\n\n";

        printCircle();
    }

    void startEliminationProcess(string startPerson, int jumpValue)
    {
        if (head == NULL)
        {
            cout<<"\n\nNo persons in the circle to eliminate.\n\n";

            return;
        }

        Node *startNode = findPerson(startPerson);

        if(startNode == NULL)
        {
            cout<<"\n\nPerson not found in the circle!!\n\n";

            return;
        }

        cout<<"\n\nElimination sequence: \n\n";

        Node *currentPerson = startNode;

        do
        {
            for (int i = 0; i<jumpValue - 1; i++)
            {
                currentPerson = currentPerson->next;
            }

            Node *eliminatedPerson = currentPerson;

            if (eliminatedPerson == head)
                head = head->next;

            currentPerson->prev->next = currentPerson->next;

            currentPerson->next->prev = currentPerson->prev;

            currentPerson = currentPerson->next;

            cout<<"\n\n" << eliminatedPerson->data<<" has been eliminated!\n\n";

            printCircle();

        } while(head->next != head);

        cout<<"\n\nLast person standing is :  "<<head->data<<"\n\n";

        head = NULL;
    }

    Node *findPerson(string name)
    {
        if (head == NULL)
            return NULL;

        Node *temp = head;
        do
        {
            if(temp->data == name)
                return temp;

            temp = temp->next;

        } while (temp != head);

        return NULL;
    }

    void printCircle()
    {
        if (head == NULL)
        {
            cout<<"\n\nNo persons in the circle\n\n";
            return;
        }

        cout<<"\n\nCurrent persons in the circle: \n\n";

        Node *temp = head;

        int i = 0;

        do
        {
            cout<<++i<<". " << temp->data;

            temp = temp->next;
            if (temp != head)
                cout << "\n";

        } while (temp != head);

        cout<<"\n\n";
    }
};

int main()
{
    CircularList circle;

    int jumpValue;
    string name, startPerson;

    cout << "\n\n\n--------------- Josephus Problem Simulator ---------------\n";

    int choice;

    while(1)
    {
        cout<<"\n\n1. Add Person\n\n";
        cout<<"2. Start Elimination Process\n\n";
        cout<<"3. Exit\n\n";

        cout<<"Your choice : ";
        cin>>choice;

        if(choice == 1)
        {
            cout<<"\n\nEnter the name of the person: ";
            cin>>name;

            circle.addPerson(name);
        }
        else if (choice == 2)
        {
            cout<<"\n\nEnter the person you want to start from: ";
            cin>>startPerson;

            cout<<"\n\nEnter the value u want to jump: ";
            cin>>jumpValue;

            circle.startEliminationProcess(startPerson, jumpValue);
            break;
        }

        else if (choice == 3)
        {
            cout << "\n\nExiting the program\n\n";
            break;
        }

        else
        {
            cout<<"\n\nInvalid choice! Please enter a valid option\n\n";
            continue;
        }
    }
    cout<<"\n\n\n";
    return 0;
}

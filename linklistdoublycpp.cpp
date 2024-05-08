#include<iostream>
using namespace std;

class Node{
    
public:
    int info;
    Node *next;
    Node *previous;

    Node(int val)
    {
        info = val;
        next = NULL;
        previous = NULL;
    }

};

class DoublyLinkedList{
    
private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList(){
        head = NULL;
        tail = NULL;
    }

    void insert(int val){
        Node *newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
        }
    }

    void insertAt(int val, int pos){
        if(pos < 1){
            cout << "Invalid position." << endl;
            return;
        }

        Node *newNode = new Node(val);
        if(pos == 1){
            newNode->next = head;
            head->previous = newNode;
            head = newNode;
        }
        else{
            Node *temp = head;
            int count = 1;
            while(count < pos - 1 && temp != NULL){
                temp = temp->next;
                count++;
            }

            if(temp == NULL){
                cout << "Invalid position." << endl;
                return;
            }

            newNode->next = temp->next;
            newNode->previous = temp;
            if(temp->next != NULL){
                temp->next->previous = newNode;
            }
            temp->next = newNode;
        }
    }

    void remove(){
        if(head == NULL){
            cout << "List is empty." << endl;
            return;
        }

        if(head == tail){
            delete head;
            head = NULL;
            tail = NULL;
        }
        else{
            Node *temp = tail->previous;
            temp->next = NULL;
            delete tail;
            tail = temp;
        }
    }

    void removeAt(int pos){
        if(pos < 1 || head == NULL){
            cout << "Invalid position." << endl;
            return;
        }

        if(pos == 1){
            Node *temp = head;
            head = head->next;
            if(head != NULL){
                head->previous = NULL;
            }
            delete temp;
        }
        else{
            Node *temp = head;
            int count = 1;
            while(count < pos && temp != NULL){
                temp = temp->next;
                count++;
            }

            if(temp == NULL){
                cout << "Invalid position." << endl;
                return;
            }

            if(temp == tail){
                tail = tail->previous;
                tail->next = NULL;
                delete temp;
            }
            else{
                temp->previous->next = temp->next;
                temp->next->previous = temp->previous;
                delete temp;
            }
        }
    }

    void back(){
        if(tail != NULL){
            cout << "Back: " << tail->info << endl;
        }
        else{
            cout << "List is empty." << endl;
        }
    }

    void display(){
        Node *temp = head;
        while(temp != NULL){
            cout << temp->info << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){

    DoublyLinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);

    list.display();

    list.insertAt(6, 3);
    list.display();

    list.remove();
    list.display();

    list.removeAt(2);
    list.display();

    list.back();

    return 0;
}
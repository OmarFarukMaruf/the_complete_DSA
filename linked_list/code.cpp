#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class List{
    Node* head;
    Node* tail;

    public:
    List(){
        head = tail = NULL;
    }

    void push_front(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head = tail = newNode;
            return;
        } else{
            newNode->next = head;
            head = newNode;
        
        }
    }

    void push_back(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head = tail = newNode;
             return;
        } else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front() {
        
        if(head == NULL){
            cout << "List is Empty";
        } else {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void pop_back() {
         if(head == NULL){
            cout << "List is Empty";
        }else if(head == tail) {
        delete head;
        head = tail = NULL;
        } else {
            Node* temp = head;
            while(temp->next != tail) {
                temp = temp->next;
            }
    
            delete tail;
            tail = temp;
            
        }
    }

    void insert(int val, int pos){
        Node* newNode = new Node(val);
        if(pos == 0){
            push_front(val);
            return;
        }
        Node* temp = head;
        for(int i=0; i<pos-1; i++){
            temp = temp->next;
        }
        if(temp == NULL){
            cout << "Position out of bounds";
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        
    }

    void printLL(){
        Node* temp = head;

        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

};

int main(){
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_front(3);
    ll.insert(4, 1);
    ll.printLL();
}
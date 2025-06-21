#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node* nextNode;

        Node(): data(0), nextNode(nullptr){};
        Node(int val): data(val), nextNode(nullptr){};
        Node(int val, Node* next): data(val), nextNode(next){};
};

Node* createList(const vector<int>& valuse){
    if(valuse.empty()) return nullptr;
    Node* head = new Node(valuse[0]);
    Node* current = head;

    for(int i=1; i<valuse.size(); i++){
        current->nextNode = new Node(valuse[i]);
        current = current->nextNode;
    }
    return head;
};

void printL(Node* head){
    Node* temp = head;
    cout << "[" ;

   while (temp != nullptr){
        cout << temp->data << " -> ";
        temp = temp->nextNode;
   }
}

class Solution{
    public:
    Node* isCycle(Node* head){
        Node* fast = head;
        Node* slow = head;

    }

};
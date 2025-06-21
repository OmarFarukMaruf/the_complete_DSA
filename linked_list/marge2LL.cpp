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
    Node* marge2List(Node* head1, Node* head2){
         if (head1 == nullptr || head2 == nullptr){
        return head1 == nullptr ? head2 : head1;
    }
    if(head1->data < head2->data){
        head1->nextNode = marge2List(head1->nextNode, head2);
        return head1;
    }
    else{
        head2->nextNode = marge2List(head1, head2->nextNode);
        return head2;
    }
}};


int main(){

    vector<int> valuse1 = {2, 3, 5};
    vector<int> valuse2 = {3, 4, 6};

    Node* head1 = createList(valuse1);
    Node* head2 = createList(valuse2);

    Solution solution;
    Node* margeHead = solution.marge2List(head1, head2);

    printL(margeHead);

}
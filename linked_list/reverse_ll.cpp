#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
     
    ListNode(): data(0), next(nullptr) {}
    ListNode(int val) : data(val), next(nullptr) {}
    ListNode(int val, ListNode* next) : data(val), next(next) {}
};

class Solution {
    public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;

        while (current != nullptr) {
            next = current->next; // Store the next node
            current->next = prev; // Reverse the link
            prev = current;       // Move prev to current
            current = next;       // Move to the next node
        }
        return prev; // New head of the reversed list
    }
};

ListNode* createList(const vector<int>& values){
    if(values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;

    for(int i = 1; i < values.size(); i++){
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

void printL(ListNode* head){
    ListNode* temp = head;
   cout << "[" ;

   while (temp != nullptr){
        cout << temp->data << " -> ";
        temp = temp->next;
   }
}

int main(){
    vector<int> values = {1, 2, 3, 4, 5};
    ListNode* head = createList(values);

    Solution solution;
    ListNode* reversed = solution.reverseList(head);

    printL(reversed);
    return 0;
    
}

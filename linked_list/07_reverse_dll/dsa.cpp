/*
class ListNode {
public:
    int data;
    ListNode* prev;
    ListNode* next;

    ListNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};
*/

class Solution {
public:
    ListNode* reverseDLL(ListNode* head) {
        // Your code goes here
        if(head == NULL || head->next == NULL)return head;

        
        ListNode* temp = head;

        while(temp != NULL){
            ListNode* front = temp->next;
            temp->next = temp->prev;
            temp->prev = front;
            temp = front;
        }
        return head->prev;
    }
};
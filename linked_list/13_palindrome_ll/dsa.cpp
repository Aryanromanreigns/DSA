/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head){
        if(head == NULL)return NULL;
        ListNode* prev = NULL;
        ListNode* temp = head;

        while(temp != NULL){
            ListNode* front=  temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL && head->next != NULL)return true;

        ListNode* slow = head;
        ListNode* fast = head;


        while(fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* shead =  reverse( slow->next);
        ListNode* o = head;
        ListNode* t = shead;

        while( t != NULL){

            if(o->val != t->val){
                return false;
            }
            t = t->next;
            o = o->next;
                        
        }
        return true;

                
    }
};
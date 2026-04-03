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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {


        ListNode* one = l1;
        ListNode* two = l2;
        
        int carry = 0;
        ListNode* dummynode = new ListNode(-1);
        ListNode* temp = dummynode;
        while(one != NULL || two != NULL){
            int sum = carry;
            if(one) sum += one->val;
            if(two) sum += two->val;

            ListNode* node = new ListNode(sum % 10);
            carry = sum / 10;
            temp->next = node;
            temp = temp->next;
            if(one) one = one->next;
            if(two) two = two->next;


        }
        if(carry){
            ListNode* newnode = new ListNode(carry);
            temp->next = newnode;
        }
        return dummynode->next;

        
    }
};
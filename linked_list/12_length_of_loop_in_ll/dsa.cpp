/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution {
public:
    int findLengthOfLoop(ListNode *head) {
        if(head == NULL || head->next == NULL) return -1;
        ListNode * slow = head;
        ListNode * fast = head;


        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            int cnt = 1;
            if(slow == fast){
                slow = slow->next;
                while(slow != fast){
                    cnt++;
                    slow = slow->next;
                }
                return cnt;
            
            }
            
        }
        return -1;



    }
};
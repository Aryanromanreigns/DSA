/*
Definition of singly linked list:
class ListNode{
  public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};
*/

class Solution {
    public:
        ListNode* sortList(ListNode* &head) {

            if(head == NULL || head->next == NULL)return head;
            ListNode* dummyzero = new ListNode(-1);
            ListNode* dummyone = new ListNode(-1);
            ListNode* dummytwo = new ListNode(-1);

            ListNode* zero = dummyzero;
            ListNode* one = dummyone;
            ListNode* two = dummytwo;

            ListNode* temp = head;

            while(temp != NULL){
                if(temp->data == 0){
                    zero->next = temp;
                    zero = zero->next;
                }
                else if(temp->data == 1){
                    one->next = temp;
                    one = one->next;
                }
                else{
                    two->next = temp;
                    two = two->next;
                }
                temp = temp->next;
            }
            zero->next = (dummyone->next) ? dummyone->next : dummytwo->next;
            one->next =  dummytwo->next ;
            two->next = NULL;
            ListNode* newhead = dummyzero->next;
            delete dummyone;
            delete dummytwo;
            delete dummyzero;

            return newhead ;
            
        }
};
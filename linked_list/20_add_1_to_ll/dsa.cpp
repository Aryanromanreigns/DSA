
class Solution {
public:
    ListNode *reverse(ListNode * head){
        if(head == NULL || head->next == NULL)return head;
        ListNode * prev = NULL;
        ListNode * temp = head;

        while(temp != NULL){
            ListNode * front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

    ListNode *addOne(ListNode *head) {
        head = reverse(head);
        int carry = 1;

        ListNode * temp = head;

        while(temp != NULL){
            temp->data = temp->data + carry;

            if(temp->data < 10){
                carry = 0;
                break;
            }
            else{
                carry = 1;
                temp->data = 0;
            }
            temp = temp->next;
            

        }
        if(carry == 1){
            ListNode * newnode = new ListNode(carry);
            head = reverse(head);
            newnode->next = head;
            return newnode;
        }
        return reverse(head);


    }
};
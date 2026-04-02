

class Solution {
    public:
        ListNode* insertAtHead(ListNode* &head, int X) {
            ListNode * newnode = new ListNode(X,head);
            head = newnode;
            return head;

        }
};  
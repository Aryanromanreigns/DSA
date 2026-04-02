class Solution {
public:
    int getLength(ListNode* head) {
        ListNode* temp = head;
        int cnt = 0;
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
};
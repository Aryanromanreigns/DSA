/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *heada, ListNode *headb) {
        ListNode * one = heada;
        ListNode * two = headb;

        // if(head == NULL || head->next == NULL)return NULL;

        while(one != two){

            if(one == NULL){
                one = headb;
            }
            else{
                one = one->next;
            }
            if(two == NULL){
                two = heada;
            }
            else{
                two = two->next;
            }


        }
        return one;

        
    }
};
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fst = head, *slw =head;
        while(n--){
            fst=fst->next; // null 
        }
        if(!fst)return head->next;
        while(fst->next!=NULL){
            slw = slw->next;
            fst = fst->next;
        }
        
        slw->next= slw->next->next;
        return head;
        
        
    }
};
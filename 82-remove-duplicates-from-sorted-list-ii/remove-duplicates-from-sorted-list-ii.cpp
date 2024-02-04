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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * curr = head;
        ListNode* dummy = new ListNode(-1);
        ListNode * prev  = dummy ;
        while(curr){
            ListNode* fwd  = curr->next;
            int cnt = 1;
            while(fwd && fwd->val == curr->val) {
                fwd = fwd->next;
                cnt++;
            }
            if(cnt == 1){
                prev->next = curr;
                prev = prev->next;
                prev->next = NULL;
            }
            curr = fwd;
        }
        return dummy->next;
    }
};
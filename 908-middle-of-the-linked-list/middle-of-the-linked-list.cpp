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
    
    ListNode* solve(ListNode* head) {
    int ans = 0;
    int res= 0;
    ListNode* prev = NULL;
    
    ListNode* curr = head;
     ListNode *oh =NULL, *ot =NULL, *th =NULL, *tt=NULL;
    while(curr){
        if(prev ==NULL ||curr->val<=prev->val){
            if(th==NULL){
                if(prev==NULL){
                    th = curr;
                }
                else{
                    th = prev;
                    
                }
                
            }
           
            res++;
        }
        else{
            th = NULL;
            tt= NULL;
            res  = 1;
        }
        prev = curr;
        if(res>ans){
            oh = th;
           
            tt = curr;
            ot = tt;
            ans = res;
        }
         curr = curr->next;
        
        
    }
    ot->next = NULL;
    return oh;
    
}
    
    
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* sl = head;
        ListNode* fs = head;
        while(fs && fs->next) {
            sl= sl->next;
            fs = fs->next->next;
        }
        return sl;
    }
};
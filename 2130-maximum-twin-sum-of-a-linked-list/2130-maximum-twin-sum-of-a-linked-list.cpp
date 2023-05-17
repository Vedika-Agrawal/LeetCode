class Solution {
public:
    
     ListNode* middleNode(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode* fst= head, *slw = head;
        while(fst!=NULL && fst->next!=NULL){
            slw= slw->next;
            fst= fst->next->next;
        }
        return slw;
        
    }
    
     ListNode* solve(ListNode* head) {
        ListNode* prev=NULL, *curr = head;
        while(curr!=NULL){
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr= tmp;
        }
        return prev;
        
        
    }
    
    int pairSum(ListNode* head) {
        ListNode* mid = NULL;
        

        ListNode* prev = NULL;
        mid =  middleNode(head);
        prev = solve(mid);
        mid->next =NULL;
        //Reversing Part
        // ListNode* nextNode = NULL;
        // ListNode* prev = NULL;
        // while(mid) {
        //     nextNode = mid->next;
        //     mid->next = prev;
        //     prev = mid;
        //     mid = nextNode;
        // }
        
        
        //Reversing Part
        
        ListNode* curr = head;
        int result = 0;
        while(prev) {
            result = max(result, curr->val + prev->val);
            curr = curr->next;
            prev = prev->next;
        }
        
        return result;
        
    }
};
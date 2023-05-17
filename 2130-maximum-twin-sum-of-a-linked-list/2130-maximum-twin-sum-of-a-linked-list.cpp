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
    
    int pairSum(ListNode* head) {
        ListNode* mid = NULL;
        

        
        mid =  middleNode(head);
        
        //Reversing Part
        ListNode* nextNode = NULL;
        ListNode* prev = NULL;
        while(mid) {
            nextNode = mid->next;
            mid->next = prev;
            prev = mid;
            mid = nextNode;
        }
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
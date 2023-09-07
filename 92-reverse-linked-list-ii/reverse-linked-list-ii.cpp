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
    ListNode* reverse(ListNode*head){
        ListNode* curr = head, *prev = NULL;
        while(curr){
            ListNode* fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int i = 1;
        ListNode* curr = head, *prev = NULL;
        while(i<right){
            if(i==left-1){
                prev  = curr ;
            }
            curr = curr->next;
            i++;
        }
        ListNode* fwd = curr->next;
        curr->next = NULL;
        if(prev==NULL){
            head  =  reverse(head);
            prev = head;
            
        }
        else{
            prev->next =  reverse(prev->next);
        }

        ListNode* temp = head;
        while(temp->next){
            temp = temp->next;
        }
        temp->next  = fwd;
        return head;
    }
};
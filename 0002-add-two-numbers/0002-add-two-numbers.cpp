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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL || l2==NULL)return l1==NULL? l2: l1;
        ListNode * dummy = new ListNode;
        
        ListNode* a=l1,*b=l2,*curr=dummy;
        int carr = 0;
        
        while(a || b || carr ){
            int sum = carr + (a? a->val:0)+ (b ? b->val : 0);
            int rem =  sum%10;
            carr = sum/10;
            curr->next = new ListNode(rem);
            curr=curr->next;
            a = a ? a->next : a;
            b = b ? b->next : b;
            
        }
        return dummy->next;
    }
};
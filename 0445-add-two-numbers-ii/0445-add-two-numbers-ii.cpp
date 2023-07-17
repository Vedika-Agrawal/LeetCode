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
    ListNode* reverse(ListNode* root){
        if(root==nullptr || root->next==nullptr)return root;
        ListNode* curr = root, *prev = NULL;
        while(curr){
            ListNode* fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==nullptr || l2==nullptr)  return l1==nullptr? l2:  l1;
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode* curr1=l1, *curr2 =l2;
        int carry= 0 ;
        ListNode * dummy = new ListNode;
        ListNode* prev = dummy;
    
        while(curr1 || curr2 || carry){
            int sum = carry;
            sum += !curr1 ? 0 : curr1->val;
            sum += !curr2 ? 0 : curr2->val;
            if(curr1!=nullptr)curr1=curr1->next;
            if(curr2!=nullptr)curr2=curr2->next;
             prev->next = new ListNode(sum%10);
           
            prev = prev->next;
            carry = sum/10;
            
            
        }
        return reverse(dummy->next);
    }
};
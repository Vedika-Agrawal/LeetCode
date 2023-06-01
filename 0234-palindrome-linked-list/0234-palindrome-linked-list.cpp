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
    ListNode* midNode(ListNode* head) {
        ListNode *slw = head, * fst = head;
        while(fst->next && fst->next->next){
           slw = slw->next;
            fst = fst->next->next;
        }
        return slw;
    }
    ListNode *reverse(ListNode* head){
      if(head==nullptr || head->next==nullptr){
          return head;
      } 
      ListNode *prev = nullptr;
      ListNode *curr = head;
      ListNode *fwd = head; 
      while(curr!=nullptr){
          fwd = curr->next;
          curr->next=prev;
          prev= curr;
          curr =fwd;
      }
      return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
          return true;
      } 
        ListNode *mid = midNode(head);
        ListNode *nhead = mid->next;
        mid->next=nullptr;
        nhead = reverse(nhead);
        ListNode *c1 = head;
        ListNode *c2 = nhead;
        while(c2!=nullptr){
            if(c1->val !=c2->val)return false;
            c1= c1->next;
            c2=c2->next;
        }
        return true;
    }
};
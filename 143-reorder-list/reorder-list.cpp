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
    ListNode* midNode (ListNode* head){
        ListNode* s = head, *f = head;
        while(f && f->next && f->next->next){
            s = s->next;
            f = f->next->next;
        }
        return s;
    }
    ListNode* reverseList(ListNode* head){
        if(head==nullptr || head->next==nullptr){
            return head;
        } 
        ListNode* p = NULL, * curr = head;
        while(curr){
            ListNode* f = curr->next;
            curr->next = p;
            p = curr;
            curr = f;
        }
        return p;
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next)return;
        ListNode* mid = midNode(head);
        ListNode *nhead = mid->next;
        mid->next=nullptr;
        nhead = reverseList(nhead);
        mid->next = NULL;
        ListNode* c1 = head;
        ListNode* c2 = nhead;
        while(c1 && c2 ){
            ListNode* f1 = c1->next;
            ListNode* f2 = c2->next;
            c1->next = c2;
            c2->next = f1;
            c1 = f1;
            c2 = f2;
        }
    }
};
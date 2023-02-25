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
    void addFirst(int data, ListNode* &nhead){
        ListNode* temp = new ListNode;
        temp->val = data;
        temp->next= nhead;
        nhead = temp;
        
        
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* nhead  = new ListNode;
        ListNode* curr = head;
        while(curr!=NULL){
            // cout<<curr->val<<" aaaaa"<<endl;
            addFirst(curr->val, nhead->next);
            curr = curr->next;
        }
        return nhead->next;
        
        
    }
};
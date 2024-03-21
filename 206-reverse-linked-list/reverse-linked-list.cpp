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
    ListNode* head = NULL;

    void addFirst(ListNode* node){
        //  if(head==NULL){
        //     node->next = NULL;
        //     head = node;
        //     return;
        // }
        node->next = head;
        head = node;
    }

    void deleteFirst(ListNode* node){
        node = node ->next;
    }
    ListNode* reverseList(ListNode* node) {
        ListNode * curr = node;
        while(curr){
            ListNode * fwd = curr ->next;
            addFirst(curr);
            // deleteFirst(curr);
            curr = fwd;
        }
        return head;
    }
};
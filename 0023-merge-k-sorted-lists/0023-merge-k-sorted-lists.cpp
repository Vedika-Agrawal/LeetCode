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

struct compare {
    bool operator()(const ListNode* l, const ListNode* r) {
        return l->val > r->val;
    }
};
class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare > q;
        for(auto it: lists){
            if(it!=nullptr){
                q.push(it);
            }
        }
        ListNode* dummy = new ListNode;
        ListNode * prev = dummy;

        while(!q.empty()){
            ListNode* temp = q.top();
            q.pop();
            prev->next = temp;
            prev= prev->next;
            temp=temp->next;
            if(temp!=nullptr){
                q.push(temp);
                
            }
        }
        return dummy->next;
    }
};
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
    ListNode* node = NULL;
    Solution(ListNode* head) {
        node = head;
    }
    
    int getRandom() {
        int i {};
        auto curr = node;
        ListNode* randomPointer = NULL;
        while(curr){
            ++i;
            int randomIdx  = rand() % i;
            if( i-1 == randomIdx ) randomPointer = curr;
            curr= curr->next;
        }
        return randomPointer->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
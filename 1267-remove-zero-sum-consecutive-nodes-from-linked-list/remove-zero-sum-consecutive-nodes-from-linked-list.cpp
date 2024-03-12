class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode dummy(0); // Create a dummy node to handle cases where the entire list sums to zero
        dummy.next = head;
        ListNode* curr = head;
       
        int pref = 0;
        unordered_map<int, ListNode*> mp;
        while (curr) {
            pref += curr->val;
            mp[pref] = curr;
            curr = curr->next;
        }
        
        pref = 0;
        curr = &dummy; // Start from the dummy node
        while (curr) {
            pref += curr->val;
            if (mp.find(pref) != mp.end() && mp[pref] != curr) { // If prefix sum exists and not pointing to the same node.
                curr->next = mp[pref]->next;
            }
            curr = curr->next;
        }
        
        return dummy.next ? dummy.next : nullptr; // Return head if it's not null, otherwise return nullptr
    }
};

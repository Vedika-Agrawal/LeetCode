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
    ListNode* nhead = NULL;
    ListNode* prev = NULL;

    void addLast(int sum) {
        ListNode* node = new ListNode(sum);
        if (prev == NULL) {
            nhead = node;
            prev = node;
        } else {
            prev->next = node;
            prev = node;
        }
    }

    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head;
        while (curr != NULL) {
            int sum = 0;
            if (curr->val == 0) {
                curr = curr->next;
                while (curr != NULL && curr->val != 0) {
                    sum += curr->val;
                    curr = curr->next;
                }
                if (sum != 0) {
                    addLast(sum);
                }
            }
        }
        return nhead;
    }
};

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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *curr = list1, *prev = NULL;
        ListNode *st = NULL, *end = NULL;
        int cnt = 0;
        while (curr) {
            cnt++;
            if (cnt == a) {
                st = curr;
            }
            if (cnt == b+1) {
                end = curr;
            }
            curr = curr->next;
        }
        curr = list2;
        while (curr && curr->next)
            curr = curr->next;
        st->next = list2;
        curr->next = end->next;
        // curr->next = end->next;
        return list1;
    }
};
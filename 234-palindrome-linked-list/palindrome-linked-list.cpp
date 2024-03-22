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
    ListNode* findMid(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* fwd = head;
        while (curr != nullptr) {
            fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        ListNode *mid = findMid(head);
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
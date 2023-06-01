/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *l1, ListNode *l2) {
        int cnt1 = 0;
        int cnt2 = 0;
        ListNode* c1= l1, *c2= l2;
        while(c1){
            cnt1++;
            c1 = c1->next;
        }
        while(c2){
            cnt2++;
            c2= c2->next;
        }
        c1=l1, c2=l2;
        int diff = abs(cnt1-cnt2);
        if(cnt1>cnt2){
            while(diff--){
                c1= c1->next;
            }
        }
        else{
            while(diff--){
                c2=c2->next;
            }
        }
        while(c1!=c2){
           c1=c1->next;
            c2=c2->next;
        }
        return c1;
        
    }
};
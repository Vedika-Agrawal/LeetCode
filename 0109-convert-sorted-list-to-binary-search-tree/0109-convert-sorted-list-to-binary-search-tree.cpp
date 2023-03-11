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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    ListNode *prev = NULL;
    ListNode* findMiddle(ListNode* head){
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *prev =NULL; 
        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            prev =slow;
            slow=slow->next;
        }
        
        if(prev != NULL)
            prev->next = NULL;
        return slow;
       
        
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)return NULL;
        if(head->next == NULL) return new TreeNode(head->val);
        ListNode* midNode = findMiddle(head);
       
        TreeNode* root = new TreeNode (midNode->val);
        
       
        root->right = sortedListToBST(midNode->next);
        midNode->next = NULL;
         root->left  = sortedListToBST(head);
        return root;
    }
};
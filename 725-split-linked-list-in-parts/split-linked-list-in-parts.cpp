
class Solution {
public:
    int calc(ListNode* head){
        int cnt  = 0;
        ListNode* curr = head;
        while(curr){
            cnt++;
            curr = curr->next;
        }
        return cnt;
    }
    void seperate(ListNode* head, vector<ListNode*>&ans, int sz, int k){
        ListNode* curr = head;
        while(curr){
            ListNode* fwd = curr->next;
            curr->next = NULL;
            ans.push_back(curr);
            curr = fwd;
        
        }
        while(sz<k){
          ans.push_back(NULL);
          sz++;  
        }
    }

    void addK(ListNode* &head, int k, int times, vector<ListNode*>&ans){
        ListNode* curr = head;
        while(times--){
            int p = k;
            p--;
            ListNode* ccc = curr;
            while(p--){
                curr = curr->next;
            }
            ListNode* fwd = curr->next;
            curr->next = NULL;
            ans.push_back(ccc);
            curr = fwd;

        }
        head = curr;
        
    }

    void solve(ListNode* head, vector<ListNode*>&ans, int k, int sz){      
        int len = sz/k;
        int rem = sz%k;
        addK(head, len+1, rem, ans);
        addK(head,len, k-rem,ans);

    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int sz = calc(head);
        vector<ListNode*>ans;
        if(sz<=k){
            seperate(head, ans,sz,k);
        }
        else{
            solve(head, ans, k,sz);
        }
        return ans;
    }
};
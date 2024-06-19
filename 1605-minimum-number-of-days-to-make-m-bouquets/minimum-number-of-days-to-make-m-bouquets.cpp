class Solution {
public:

    bool isPossible(vector<int>& bloom, int m, int k, int mid){
        int cnt = 0 ;
        int i = 0, n = bloom.size();
        while(i<n && cnt<m){
            int j = i;
            int tmp_cnt = 0;
            bool check = 0;
            while(j<n && bloom[j]<=mid && tmp_cnt<k){
                j++;
                tmp_cnt++;
                check = 1;
            }
            if(tmp_cnt==k)cnt++;
            if(check==0){
                i = j+1;
            }
            else
            i = j;

        }
        if(cnt==m)return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l = 1, h = 1e9;
        int ans = -1;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(isPossible(bloomDay, m, k, mid)){
                ans = mid;
                h = mid -1;
            }
            else {
                l = mid + 1;
            }
        }
    
        return ans;

    }
};
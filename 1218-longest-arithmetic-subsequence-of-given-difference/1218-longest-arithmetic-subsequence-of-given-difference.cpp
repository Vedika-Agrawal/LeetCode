class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n=arr.size();
        int ans=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            int val =arr[i]-difference;
            if(mp.count(val )){
                mp[arr[i]]=mp[val ]+1;
            }
            else{
                mp[arr[i]]=1;
            }
            ans=max(mp[arr[i]],ans);
        }
        return ans;
    }
};
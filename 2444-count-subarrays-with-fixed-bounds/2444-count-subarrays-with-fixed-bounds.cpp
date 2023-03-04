class Solution {
public:
    long long countSubarrays(vector<int>& v, int minK, int maxK) {
        int mini=-1, maxi= -1, left=-1;
        long long ans=0;
        for(int i=0;i<v.size();++i){
            int ele = v[i];
            if(ele==minK)mini = i;
            if(ele==maxK)maxi= i;
            if(ele<minK || ele>maxK)left =i;
            ans +=max(0, min(mini,maxi)-left) ;
        }
        return ans;
    }
}; 
class Solution {
public:
    int trap(vector<int>& v) {
        vector<int>left,right;
        int n = v.size();
        int a = v[0];
        for(int i=0;i<n;i++){
            a= max(a,v[i]);
            left.push_back(a);
            // left.push_back(max(a,v[i]));
        }
        a = v[n-1];
        for(int i=n-1;i>=0;i--){
            
            a= max(a,v[i]);
            right.push_back(a);
        }
        reverse(right.begin(),right.end());
        int ans = 0;
        
        for(int i= 0;i<n;i++){
            ans+= min(left[i],right[i])-v[i];
        }
        return ans;
    }
};
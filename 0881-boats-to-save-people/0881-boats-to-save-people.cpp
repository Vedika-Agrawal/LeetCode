class Solution {
public:
    int numRescueBoats(vector<int>& v, int limit) {
        sort(v.begin(),v.end());
        int i = 0, j = v.size()-1;
        int cnt  =0;
        while(i<=j){
            int sum = v[i] + v[j];
            if(sum> limit)cnt++,j--;
            else{
                i++;
                j--;
                cnt++;
            }
        }
        return cnt;
        
        
    }
};
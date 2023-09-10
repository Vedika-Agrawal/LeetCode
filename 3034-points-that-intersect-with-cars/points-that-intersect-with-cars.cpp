class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int>v(101,0);
        for(auto it: nums){
            int st= it[0];
            int end  = it[1];
            for(int i =st; i<=end;i++)v[i]= 1;
        }
        return accumulate(v.begin(),v.end(),0);
    }
};
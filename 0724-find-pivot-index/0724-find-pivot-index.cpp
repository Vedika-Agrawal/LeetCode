class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int>p,s;
        int curr = 0,suff=0;
        for(int i=0;i<nums.size();i++){
            curr += nums[i];
            suff+= nums[nums.size()-i-1];
            s.push_back(suff);
            p.push_back(curr);
            cout<<suff<< " "<< curr<<endl;
            
        }
        reverse(s.begin(),s.end());
        for(int i=0; i<nums.size();i++){
            if(s[i]==p[i])return i;
        }
        return -1;
    }
};
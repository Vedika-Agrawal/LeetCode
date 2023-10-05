class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ans1 = INT_MIN, cnt1= 0;
        int ans2 = INT_MIN, cnt2 =0;
        
        for(auto it: nums){
            
            if(ans1==it)cnt1++;
            else if(ans2==it)cnt2++;
            else if(cnt1==0){
                ans1 = it;
                cnt1++;
            }
            else if(cnt2==0){
                ans2 = it;
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        
        cout<<ans1<<" "<<ans2<<endl;
        vector<int>res;
        cnt1=0, cnt2= 0 ;
        for(auto it: nums){
            if(it==ans1)cnt1++;
            if(it==ans2)cnt2++;
        }
        if(cnt1 > nums.size()/3)res.push_back(ans1);
        if(cnt2 > nums.size()/3)res.push_back(ans2);
        return res;
    }
};
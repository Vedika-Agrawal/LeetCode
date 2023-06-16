int solve(vector<int>& nums,int idx,int prev){
if(idx>=nums.size()){
return 0;
}
if(dp[idx][prev +1]!=-1){
return dp[idx][prev+1];
}
int not_take=solve(nums,idx+1,prev);
int take=0;
if(prev==-1 || nums[idx] > nums[prev]){
take=1+solve(nums,idx+1,idx);
}
return dp[idx][prev+1]=max(take,not_take);
}
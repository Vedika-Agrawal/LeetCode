//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	vector<int>inc, des;
	int n;
	
	void increasing(vector<int>&nums){
	    for(int i=0;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(nums[j]<nums[i] && inc[j]+1>inc[i]){
	                inc[i]= inc[j]+1;
	            }
	        }
	    }
	    
	}
	
	void decreasing(vector<int>&nums){
	    for(int i= n-1; i>=0;i--){
	        for(int j= n-1; j>i;j--){
	            if(nums[j]<nums[i] && des[j]+1>des[i]){
	                des[i]= des[j]+1;
	            }
	        }
	    }
	}
	
	int LongestBitonicSequence(vector<int>nums)
	{
	    n = nums.size();
	    
	    inc.resize(n,1);
	    des.resize(n,0);
	    increasing(nums);
	    decreasing(nums);
	   // for(auto it: inc)cout<<it<<" ";
	   // cout<<endl;
	   // for(auto it: des)cout<<it<<" ";
	   // cout<<endl;
	   int ans = 0;
	   for(int i=0;i<n;i++){
	       ans = max(ans, inc[i]+des[i]);
	   }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
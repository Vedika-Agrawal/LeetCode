class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
       long long streak = 0;
		long long zeroArrays = 0;
		for(auto x: nums){
			if(x == 0){
				streak++;
			}else{
				if(streak){
					zeroArrays += (streak)*1LL*(streak+1)/2;
				}
				streak = 0;
			}
		}
		if(streak){
			zeroArrays += (streak)*1LL*(streak+1)/2;
		}
		return zeroArrays;
    }
};


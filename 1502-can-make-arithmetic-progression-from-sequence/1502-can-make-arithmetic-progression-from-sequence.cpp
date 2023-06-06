class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int first = arr[0];
        int sec   = arr[1];
        int diff = sec-first;
        for(int i=2;i<arr.size();i++){
            int ele = arr[i];
            int temp_diff = ele - sec;
            if(diff!=temp_diff)return false;
            sec=  ele;
            
        }
        return true;
    }
};
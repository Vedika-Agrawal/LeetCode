class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int>mp;
        for(auto it: arr){
            mp[it]++;
        }
        arr.clear();
        for(auto it: mp ){
            arr.push_back(it.second);
        }
        sort(arr.begin(),arr.end());
        int ans = arr.size(); 
        int i = 0;
        while(i<arr.size() && k>=0){
            if(arr[i]<=k){
                ans--;
                k-= arr[i];
            }
            else{
                break;
            }
            i++;

        }
        return ans;

    }
};
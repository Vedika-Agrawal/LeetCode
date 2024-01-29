class Solution {
public:
    int mod = 1e9+7;
    int threeSumMulti(vector<int>& arr, int t) {
        sort(arr.begin(),arr.end());
        int ans =0;
        int n = arr.size();
        for(int i=0;i<n-2;i++){
            int temp = t - arr[i];
            int l = i+1, h = n-1;
            while(l<h){
                if(temp==arr[l]+arr[h]){
                    long long sc = 1, ec = 1;
                    while(l< h && arr[l] == arr[l+1]){
                        l++;
                        sc++;
                    }
                    while(l <h && arr[h] == arr[h-1]){
                        h--;
                        ec++;
                    }
                    if(l == h){
                        long long temp = (sc*(sc-1))/2; //nC2
                        ans = (ans + temp) % mod;
                    }
                    else{
                        ans = ans + (sc*ec) % mod;
                    }
                    l++;
                    h--;

                }
                else if(temp < arr[l]+arr[h]) h--;
                else l++;
            }
        }
        return ans;
    }
};
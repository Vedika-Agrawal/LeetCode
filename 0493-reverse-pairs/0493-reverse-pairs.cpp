class Solution {
public:
    #define ll long long 
    
    ll mergeTwo(ll st, ll end, ll mid, vector<int>&arr){
        vector<ll>temp;
        ll l=st, r = mid+1;
        ll cnt = 0;
        
        while(l<=mid && r<=end){
            if((ll)arr[l]>(ll)arr[r]*2){
                cnt += mid- l+1;
                // temp.push_back(arr[r]);
                r++;
            }
            else{
                // temp.push_back(arr[l]);
                l++;
            }
        }
        l = st, r = mid+1;
        while(l<=mid){
            temp.push_back(arr[l]);
            l++;
        }
         while(r<=end){
            temp.push_back(arr[r]);
            r++;
        }
        sort(temp.begin(), temp.end());
        int k =0 ;
        for(ll i = st; i<=end; i++){
            arr[i] = temp[k];
            k++;
        }
        return cnt;
        
        
    }

    ll mergesort(ll st, ll end, vector<int>&arr){
        ll cnt= 0;
        if(st<end){
            ll mid = (st+end)/2;
            cnt += mergesort(st, mid, arr);
            cnt += mergesort(mid+1,end, arr);
            cnt += mergeTwo(st,end,mid,arr);
        }
        return cnt;
    }
    
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
         return mergesort(0, n-1, nums);
    }
};
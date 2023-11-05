class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int ele = *max_element(arr.begin(),arr.end());
        if(k>=arr.size())return ele;
        int cnt =0 ;
        int mx = arr[0];
        for(int i=1;i<arr.size();i++){
            if(arr[i]<mx){
                cnt++;
            }
            else{
                cnt = 1;
                mx = arr[i];
            }
            if(cnt==k || mx == ele)return mx;
        }
        return ele;

    }
};
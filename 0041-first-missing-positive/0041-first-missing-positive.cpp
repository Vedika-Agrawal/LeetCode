class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]<=0 || arr[i]>n+1){
                // cout<<arr[i]<<" "<<i<<endl;
                arr[i]= n+1;
            }
        }
       
        
        for(int i=0;i<n;i++){
            if(abs(arr[i])<=n){
                
                int idx = abs(arr[i])-1;
                cout<<idx<<" "<<arr[i]<<endl;
                if(arr[idx]>0)arr[idx]*=-1;
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                return i+1;
            }
        }
        return n+1;
    }
};
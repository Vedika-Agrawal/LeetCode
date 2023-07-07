class Solution {
public:
    
    bool isPossible(string s, int mid, int k){
        int n = s.size();
        int t= 0, f= 0;
        for(int i=0;i<mid;i++){
            if(s[i]=='T')t++;
            else f++;
        }
        int mini = min(t,f);
        if(mini<=k)return true;
        
        int i= 0;
        while(mid<n){
            if(s[mid]=='T')t++;
            else f++;
            
            if(s[i]=='T')t--;
            else f--;
            
            int mini = min(t,f);
            if(mini<=k)return true;
            i++;
            mid++;
            
        }
        return false;
    }
    int maxConsecutiveAnswers(string s, int k) {
      int l = 1, h =  s.size();
        int ans = 0;
        while(l<=h){
            int mid = (l+h)/2;
            if(isPossible(s, mid, k)){
                ans = mid;
                 l = mid+1;
            }
            else{
                h = mid -1;
            }
        }
        return ans;
    }
};
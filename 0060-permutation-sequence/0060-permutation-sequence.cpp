class Solution {
public:
    string getPermutation(int n, int k) {
        k--;
        string ans ="";
        vector<int>v;
        int fact =1;
        
        for(int i=1;i<n;i++){
            v.push_back(i);
            fact *= i;
        }
        v.push_back(n);
        
        while(true){
            int idx  = k / fact;
            ans += to_string(v[idx]);
            v.erase(v.begin()+idx);
            if(v.size()==0)break;
            
            k %= fact;
            fact/=v.size();
        }
        
        
        
        return ans;
        
    }
};
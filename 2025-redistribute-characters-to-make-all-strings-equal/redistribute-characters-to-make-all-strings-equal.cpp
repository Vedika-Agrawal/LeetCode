class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int  n = words.size();
        vector<int>v(26,0);
        for(auto it: words){
            for(auto i : it){
                v[i-'a']++;
            }
        }
        for(int i=0;i<26;i++){
            if(v[i]!=0 &&  v[i]%n!=0)return false;
        }
        
        return true;
        
    }
};
class Solution {
public:
    string customSortString(string o, string s) {
        vector<int>v(26);
        for(auto it: s){
            v[it-'a']++;
        }
        string ans = "";
        for(auto it : o){
            int freq = v[it-'a'];
            if(freq!=0){
                while(freq--){
                    ans+= it;
                }
                v[it-'a'] = 0;
            }
            
        }
        for(int i=0;i<26;i++){
            int times = v[i];
            char ch = i + 'a';
            while(times--){
                ans += ch;
            }
        }
        return ans;
    }
};
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string>st[26];
        for(auto it : ideas){
            st[it[0]-'a'].insert(it.substr(1));
        }
        
        long long ans = 0;
        for(int i=0;i<25;i++){
            for(int j=i+1;j<26;j++){
                int mutual = 0;
                for(auto it : st[i]){
                    if(st[j].count(it))mutual++;
                }
                ans+= 2LL* (st[i].size()-mutual)* (st[j].size()-mutual);
            }
            
        }
        return ans;
        
    }
};
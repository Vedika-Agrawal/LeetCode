class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n = s.size();
        
        if(s.size()!=goal.size())return false;
        int cnt  =0 ;
        vector<int>v;
        
        for(int i=0;i<s.size();i++){
            
            if(s[i]!=goal[i]){
                
                cnt++;
                v.push_back(i);
            }
        }
        if(cnt!=0 && cnt != 2)return false;
        
        cout<<cnt;
        if(cnt==2){
            cout<<"aaa";
            swap( s[v[0]], s[v[1]]);
            if(s==goal)return true;
            else
                return false;
        }
        unordered_map<char,int>mp;
        for(auto it: s){
            mp[it]++;
            if(mp[it]>1)return true;
        }
        return false;
    }
};
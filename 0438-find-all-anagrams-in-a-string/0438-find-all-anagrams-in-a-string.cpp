class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ns = s.size();
        int np =p.size();
        vector<int>ans;
        if(np>ns)return {};
        
        // vector<int> arr_p(26,0);
        // vector<int> arr_s(26,0);
        
        unordered_map<char,int>arr_p,arr_s;
        
        
        
        for(int i=0;i<np;i++){
            
            arr_p[p[i]]++;
            arr_s[s[i]]++;
        }
        
        if(arr_p==arr_s)ans.push_back(0);
        
        for(int i=np;i<ns;i++){
            arr_s[s[i-np]]--;
            if(arr_s[s[i-np]]==0) arr_s.erase(s[i-np]);
            arr_s[s[i]]++;
            if(arr_p==arr_s)ans.push_back(i-np+1);
            
        }
        return ans;
        
        
    }
};
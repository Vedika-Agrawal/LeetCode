class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        for(auto it : t) mp[it]++;
        int count = t.size();
        int n = s.size();
        int i= 0, j = 0;
        int mnLen = INT_MAX;
        int st_ans = 0 ;

        while(i<n){
            if(mp[s[i]]>0)count--;
            mp[s[i]]--;
            i++;

            while(count==0){
                if(i-j< mnLen) {
                    mnLen  = i- j;
                    st_ans = j;
                }
                mp[s[j]]++;

                if(mp[s[j]]>0)count++;

                j++;
            }

        }
        if (mnLen != INT_MAX)
		    return s.substr(st_ans, mnLen);
	    return "";  
    }
};
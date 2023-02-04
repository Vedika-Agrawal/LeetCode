class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        if(n>s2.size())return false;
        sort(s1.begin(),s1.end());
        
        // cout<<s1<<endl;
        
        for(int i=0;i<=s2.size()-n;i++){
            cout<<i<<" "<<n<<endl;
            string str = s2.substr(i,n);
            // cout<<str<<endl;
            sort(str.begin(),str.end());
            if(str==s1)return true;
        }
        return false;
    }
};
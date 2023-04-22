class Solution {
public:
   
  int LPS_Bottom_Up(string s, int n) {
        vector<vector<int>> t(n, vector<int>(n));
        //t[i][j] = longest common subsequence in string from i to j indices;
        //strings of length 1 are always a palindorme
        for(int i = 0; i<n; i++) {
            t[i][i] = 1;
        }
        
        for(int L = 2; L<=n; L++) {
            for(int i = 0; i<n-L+1; i++) {
                int j = i + L - 1;
                
                if(s[i] == s[j] && L == 2)
                    t[i][j] = 2;
                else if(s[i] == s[j]) {
                    t[i][j] = 2 + t[i+1][j-1];
                } else {
                    t[i][j] = max(t[i+1][j], t[i][j-1]);
                }
            }
        }
        return t[0][n-1];
    }
    int minInsertions(string s) {
    
        int ans = s.size();
        int m = s.size();
        // vector<vector<int>> t(m+1, vector<int>(m+1));
        ans -= LPS_Bottom_Up(s,m);
        return ans;
    }
};
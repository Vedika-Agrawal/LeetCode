class Solution {
public:
    #define ll long long
    int m; // target ki lenght 
    int k ; // per word ki lenght
    const int MOD = 1e9+7;
    int t[1001][1001];
    
    
    int solve(int i, int j, vector<vector<ll>>&freq, string &tar){
        if(i==m)return 1;
        if(j==k)return 0;
        
        if(t[i][j] != -1)
            return t[i][j];
        
        int notTaken = solve(i, j+1, freq, tar)%MOD;
        int taken = (solve(i+1, j+1, freq,tar)  * (freq[tar[i]-'a'][j]))%MOD;
        
         return t[i][j] = (notTaken + taken)%MOD;
    }
    
   
    
    int numWays(vector<string>& word, string tar) {
         m = tar.size();
         k = word[0].size();
        
        vector<vector<long long>>freq(26, vector<long long>(k));
        
        for(int col =  0 ; col<k; col++){
            for(string &str : word){
                freq[str[col]-'a'][col]++;
            }
        }
        memset(t, -1, sizeof(t));
        
        return solve(0, 0, freq, tar);
        
        
       
        
    }
};
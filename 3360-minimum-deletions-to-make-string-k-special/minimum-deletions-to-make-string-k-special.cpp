class Solution {
public:
    
    int solve( vector<int>&v, int i, int j,int k){
        if(i>=j)return 0;
        if(v[j]-v[i]<=k)return 0;
        
        // delete for start
        int a = v[i] + solve( v, i+1, j, k);
        // delect from end
        int b = v[j] - (k + v[i]) + solve(v, i, j-1, k);
        
        return min(a,b);
    }
    int minimumDeletions(string word, int k) {
        unordered_map<char,int>mp;
        for(auto it: word){
            mp[it]++;
        }
        vector<int>freq ;
        for(auto it: mp){
            freq.push_back(it.second);
        }
        sort(freq.begin(), freq.end());
        int n = freq.size();
        cout<<n<<endl;
        return solve(freq, 0, n-1, k);
    }
};
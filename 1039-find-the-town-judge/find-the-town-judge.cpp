class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>v(n+1,0);
        for(auto it: trust){
            v[it[0]]++;
            v[it[1]]--;
        }
        //  0 1 2 
        //    1 -1
        int neg = 0;
        for(int i = 1; i<=n;i++){
            if(-1 *v[i]== n-1)return i;
        }

         return -1;
        
    }
};
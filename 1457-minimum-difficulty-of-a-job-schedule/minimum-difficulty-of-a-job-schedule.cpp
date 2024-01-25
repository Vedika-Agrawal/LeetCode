// class Solution {

// public:
//     int solve(vector<int>&jd, int d, int currIdx, int mx){
//         if(currIdx==jd.size()){
//             if(d==0){
//                 return mx;
//             }
//             return INT_MAX;
//         }
//         int take =INT_MAX;
//         int notTake = INT_MAX;


//         // noTake currIdx diff grp ;
//         notTake =  mx + solve(jd, d-1, currIdx+1, jd[currIdx]);
        
//         //  take = = same grp continue;
//         take = solve(jd, d, currIdx+1, max(mx, jd[currIdx]));
//         return min(notTake, take);
//     }
//     int minDifficulty(vector<int>& jd, int d) {
//         int n = jd.size();
//         if(d>n)return -1;
//         return solve(jd,d,0, 0);
//     }
// };

class Solution {
public:
    int n;
    int dp[301][11][302];
    int solve(vector<int>& job,int idx,int mx,int d){
        if(d==0)return 1e9;
        if(idx>=n) return d==1 ? job[mx] : 1e9;
        
        if(dp[idx][d][mx]!=-1){
            return dp[idx][d][mx];
        }

        
        // 1. Either carry the current task in previous day
        int temp_idx = job[idx]> job[mx] ? idx : mx;
         int b=solve(job,idx+1,temp_idx,d);


        // 2. Finish the day and start current task in new day
        int a= job[mx] + solve(job,idx+1,idx,d-1);

       

        return dp[idx][d][mx] = min(a,b);
    }
    int minDifficulty(vector<int>& job, int d) {
        n=job.size();
        memset(dp,-1,sizeof(dp));
        if(d>n){
            return -1;
        }
        return solve(job,1,0,d);
    }
};
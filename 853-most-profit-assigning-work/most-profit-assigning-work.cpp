class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
        vector<vector<int>>v;  // { difficult, profit, max_profit till now};
        for(int i=0;i<profit.size();i++){
           v.push_back({difficulty[i], profit[i]});
        }

        sort(v.begin(),v.end());
        sort(worker.begin(), worker.end());

        int mx =0;
        for(int i=0;i<profit.size();i++){
           mx = max(mx, v[i][1]);
           v[i].push_back(mx);
        }
        
        
        int ans = 0;
        int j = 0;
        
        for(int i=0;i<worker.size();i++){
            
            int tmp = 0;
            while( j< profit.size() && v[j][0] <= worker[i]){
                // cout<<tmp<<" ";
                
                tmp = v[j][2];
                cout<<worker[i]<<" "<<v[j][0]<<" "<<tmp<<endl;
                j++;
            }
            if(j>0) j--;
            cout<<endl;
            ans += tmp;

        }
        return ans;

    }
};
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        vector<pair<int,int>>v;
        for(auto it : inter){
            int a = it[0];
            int b = it[1];
            v.push_back({a,b});
        }
        sort(v.begin(),v.end());
        vector<vector<int>>ans;
        
        int st =  v[0].first;
        int end = v[0].second;
        
        for(int i=1;i<v.size();i++){
            int a = v[i].first;
            int b = v[i].second;
            int flag = 0;
            if(end>=a){
                flag =1;
                end = max(end,b);
            }
            if(flag==0){

                ans.push_back({st,end});
                st = a,end =  b;

            }
            
        }
          
               
         ans.push_back({st,end});
        return ans;
    }
};
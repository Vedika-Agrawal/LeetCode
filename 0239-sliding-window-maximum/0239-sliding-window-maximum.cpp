class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int k) {
        vector<int>ans;
        priority_queue<pair<int,int>>q;
        for(int i=0;i<k;i++)q.push({v[i], i});
        ans.push_back(q.top().first);
        
        for(int i=k;i<v.size();i++){
            q.push({v[i], i}); // add curr ele to the q;
            
            while(!(q.top().second > i-k)){
                 cout<<q.top().second<<endl;
                 q.pop();
            }
               
            ans.push_back(q.top().first);
            
            
            
        }
        return ans;
    }
};
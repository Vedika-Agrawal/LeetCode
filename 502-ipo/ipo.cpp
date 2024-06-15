class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {
        int n = p.size();
        vector<pair<int,int>>project;
        for(int i=0;i<n;i++){
            project.push_back({c[i],p[i]});
        }
        sort(project.begin(),project.end());
        priority_queue<int>q;
        int ptr = 0;
        while(k--){
            while(ptr<n && project[ptr].first <=w){
                q.push(project[ptr].second);
                ptr++;
            }
            if(q.empty())break;
             w += q.top();
            q.pop();
        }
        return w;
    }
};

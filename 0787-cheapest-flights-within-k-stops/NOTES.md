int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
unordered_map<int,vector<pair<int,int>>> mp;
for(auto it: flights){
mp[it[0]].push_back({it[1],it[2]});
}
pq.push({0,{src,k}});
int ans=INT_MAX;
while(!pq.empty()){
auto p=pq.top();
pq.pop();
int dis=p.first;
int node=p.second.first;
int up_k=p.second.second;
if(node==dst){
ans=min(ans,dis);
}
if(up_k>=0){
for(auto it:mp[node]){
pq.push({it.second+dis,{it.first,up_k-1}});
}
}
}
if(ans==INT_MAX){
return -1;
}
return ans;
}
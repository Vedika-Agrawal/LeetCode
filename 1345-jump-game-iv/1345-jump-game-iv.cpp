class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n==1)return 0;
        vector<bool>check(n,false);
        unordered_map<int,vector<int>>mp;
        
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        queue<int>q;
        q.push(0);
        check[0]=true;
        int step = 0;
        while(q.size()){
            int sz = q.size();
            while(sz--){
                int curr = q.front(); q.pop();
                if(curr==n-1)return step;
                int left = curr-1;
                int right = curr+1;
                if(left>=0 && !check[left]){
                    q.push(left);
                    check[left]=true;
                }
                if(right<n && !check[right]){
                    q.push(right);
                    check[right]=true;
                }
                for(const int &idx : mp[arr[curr]]){
                    if(!check[idx]){
                        q.push(idx);
                        check[idx]=true;
                    }
                }
                mp.erase(arr[curr]);
            }
            step++;
        }
        return -1;
        
        
    }
};
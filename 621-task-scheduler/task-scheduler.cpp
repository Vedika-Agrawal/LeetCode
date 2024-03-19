class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int cnt = 0; int mx = 0;
        unordered_map<char,int>mp;
        for(auto it: tasks){
            mp[it]++;
            if(mp[it]>mx){
                cnt = 1;
                mx = mp[it];
            }
            else if(mp[it]==mx){
                cnt++;
            }
        }
        cout<<cnt<<" "<<mx;
        int a = (n+1) * (mx-1) + cnt;
        int b = tasks.size();
        return max(b, a);
        }
};
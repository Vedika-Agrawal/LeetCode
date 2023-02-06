#define ll long long 

class Solution {
public:
    long long minCost(vector<int>& v1, vector<int>& v2) {
        map<int,int>mp1,mp2;
        set<int>st;
        for(auto it : v1){
            mp1[it]++;
            st.insert(it);
        }
        for(auto it : v2){
                mp2[it]++;
                st.insert(it);
        }
        vector<int>diff1,diff2;
        
        int min_ele = *st.begin();
        
        for(auto it : st){
            int f1 = mp1[it];
            int f2 = mp2[it];
            if(f1==f2)continue;
            
            ll diff = abs(f1-f2);
            if(diff%2!=0)return -1;
            
            if(f1>f2){
                
                for(int i=0;i<diff/2;i++){
                    diff1.push_back(it);
                }
            }
            else{
                
                for(int i=0;i<diff/2;i++){
                    diff2.push_back(it);
                }
            }
        }
        
        if(diff1.size()!=diff2.size())return -1;
        
        reverse(diff2.begin(),diff2.end());
        
        int n = diff1.size();
        ll cost = 0;
        
        for(int i=0;i<n;i++){
            int temp = min(diff1[i],diff2[i]);
            cost += min(2*min_ele, temp );
            
        }
        return cost;
        
        
        
    }
};
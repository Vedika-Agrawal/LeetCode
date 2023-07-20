class Solution {
public:
    class robot{
        public : 
        int p;
        int h;
        char d;
        int idx;
    };
    
    static bool compare(robot &a, robot &b){
        return a.p < b.p;
    }
    
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& health, string dir) {
        int n = pos.size();
        vector<robot>v;
        for(int i=0;i<n;i++){
            v.push_back({pos[i], health[i],dir[i], i});
        }
        
        sort(v.begin(),v.end(),compare);
        
        // for(auto it: v){
        //     cout<<it.p<<" "<<it.h<<" "<<it.d<<" "<<it.idx;
        //     cout<<endl;
        // }
        
        
        stack<robot>st;
        
        for(auto it:v){
            if(it.d=='R'){
                st.push(it);
                continue;
            }
            bool flag =  false;
            
            while(st.size() && st.top().d=='R' && st.top().h<= it.h){
                if(st.top().h == it.h){
                    flag = true;
                    st.pop();
                    break;
                }
                it.h--;
                st.pop();
            }
            
            
            
            if(!flag && st.size() && st.top().h>it.h && st.top().d=='R' ){
                st.top().h --;
               
            }
            else if(!flag){
                st.push(it);
                 flag  = false;
            }
        }
        
        cout<<st.size()<<endl;
        
        vector<int>ans;
        vector<int>temp(n);
        while(st.size()){
            int x  = st.top().idx;
            int y = st.top().h;
            temp[x] = y;
            st.pop();
        }
        for(int i=0;i<n;i++){
            if(temp[i]!=0){
                ans.push_back(temp[i]);
            }
        }
        
        return ans;
        
    }
};
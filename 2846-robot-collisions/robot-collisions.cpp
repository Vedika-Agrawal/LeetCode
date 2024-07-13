class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();
        
        vector<pair<int,pair<int,pair<int,char>>>> arr;
        for(int i=0;i<n;i++){
            arr.push_back({positions[i],{i,{healths[i],directions[i]}}});
        }
        sort(arr.begin(),arr.end());
        stack<pair<int,pair<int,char>>> st;  //idx,health,dir
        for(int i=0;i<n;i++){
            int x=arr[i].second.first;
            int y=arr[i].second.second.first;
            char z=arr[i].second.second.second;
            st.push({x,{y,z}});
            while(st.size()>=2){
                auto p=st.top();
                st.pop();
                auto q=st.top();
                st.pop();
                if(q.second.second=='R'){
                    if(p.second.second=='L'){
                        if(p.second.first>q.second.first && p.second.first>1){
                            st.push({p.first,{p.second.first-1,p.second.second}});
                        }
                        else if(q.second.first>p.second.first && q.second.first>1){
                            st.push({q.first,{q.second.first-1,q.second.second}});
                        }
                        else if(q.second.first==p.second.first){
                            break;
                        }
                    }
                    else{
                        st.push(q);
                        st.push(p);
                        break;
                    }
                }
                else{
                    st.push(q);
                    st.push(p);
                    break;
                }
            }
        }
        int m=st.size();
        vector<int> temp(n);
        while(!st.empty()){
            auto p=st.top();
            st.pop();
            int x=p.first;
            int y=p.second.first;
            temp[x]=y;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(temp[i]!=0){
                ans.push_back(temp[i]);
            }
        }
        return ans;
    }
};
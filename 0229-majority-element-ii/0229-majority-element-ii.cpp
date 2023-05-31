class Solution {
public:
    vector<int> majorityElement(vector<int>& v) {
        int c1= 0, c2 =0, e1= -1, e2= -1;
        for(auto it: v){
            
            if(it==e1)c1++;
            else if(it==e2)c2++;
            else if(c1==0){
                e1 = it;
                c1++;
            }
            else if(c2==0){
                e2 = it;
                c2++;
            }
            else{
                c1--;
                c2--;
            }
        }
        
        c1= 0,c2=0;
        for(auto it: v){
            if(it==e1)c1++;
            else if(it==e2)c2++;
        }
        
        vector<int>ans;
        if(c1 > v.size()/3)ans.push_back(e1);
        if(c2 > v.size()/3)ans.push_back(e2);
        return ans;
        
    }
};
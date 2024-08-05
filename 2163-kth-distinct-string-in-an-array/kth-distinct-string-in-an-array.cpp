class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) 
    {
        map<string,int>map;
        for(auto it: arr) map[it]++;
        int cnt=0;
        for(auto it:arr){
        if(map[it]==1)
        {
            cnt++;
            if(cnt==k)
                return it;
        }
        }
        return "";
    }
};
class Solution {
public:
    bool asteroidsDestroyed(int sum, vector<int>& v) {
        sort(v.begin(),v.end());
        long long mass = sum ;
        for(auto it: v){
            if(mass-it < 0) return false;
            else mass+= it;
        }
        return true;
    }
};
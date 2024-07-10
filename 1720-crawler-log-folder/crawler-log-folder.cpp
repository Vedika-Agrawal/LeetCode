class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cnt  = 0 ;
        for(auto it: logs){
            if(it[0]!='.'){
                cnt++;
            }
            else if(it[0]=='.' && it[1]=='.' && cnt>0){
                cnt--;
            }
        }
        return cnt;
    }
};
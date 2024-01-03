class Solution {
public:
    int countOne(string &s){
        int one   =0;
        for(auto it: s) one += it=='1' ? 1 : 0;
        return one;
    }
    int numberOfBeams(vector<string>& bank) {
        int ans =0;
        int  n = bank.size();
        int  m = bank[0].size();
        int prev = 0;
        for(int i =0;i< n;i++){ 
            int one = countOne(bank[i]);
            if(i != 0 ){
                ans += one* prev;
            }
            if(one!= 0){
                prev = one;
            }
        }
        return ans;
    }
};
class Solution {
public:
    char nextGreatestLetter(vector<char>& let, char tar) {
        int l =0 , h = let.size()-1;
        char ans = '*';
        while(l<=h){
            int mid = (l+h)/2;
            if(let[mid]>tar){
                ans = let[mid];
                    h = mid-1;
            }
            else{
                l= mid+1;
            }
        }
        if(ans=='*')ans = let[0];
        return ans;
    }
};
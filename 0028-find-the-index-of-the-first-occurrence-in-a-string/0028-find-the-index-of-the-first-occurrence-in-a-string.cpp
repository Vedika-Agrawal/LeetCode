class Solution {
public:
    int strStr(string hay, string need) {
        if(need.size()>hay.size())return -1;
        int i=0;
        int idx = 0;
        for(int i=0;i<hay.size();i++){
            int  j =0 ;
            int k = i;
            while(j<need.size() && k<hay.size() && hay[k]==need[j])k++,j++;
            if(j==need.size()){
                return i;
            }
            else{
                j=0;
            }
        }
        return -1;
    }
};
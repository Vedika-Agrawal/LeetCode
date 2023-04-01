class Solution {
public:
    int search(vector<int>& v, int t) {
        int l=0,h=v.size()-1;
        while(l<=h){
            int mid = (l+h)/2;
            if(v[mid]==t)return mid;
            else if(v[mid]>t){
                h = mid-1;
            }else{
                l = mid+1;
            }
        }
        return -1;
    }
};
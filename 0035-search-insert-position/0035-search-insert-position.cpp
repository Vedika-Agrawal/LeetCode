class Solution {
public:
    int searchInsert(vector<int>& num, int x) {
         int i,low,mid,high;
        low=0;
        high=num.size()-1;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(num[mid]==x)
                return mid;
            if(x>num[mid])
                low=mid+1;
            else 
                high=mid-1;


        }
        return low;

    }
};
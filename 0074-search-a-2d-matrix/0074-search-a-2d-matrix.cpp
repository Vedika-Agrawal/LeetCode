class Solution {
public:
      bool searchMatrix(vector<vector<int>>& v, int target)
        {
            int m= v.size();//column;
            int n = v[0].size();//rows;
            int i=0, j=n-1;
            while(i<m && j>=0)
            {
                if(v[i][j]==target)
                {
                    return true;
                }
                 if(v[i][j]>target)
                 {
                     j--;
                 }
                else
                    i++;

            }
            return false;
        }
};
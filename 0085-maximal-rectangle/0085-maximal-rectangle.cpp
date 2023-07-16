class Solution {
public:
    int n;
    int largestRectangleArea(vector < int > & histo) {
    stack < int > st;
    int maxA = 0;
    int n = histo.size();
    for (int i = 0; i <= n; i++) {
        while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
            int height = histo[st.top()];
            st.pop();
            int width;
            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;
            maxA = max(maxA, width * height);
        }
        st.push(i);
    }
    return maxA;
}
    
    int maximalRectangle(vector<vector<char>>& mat) {
        int n= mat.size(), m = mat[0].size();
        int ans =0;
         vector<int>temp(m,0);
        for(int i=0;i<n;i++){
           
            for(int j=0;j<m;j++){
                if(mat[i][j]=='1')temp[j]++;
                else temp[j]=0;
            }
            ans = max(ans, largestRectangleArea(temp));
        }
        
        return ans;
    }
};
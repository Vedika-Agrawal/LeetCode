class Solution {
public:
    int n;
    void rightSmaller( vector<int>& ht,  vector<int>& right){
        stack<int>st;
        for(int i= ht.size()-1; i>=0 ; i--){
            int curr = ht[i];
            while(st.size() && ht[st.top()]>= curr){
                st.pop();
            }
            right[i] = st.size()==0 ? n : st.top();
            
            st.push(i);
        }
    }
    
    void leftSmaller( vector<int>& ht ,  vector<int>& left){
         stack<int>st;
        
        for(int i= 0; i<n ; i++){
            int curr = ht[i];
            while(st.size() && ht[st.top()]>= curr){
                st.pop();
            }
            left[i] = st.size()==0 ? -1 : st.top();
            
            st.push(i);
        }
    }
    
    // for(int i=0;i<n;i++)cout<<left[i]<<endl;
    
    int largestRectangleArea(vector<int>& ht) {
        int ans = INT_MIN;
        n = ht.size();
        vector<int>left(n), right(n);
        rightSmaller(ht,right);
        leftSmaller(ht,left);
        
        
        for(int i=0;i<n;i++){
//             int aaa = right[i]==n ? ht[i] : ht[right[i]];
//             int bbb = left[i]==-1 ? ht[i] : ht[left[i]];
//             int temp1 = (right[i]-i)* aaa;
            
//             int temp2 = (i - left[i]) * bbb;
           
//             ans = max({temp1,temp2,ans});
            
            int diff = right[i]-left[i]-1;
            int area = diff * ht[i];
            ans = max(ans,area);
        }
        return ans;
        
    }
};

















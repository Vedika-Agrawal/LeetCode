class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n));
        int dir  = 0;
        int top = 0, down = n-1;
        int left = 0, right = n-1;
        int val =1 ;
        
        while(top<=down && left<=right){
            if(dir==0){
               
                for(int i=left; i<=right;i++){
                    // tmp.push_back(m[top][i]);
                    ans[top][i]=val++;
                }
                top++;
                
         
            }
            else if(dir==1){
                
                for(int i=top;i<=down;i++){
                   // tmp.push_back(m[i][right]); 
                  ans[i][right]=val++;
                }
                 
                right--;
            }
            else if(dir==2){
               
                for(int i=right;i>=left;i--){
                   // tmp.push_back(m[down][i]); 
                    ans[down][i]=val++;
                }
                
                down--;
            }
            else if(dir==3){
                
                for(int i=down;i>=top;i--){
                   // tmp.push_back(m[i][left]); 
                    ans[i][left]=val++;
                }
                 
             left++;
            }
             dir = (dir+1)%4;
            
        }
        return ans;
        
    }
};
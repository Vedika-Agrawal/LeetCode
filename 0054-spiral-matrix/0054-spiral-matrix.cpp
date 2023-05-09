class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        int dir  = 0;
        int top = 0, down = m.size()-1;
        int left = 0, right = m[0].size()-1;
        vector<int>tmp;
        
        while(top<=down && left<=right){
            if(dir==0){
               
                for(int i=left; i<=right;i++){
                    tmp.push_back(m[top][i]);
                }
                top++;
                
         
            }
            else if(dir==1){
                
                for(int i=top;i<=down;i++){
                   tmp.push_back(m[i][right]); 
                }
                 
                right--;
            }
            else if(dir==2){
               
                for(int i=right;i>=left;i--){
                   tmp.push_back(m[down][i]); 
                }
                
                down--;
            }
            else if(dir==3){
                
                for(int i=down;i>=top;i--){
                   tmp.push_back(m[i][left]); 
                }
                 
             left++;
            }
             dir = (dir+1)%4;
            
        }
        return tmp;
        
    }
};
class Solution {
public:
   string addBinary(string a, string b) {
        int i = a.size()-1;
        int j = b.size()-1;
        int carry = 0;
        string ans = "";
        while(i>=0 && j >=0 ){
            // db3(a[i],b[j],carry);
            int add = (a[i]-'0')+(b[j]-'0')+carry;
            // db1(add);
            if(add==2){
                carry = 1;
                ans+='0';
            }
            else if(add==3){
                carry =1;
                ans+='1';
            }
            else if(add==1){
                carry = 0;
                ans+='1';
            }
            else
            {
                carry = 0;
                ans+='0';
            }
            i--;
            j--;
        }
        while(i>=0){
         int add = carry + (a[i] -'0');
             if(add==2){
                carry = 1;
                ans+='0';
            }
           else if(add==1){
                carry = 0;
                ans+='1';
            }
            else
            {
                carry = 0;
                ans+='0';
            }
            i--;
          
        }
       while(j>=0){
           
          int add = carry +( b[j]-'0');
             if(add==2){
                carry = 1;
                ans+='0';
            }
           else if(add==1){
                carry = 0;
                ans+='1';
            }
            else
            {
                carry = 0;
                ans+='0';
            }
           j--;
           
           
        }
       
       if(carry==1){
           char ch = '1';
           ans+=ch;
       }
        reverse(ans.begin(),ans.end());
        return ans;
        
        
    }
};
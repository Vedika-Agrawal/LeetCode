//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
        
        int n1 = s1.size(), n2 = s2.size();
        int arr[n1+n2] = {0};
        int a  = s1[0]=='-'? -1:0;
        int b  = s2[0]=='-'? -1:0;
        
        for(int i = n1-1;i>=0;i--){
            int k  = i + n2;
            if(s1[i]!='-'){
                int carry =0;
                for(int j= n2-1;j>=0;j--){
                    if(s2[j]!='-'){
                        int x  = (s1[i]-'0') * (s2[j]-'0') + carry + arr[k];
                        arr[k] = x%10;
                        carry = x/10;
                        k--;
                    }
                }
                
                if(carry>0){
                    arr[k] = carry;
                }
            }
        }
        string ans ="";
        bool flag  = true;
        for(int i = 0;i<n1+n2;i++){
            while(i<n1+n2 && arr[i]==0 && flag == true){
                i++;
            }
            flag = false;
            char ch  = arr[i]+'0';
            ans += ch;
        } 
        if(a<0 && b>=0 ||  a>=0 && b<0)return '-'+ans;
        return ans;
       
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends
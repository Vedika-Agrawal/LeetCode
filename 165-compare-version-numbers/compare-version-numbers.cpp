class Solution {
public:
    int compareVersion(string v1, string v2) {
        int n= v1.size(), m = v2.size();
        int num1=0,num2=0;
        int i=0,j=0;
        while(i<n || j <m)
        {
            while(i<n && v1[i]!='.')
            {
                num1 = num1*10 + (v1[i]-'0');
                i++;
            }
            while(j<m && v2[j]!='.')
            {
                num2 = num2*10 + (v2[j]-'0');
                j++;
            }
            if(num1>num2)
                return 1;
            else if(num2>num1)
                return -1;
            i++;
            j++;
            num1=0;
            num2=0;
        }
        return 0;
        
    }
};
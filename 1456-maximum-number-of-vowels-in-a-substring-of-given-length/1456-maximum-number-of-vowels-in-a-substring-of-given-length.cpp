class Solution {
public:
    bool isVowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k) {
        int ans =INT_MIN;
        int sum =0;
        // "abciiidef" 
        for(int i=0;i<k;i++){
            if(isVowel(s[i])==true){
            
                sum++;
            }
        }
        

        ans = max(ans,sum);
        // cout<<ans<<" ";
        for(int i=k;i<s.size();i++){
            // cout<<i<<" "<<s;
            if(isVowel(s[i-k])==true){
                cout<< "s[i-k]" <<endl;
                sum--;
            }
            if(isVowel(s[i])==true){
                //  cout<< "s[k]" <<" "<< s[k]<<endl;
                sum++;
            }
            ans = max(ans,sum);
        }
        return ans;
    }
};
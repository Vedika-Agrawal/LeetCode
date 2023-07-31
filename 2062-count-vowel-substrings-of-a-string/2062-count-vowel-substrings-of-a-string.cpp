class Solution {
public:
    
    bool isVowel(char ch){
        return ch=='a' || ch=='e' || ch=='i'|| ch=='o' || ch=='u';
    }
    
    int atMost(string word, int cnt){
        int i=0,j=0,ans =0,n=word.size();
        unordered_map<char,int>mp;
        
       for(;j<n;j++){
           if(!isVowel(word[j])){
               i =j+1;
               mp.clear();
               continue;
           }
           
           mp[word[j]]++;
           for(; i<j && mp.size()>cnt; i++){
               mp[word[i]]--;
               if(mp[word[i]]==0)mp.erase(word[i]);
           }
           ans += j-i+1;
           
       }
        return ans;
    }
    
    int countVowelSubstrings(string word) {
        return atMost(word,5)-atMost(word,4);
    }
};
class Solution {
public:
    string sortVowels(string s) {
        vector<int>v;
        for(auto it: s){
            if(it=='a' || it=='e' || it=='i' || it=='o'|| it=='u' ||it=='A' || it=='E' || it=='I' || it=='O'|| it=='U' ){
                v.push_back(it);
            }
            
        }
        sort(v.begin(),v.end());
        int j = 0;
        for(int i=0;i<s.size(); i++){
            char it = s[i];
            if(it=='a' || it=='e' || it=='i' || it=='o'|| it=='u' ||it=='A' || it=='E' || it=='I' || it=='O'|| it=='U' ){
                s[i] = v[j];
                j++;
            }
        }
        return s;
    }
};
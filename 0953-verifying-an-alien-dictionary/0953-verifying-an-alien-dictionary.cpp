class Solution {
public:
    // vector<pair<char,int>>v;
    unordered_map<char, int> v;

    bool solve(vector<string>& wrd){
        for(int k=0;k<wrd.size()-1;k++){
            string a =wrd[k];
            string b = wrd[k+1];
            // cout<<a<<" "<<b<<endl;
            int i=0, j=0;
            while(i<a.size() && j<b.size()){

                    int idxa = v[a[i]];
                    int idxb = v[b[j]];
                    if(a[i]!=b[j]){
                        if(idxa>idxb)return false;
                        break;
                    }
                    
                    i++; j++;
            }
            cout<<i<<" "<<j<<endl;
            if(b.size()==j && a.size()!=i){
                return false;
            }
        }
        return true;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        
        for(int i = 0; i < order.length(); i++){
            v[order[i]] = i;
        }
        
        return solve(words);
    }
};
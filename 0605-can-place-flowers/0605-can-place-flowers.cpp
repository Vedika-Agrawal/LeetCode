class Solution {
public:
    bool canPlaceFlowers(vector<int>& v, int n) {
        int sz = v.size();
        for(int i=0;i<v.size();i++){
            cout<<i<<endl;
            if(n==0)break;
            if(v[i]==0 && i==0 && i==sz-1){
                cout<<i<<endl;
                i++;
                n--;
            }
            else if(v[i]==0 && i==0 && i+1<sz && v[i+1]==0){
                cout<<i<<endl;
                i++;
                n--;
            }
            else if(v[i]==0 && i-1 >= 0 && i+1<sz && v[i+1]==0 && v[i-1]==0){
                cout<<i<<endl;
                i++;
                n--;
            }
            else if(v[i]==0 && i-1 >= 0 && i+1==sz  && v[i-1]==0){
                cout<<i<<endl;
                i++;
                n--;
            }
        }
        if(n==0)return true;
        return false;
    }
};
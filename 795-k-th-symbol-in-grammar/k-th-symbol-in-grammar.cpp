class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1)return 0;

        if(k%2==0){
            int no = kthGrammar(n-1, k/2);
            if(no==1)return 0;
            else return 1;
        }
        else{
            int no = kthGrammar(n-1, (k/2)+1);
            if(no==1)return 1;
            else return 0;
        }
    }
};
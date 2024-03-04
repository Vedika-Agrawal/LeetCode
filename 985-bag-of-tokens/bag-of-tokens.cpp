class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int i=0, j= tokens.size()-1;
        int score = 0;
        while(i<=j){
            //  cout<<power<<" "<<tokens[i]<<" "<<tokens[j]<<endl;
            if(power>=tokens[i]){
                power-=tokens[i];
                score++;
                i++;
            }
            else if(i!=j && score){
                power+= tokens[j];
                score--;
                j--;
            }
            else{
                return score;
            }
            
           
        }
        return score;

    }
};
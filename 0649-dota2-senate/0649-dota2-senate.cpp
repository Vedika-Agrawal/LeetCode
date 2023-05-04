class Solution {
public:
    string predictPartyVictory(string s) {
        queue<int>qr,qd;
        for(int i=0;i<s.size();i++){
            if(s[i]=='R')qr.push(i);
            else qd.push(i);
        }
        int n = s.size();
        
        while(qd.size()>0 && qr.size()>0){
            int r =qr.front(), d = qd.front();
            qr.pop(); qd.pop();
            r<d ? qr.push(n+r) : qd.push(n+d);
        }
        return (qr.size()>qd.size()) ? "Radiant" : "Dire";
    }
};
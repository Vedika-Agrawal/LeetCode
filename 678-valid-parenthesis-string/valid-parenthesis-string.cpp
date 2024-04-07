class Solution {
public:
    bool checkValidString(string s) {
        int cnt = 0;
        stack<int>st1, st2;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st1.push(i);
            }
            else if(s[i]=='*'){
                st2.push(i);
            }
            else{
                if(st1.size()==0 && st2.size()==0)return false;
                else if (st1.size())st1.pop();
                else st2.pop();
            }
        }
        while(st1.size() && st2.size()){
            if(st1.top()>=st2.top())return false;
            st1.pop();
            st2.pop();
        }
        return !st1.size();
    }
};
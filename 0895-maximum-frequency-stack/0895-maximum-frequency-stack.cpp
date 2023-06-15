class FreqStack {
public:
    
    map<int , stack<int>>st;
    map<int,int>mp;
    int maxfreq;
    
    FreqStack() {
        maxfreq = 0;
    }
    
    void push(int val) {
        mp[val]++;
        maxfreq = max(maxfreq , mp[val]);
        st[mp[val]].push(val);
    }
    
    int pop() {
        auto it = st[maxfreq].top();
        st[maxfreq].pop();
        if(st[maxfreq].size()==0){
            maxfreq--;
        }
        mp[it]--;
        return it;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
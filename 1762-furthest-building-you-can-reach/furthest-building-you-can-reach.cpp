class Solution {
public:
    int furthestBuilding(vector<int>& ht, int bricks, int ladders) {
        int i = 0, n = ht.size();
        priority_queue<int, vector<int>, greater<int>>pq;

        while(i<n){

            if(i>0 && ht[i]>ht[i-1]){
                pq.push(ht[i]-ht[i-1]);
                if(pq.size()>ladders){
                    int top= pq.top(); pq.pop();
                    if(bricks>=top)bricks-=top;
                    else break;
                }
            }
            i++;
        }
        return i-1;
    }
};
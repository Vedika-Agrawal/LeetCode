class MedianFinder {
public:
    priority_queue<int>mx;
    priority_queue<int, vector<int>, greater<int>>mn;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
         if(mx.size()==0){
            mx.push(num);
            return ;
        }
        if(mx.top()>=num){
            mx.push(num);
        }
        else{
            mn.push(num);
        }
        
        if(mx.size()-mn.size()==2){
            // mn.push(mx.top());
            // mx.pop();
            int x = mx.top();
            mn.push(x);
            mx.pop();
        }
        else if(mn.size()-mx.size()==2){
            // mx.push(mn.top());
            // mn.pop();
            int x = mn.top();
            mx.push(x);
            mn.pop();
        }
       
        
    }
    
    double findMedian() {
        // cout<<mn.top()<<" "<<mx.top()<<endl;
        if(mx.size()>mn.size())return mx.top();
        else  if(mn.size()>mx.size())return mn.top();
        else{
            double sum =(double) (mn.top() + mx.top())/2.0;
            return sum;
        }
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
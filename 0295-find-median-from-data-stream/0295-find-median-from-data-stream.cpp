class MedianFinder {
public:
    priority_queue<int>pq_max;
    priority_queue<int, vector<int>, greater<int>>pq_min;
    MedianFinder() {
        
    }
    
    // max heap // min heap =============
    void addNum(int num) {
        
        if(pq_max.size()==0){
            pq_max.push(num);
            return ;
        }
        
        if(num<=pq_max.top())
        {
            pq_max.push(num); 
             if(pq_max.size()-pq_min.size()>1){
                pq_min.push(pq_max.top());
                pq_max.pop();
            }
        }
        
        
        else {
             pq_min.push(num); 
              if(pq_min.size()-pq_max.size()>1){
                pq_max.push(pq_min.top());
                pq_min.pop();
            }
        
        }
            
        
       
        
       
        cout<<pq_max.top()<<endl;
        
    }
    
    double findMedian() {
        double temp;
        if(pq_max.size()>pq_min.size())return (double)pq_max.top();
        if(pq_min.size()>pq_max.size())return (double)pq_min.top();
        
        else{
             temp = (pq_max.top() + pq_min.top())/(double)2;
        }
        return temp;
        // return 0.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
class NestedIterator {
public:
    queue<int> que;
    NestedIterator(vector<NestedInteger> &nestedList) {
        addAll(nestedList);
    }
    
    void addAll(vector<NestedInteger>& nestedList) {
        int n = nestedList.size();
        for(int i = 0; i<n; i++) {
            NestedInteger& obj = nestedList[i];
            if(obj.isInteger())
                que.push(obj.getInteger());
            else {
                addAll(obj.getList());
            }
        }
    }
    
    int next() {
        int num = que.front();
        que.pop();
        return num;
    }
    
    bool hasNext() {
        return !que.empty();
    }
};


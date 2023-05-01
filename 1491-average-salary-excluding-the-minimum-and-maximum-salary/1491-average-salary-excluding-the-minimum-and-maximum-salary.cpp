class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(),salary.end());
        int n = salary.size();
        int sum =  accumulate(salary.begin(),salary.end(),0);
        cout<<sum<<" ";
        sum -=salary[0];
        sum -=salary[n-1];
        // cout<<sum<<endl;
        n-=2;
        double ans =(double) sum/n;
        return ans;
    }
};
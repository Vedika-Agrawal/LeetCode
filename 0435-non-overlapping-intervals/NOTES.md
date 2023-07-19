static bool compare(vector<int>&a,vector<int>&b){
if(a[0]==b[0]){
return a[1]<b[1];
}
return a[0]<b[0];
}
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
int n=intervals.size();
sort(intervals.begin(),intervals.end(),compare);
for(auto it:intervals){
cout<<it[0]<<" "<<it[1]<<endl;
}
return 0;
}
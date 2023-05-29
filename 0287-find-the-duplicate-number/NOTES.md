1. For loop.
2. Map
3. Optimal Soution :--
Binary search : ----
or
turoise method
(cycle in linked list.).
class Solution {
public:
int findDuplicate(vector<int>& v) {
int l = 1, h= v.size()-1;
while(l<=h){
int mid = l + (h-l)/2;
int cnt =0;
for(auto it: v){
if(it<=mid){
cnt++;
}
}
if(cnt<=mid){
l = mid+1;
}
else{
h = mid-1;
}
}
return l;
}
};
​
class Solution {
public:
int singleNonDuplicate(vector<int>&v) {
int n = v.size();
int l=0, h= n-1, mid;
while(l<h)
{
int mid = (l+(h-l)/2);
if((mid%2==0 && v[mid]==v[mid+1] ) || (mid%2!=0  && v[mid]== v[mid-1]))
{
l = mid +1;
}
else
h = mid;
}
return v[l];
}
};
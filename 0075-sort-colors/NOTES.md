1. sorting
2. frequency cnt
3. Binary search
Note : comparision ma pivot ayega low nhi.
void sortColors(vector<int>& v) {
int low =0, high = v.size()-1, pivot = 0;
while(pivot<=high){
if(v[pivot]==0){
swap(v[low],v[pivot]);
low++;
pivot++;
}
else if (v[pivot]==1){
pivot++;
}
else{
swap(v[pivot],v[high]);
high--;
}
}
}
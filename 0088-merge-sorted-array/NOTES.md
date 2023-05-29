Start from last index ie. put the larget ele at their right position first.
ie. o(n+m) constant space;
​
class Solution {
public:
void merge(vector<int>& n1, int m, vector<int>& n2, int n) {
int idx = n+m-1;
int i =m-1;
int j =n-1;
while(i>=0 && j>=0){
if(n2[j]>n1[i]){
n1[idx]=n2[j];
j--;
}
else{
n1[idx]=n1[i];
i--;
}
idx--;
}
while(i>=0){
n1[idx]=n1[i];
i--;
idx--;
}
while(j>=0){
n1[idx]=n2[j];
j--;
idx--;
}
}
};
​
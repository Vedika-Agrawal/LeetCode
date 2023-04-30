class Solution {
public:
vector<int>  parent1, size1, parent2, size2;
int remove = 0;
int findUPar1(int node) {
if (node == parent1[node])
return node;
return parent1[node] = findUPar1(parent1[node]);
}
int findUPar2(int node) {
if (node == parent2[node])
return node;
return parent2[node] = findUPar2(parent2[node]);
}
void unionBySize1(int u, int v) {
int ulp_u = findUPar1(u);
int ulp_v = findUPar1(v);
if (ulp_u == ulp_v)
{
remove++;
return;
}
if (size1[ulp_u] < size1[ulp_v]) {
parent1[ulp_u] = ulp_v;
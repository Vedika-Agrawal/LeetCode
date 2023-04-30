}
}
void unionBySize2(int u, int v) {
int ulp_u = findUPar2(u);
int ulp_v = findUPar2(v);
{
remove++;
return;
}
if (size2[ulp_u] < size2[ulp_v]) {
parent2[ulp_u] = ulp_v;
size2[ulp_v] += size2[ulp_u];
}
else {
parent2[ulp_v] = ulp_u;
size2[ulp_u] += size2[ulp_v];
}
}
int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
parent1.resize(n + 1);
size1.resize(n + 1);
for (int i = 0; i <= n; i++) {
parent1[i] = i;
size1[i] = 1;
}
parent2.resize(n + 1);
size2.resize(n + 1);
for (int i = 0; i <= n; i++) {
parent2[i] = i;
size2[i] = 1;
}
for(auto it : edges){
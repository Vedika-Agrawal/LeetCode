void rotate(vector<vector<int>>& arr) {
int n = arr.size();
for (int i = 0; i < n; i++)
for (int j = 0; j < i; j++)
swap(arr[i][j], arr[j][i]);
for (int i = 0; i < n; i++)
for (int j = 0; j < n / 2; j++)
swap(arr[i][j], arr[i][n - 1 - j]);
​
}
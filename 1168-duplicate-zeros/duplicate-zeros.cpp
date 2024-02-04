class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int numOfZeros = count(arr.begin(), arr.end(), 0);

        int i = n - 1;
        int j = n + numOfZeros - 1;

        while (i >= 0 && j >= 0) {
            if (arr[i] == 0) {
                if (j < n) {
                    arr[j] = 0;
                }
                j--;
            }

            if (j < n) {
                arr[j] = arr[i];
            }

            i--;
            j--;
        }
    }
};

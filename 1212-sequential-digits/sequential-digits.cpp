class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int> ans;
        string a = to_string(low);
        int l = a.size();
        string b = to_string(high);
        int r = b.size();
        for (int k = l; k <= r; k++) {
            // check for k size window;
            for (int i = 0; i <= 9 - k; i++) {
                string temp = s.substr(i, k);
                cout << temp << endl;
                int check_no = stoi(temp);
                if (check_no >= low && check_no <= high)
                    ans.push_back(check_no);
               
            }
        }
        return ans;
    }
};

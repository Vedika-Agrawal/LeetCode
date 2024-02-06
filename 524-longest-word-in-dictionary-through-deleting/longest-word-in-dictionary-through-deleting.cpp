class Solution {
public:
    static bool compareStrings(const std::string& a, const std::string& b) {
        if (a.length() == b.length()) {
            return a < b; // If lengths are equal, sort lexicographically
        }
        return a.length() > b.length(); // Otherwise, sort based on length
    }
    bool isPresent(string s, string t){
        int i= s.size()-1, j=t.size()-1;
        // search s in t
        while(i>=0 &&j>=0){
            if(s[i]==t[j]) i--;
            j--;

        }
        if(i<0)return true;
        return false;

    }
    string findLongestWord(string s, vector<string>& dic) {
        sort(dic.begin(), dic.end(), compareStrings);
        for (auto it : dic) {
            cout<<it<<endl;
            if (isPresent(it, s)) return it;
        }
        return "";
    }
};
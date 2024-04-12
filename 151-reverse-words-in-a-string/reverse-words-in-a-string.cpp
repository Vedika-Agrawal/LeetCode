class Solution {
public:
    string reverseWords(string s) {
    reverse(s.begin(), s.end());
    
    stringstream ss(s);
    string word, result;
    bool firstWord = true;
    
    while (ss >> word) {
        reverse(word.begin(), word.end());
        
        if (!firstWord) {
            result += " ";
        } else {
            firstWord = false;
        }
        result += word;
    }
    
    return result;
}
};
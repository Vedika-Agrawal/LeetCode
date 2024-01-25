class Solution {
public:
    bool isPossibleToTake(vector<int>&currAnsCharFreq, string curr){
        set<char>st(curr.begin(),curr.end());
        if(st.size()!=curr.size())return false;
        for(auto it: curr){
           if( currAnsCharFreq[it-'a']!=0)return false;
        }
        return true;
    }

    int solve(vector<string>&arr, int currIdx, vector<int>&currAnsCharFreq){
        if(currIdx >= arr.size())return 0;
        int notTake = solve(arr, currIdx+1, currAnsCharFreq);
        int take = 0;
        if(isPossibleToTake(currAnsCharFreq, arr[currIdx])){
            for(auto it: arr[currIdx]){
                currAnsCharFreq[it-'a']++;
            }
            take = arr[currIdx].size() + solve(arr, currIdx+1, currAnsCharFreq);
            for(auto it: arr[currIdx]){
                currAnsCharFreq[it-'a']--;
            }
        }
        return max(take, notTake);
    }
    int maxLength(vector<string>& arr) {
        vector<int>currAnsCharfreq(26, 0);
        return solve(arr, 0, currAnsCharfreq);
    }
};
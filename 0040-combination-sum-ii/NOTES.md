class Solution {
private:
void combinationSum2(vector<int>& candidates, int target, vector<vector<int>> &output, vector<int> &temp, int index){
if(index == candidates.size()){
if(target == 0){
bool isPresent = find(output.begin(), output.end(), temp) != output.end();
if(!isPresent){
output.push_back(temp);
}
}
return;
}
if(candidates[index] <= target){
temp.push_back(candidates[index]);
combinationSum2(candidates, target-candidates[index], output, temp, index+1);
temp.pop_back();
}
combinationSum2(candidates, target, output, temp, index+1);
}
public:
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
sort(candidates.begin(), candidates.end());
vector<vector<int>> output;
vector<int> temp;
combinationSum2(candidates, target, output, temp, 0);
return output;
}
};
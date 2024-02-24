class Solution {
public:
    void dfs(int i, int time, unordered_map<int, vector<pair<int,int>>>& graph, vector<int>& visitedAt) {
        for (auto neigh : graph[i]) {
            if (time <= neigh.second && neigh.second < visitedAt[neigh.first]) {
                visitedAt[neigh.first] = neigh.second;
                dfs(neigh.first, neigh.second, graph, visitedAt);
            }
        }
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        unordered_map<int, vector<pair<int,int>>> graph;
        for (int i = 0; i < n; ++i)
            graph[i] = vector<pair<int,int>>();

        for (auto meet : meetings) {
            graph[meet[0]].push_back({meet[1], meet[2]});
            graph[meet[1]].push_back({meet[0], meet[2]});
        }

        vector<int> ans;
        vector<int> visitedAt(n, INT_MAX);
        visitedAt[0] = 0;
        visitedAt[firstPerson] = 0;
        dfs(firstPerson, 0, graph, visitedAt);
        dfs(0, 0, graph, visitedAt);
        for (int i = 0; i < n; ++i) {
            if (visitedAt[i] != INT_MAX)
                ans.push_back(i);
        }
        return ans;
    }
};
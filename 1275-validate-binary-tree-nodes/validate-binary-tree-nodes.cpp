class Solution {
public:
    vector<int> parent;
    int components;

    int find(int x) {
        if(parent[x] == x)
            return x;
        
        return parent[x] = find(parent[x]);
    }

    bool Union(int par, int child) {
        int child_ka_parent  = find(child);
    
        //child_ka_parent != child --> Child had already some other parent
        if(child_ka_parent != child)
            return false;
        
        int parent_ka_parent = find(par);
        //parent_ka_parent == child_ka_parent ---> Parallel edge (It means, already they were connected by another edge)
        if (parent_ka_parent == child_ka_parent) {
            return false;
        }
        
        parent[child] = par;
        components--;
        return true;
    }
    
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        components = n;
        parent.resize(n);
        for(int i = 0; i<n; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < n; i++) {
            if (leftChild[i] >= 0 && !Union(i, leftChild[i])) {
                return false;
            }
            if (rightChild[i] >= 0 && !Union(i, rightChild[i])) {
                return false;
            }
        }
        
        return components == 1;
    }
};

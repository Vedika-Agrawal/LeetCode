class Solution {
public:
    vector<char>geneAlpha ={'A','C','G','T'};
    
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        set<string> st(bank.begin(),bank.end());
        set<string>vis;
        // {string, level};
        queue<pair<string,int>>q;
        vis.insert(startGene);
        q.push({startGene,0});
        while(q.size()){
            string temp = q.front().first;
            int level = q.front().second;
            q.pop();
            if(temp==endGene)return level;

            for(int i=0;i<temp.size();i++){
                char orignal = temp[i];
                for(int ch = 0;ch<4;ch++){
                    temp[i] = geneAlpha[ch];
                    if(vis.count(temp)!=0)continue;
                    if(st.count(temp)!=0){
                        q.push({temp,level+1});
                        vis.insert(temp);
                    }
                }
                temp[i] = orignal;
            }
        }
        return -1;
    }
};


// startGene = "AACCGGTT", endGene = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
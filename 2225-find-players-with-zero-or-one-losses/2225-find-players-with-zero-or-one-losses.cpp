class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
       map<int, int> mapp;
        
        for (vector<int> match : matches) {
            mapp[match[1]]++;
            if (mapp.count(match[0]) == 0) {
                mapp[match[0]] = 0;
            }
        }
        
        vector<vector<int>> res = {{}, {}};
        
        for (auto it = mapp.begin(); it != mapp.end(); it++) {
            if (it->second == 0) {
                res[0].push_back(it->first);
            } else if (it->second == 1) {
                res[1].push_back(it->first);
            }
        }
        return res;
    }
};
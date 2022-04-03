class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>>ans(2);
        map<int,int>winners;
        map<int,int>loosers;
        
        for(int i = 0 ; i < matches.size();i++){
            winners[matches[i][0]]++;
            loosers[matches[i][1]]++;
        }
        
        for(auto it = winners.begin(); it != winners.end(); it++){
            if(loosers.find(it->first) == loosers.end())
                ans[0].push_back(it->first);
        }
        
        for(auto it = loosers.begin(); it != loosers.end(); it++){
            if(it->second == 1)
                ans[1].push_back(it->first);
        }
        return ans;
        
    }
};
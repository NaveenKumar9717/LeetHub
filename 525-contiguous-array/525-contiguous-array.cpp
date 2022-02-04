class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0;
        unordered_map<int,int>mp{{0, -1}};
        int maxlength = 0;
        for(int i = 0 ;i <nums.size();i++){
            sum += (nums[i]) ? 1 :-1;
            if(mp.find(sum) != mp.end())
                maxlength = max(maxlength,i- mp[sum]);
            else
                mp[sum] = i;
        }
    return maxlength;
    }
    
};
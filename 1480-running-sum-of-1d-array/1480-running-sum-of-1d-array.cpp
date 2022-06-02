class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> runningsum;
        int sum = 0;
        for(int i = 0 ; i < nums.size();i++)
        {
            sum += nums[i];
            runningsum.push_back(sum);
        }
        return runningsum;
    }
};
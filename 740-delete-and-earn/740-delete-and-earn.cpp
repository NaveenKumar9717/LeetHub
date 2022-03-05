class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        int freq[n];
        int dp[n] ;
        for(int i = 0 ;i <10001;i++)
        {
            dp[i] =  0;
            freq[i]  = 0;
        }
         for(int i = 0 ;i < nums.size();i++)
             freq[nums[i]] += nums[i];
        
        dp[0] = 0 ;
        dp[1] = freq[1];
        for(int i =2;i < n;i++)
        {
            dp[i] = max(dp[i-2] + freq[i], dp[i-1]);
        }
        return dp[n-1];
    }
};
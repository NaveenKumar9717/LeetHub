class Solution {
public:
    int jump(vector<int>& nums) {
     int n  = nums.size();
     int dp[nums.size()];
        
     dp[n-1] = 0;
     for(int i = n-2;i>=0;i--){
         if((nums[i] + i) >= (n-1))
         {   dp[i] = 1; 
         }
         else if(nums[i] == 0){
             dp[i] = 100000;
         }
         else{
           dp[i] = n-1;
           for(int k = nums[i] ;k >=1;k--){
               dp[i]  = min(dp[i],1 + dp[i+k]);
           }  
             
         }
     }
     return dp[0];    
    }
};
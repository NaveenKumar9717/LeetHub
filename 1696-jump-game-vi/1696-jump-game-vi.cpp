vector<int>dp(100005);  
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        //Thnaks @nidhi_ranjan i did not get this approach got stuck till N*k
        int n = nums.size();  
        dp[n-1]=nums[n-1];
        priority_queue<pair<int,int>> maxheap; 
        maxheap.push({nums[n-1],n-1});
        for(int i = n-2; i>=0; i--){
           while(maxheap.top().second > (i+k))
               maxheap.pop();
           dp[i] = maxheap.top().first + nums[i];
           maxheap.push({dp[i],i}); 
            
        }
         return dp[0];

    }
};
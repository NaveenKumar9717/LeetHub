class Solution {
public:
    int numSquares(int n) {
        int dp[n+1];
        dp[0] = 0;
        dp[1] = 1;
        
        for(int i = 2;i <=n;i++){
            int curr = i;
          for(int j = 1;j*j <= i; j++){
              curr = min(curr,dp[i-j*j] + 1);
          }
           dp[i] = curr; 
        }
        return dp[n];
    }
};
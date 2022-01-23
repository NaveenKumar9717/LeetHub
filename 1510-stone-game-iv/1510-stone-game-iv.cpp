class Solution {
public:
    bool winnerSquareGame(int n) {
      int dp[n+1];
      for(int i = 0 ;i <=n;i++){
          dp[i] = 0 ;
      }
        
      for(int i = 1; i <= n;i++){
          for(int j =1;j*j <= i;j++){
              if(dp[i - j*j] == 0){
                  dp[i] = true ;
                  break;
              }
          }
      }
        return dp[n];
    }
};
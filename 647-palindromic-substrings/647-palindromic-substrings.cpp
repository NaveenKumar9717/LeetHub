class Solution {
public:
    int countSubstrings(string s) {
        int len = s.length();
        bool dp[len+1][len+1];
        memset(dp,0,sizeof(dp));
        int num_str = 0 ;
        for(int i = 0 ; i < len; i++){
            dp[i][i] = true;
            num_str++;
        }
        
        for(int i = 0 ; i < len-1; i++){
           if(s[i] == s[i+1]){
             dp[i][i+1] = true;
             num_str++;    
           }
        }
        
        for(int l = 2; l < len; l++ ){
          for(int i = 0 ; (i+l) < len;i++){
              if(s[i] == s[i+l] && dp[i+1][i+l-1])
              {
                  dp[i][i+l] = true;
                  num_str++;
              }
          } 
        }
        
        return num_str;
    
    }
};